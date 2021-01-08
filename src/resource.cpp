#include "resource.h"

#ifndef IS_UNIX
#include "windows.h"
#define _getlib(name) LoadLibraryA(name)
#define _getfunc(module, name, type) (type)GetProcAddress(module, name);
#define _seperator "/"
#else
#include <dlfcn.h>
#define _getlib(name) dlopen(name, RTLD_NOW);
#define _getfunc(module, name, type) (type)dlsym(module, name);
#define _seperator "\\"
#endif

CppResource::CppResource(CppRuntime* runtime, alt::IResource* resource)
: runtime(runtime),
  resource(resource)
{
    main.append(resource->GetPath().CStr());
    main.append(_seperator);
    main.append(resource->GetMain().CStr());
}

bool CppResource::Start()
{
    auto module = _getlib(main.c_str());
    if(module == NULL)
    {
        Log::Error << "Failed to open main file" << Log::Endl;
        return false;
    }

    auto main = _getfunc(module, "Start", MainFunction);
    if(main == NULL)
    {
        Log::Error << "Main entrypoint not found" << Log::Endl;
        return false; 
    }
    mainFunc = main;

    auto stop = _getfunc(module, "Stop", StopFunction);
    stopFunc = stop;

    auto event = _getfunc(module, "OnEvent", EventFunction);
    eventFunc = event;

    mainFunc(&alt::ICore::Instance());

    return true;
}

bool CppResource::Stop()
{
    if(stopFunc != NULL) stopFunc();
    return true;
}

bool CppResource::OnEvent(const alt::CEvent* ev)
{
    if(eventFunc == NULL) return true;
    else return eventFunc(ev);
}