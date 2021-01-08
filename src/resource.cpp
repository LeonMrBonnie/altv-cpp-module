#include "resource.h"
#ifndef IS_UNIX
#include "windows.h"
#endif

CppResource::CppResource(CppRuntime* runtime, alt::IResource* resource)
: runtime(runtime),
  resource(resource)
{
    main.append(resource->GetPath().CStr());
    #ifdef IS_UNIX
    main.append("\\")
    #else
    main.append("/");
    #endif
    main.append(resource->GetMain().CStr());
}

bool CppResource::Start()
{
    #ifdef IS_UNIX
    //void* module = dlopen(main.c_str());
    #else
    HMODULE module = LoadLibraryA(main.c_str());
    if(module == NULL)
    {
        Log::Error << "Failed to open main file" << Log::Endl;
        return false;
    }

    auto main = (MainFunction)GetProcAddress(module, "Main");
    if(main == NULL)
    {
        Log::Error << "Main entrypoint not found" << Log::Endl;
        return false; 
    }
    mainFunc = main;

    auto stop = (StopFunction)GetProcAddress(module, "Stop");
    if(stopFunc != NULL) stopFunc = stop;

    auto event = (EventFunction)GetProcAddress(module, "OnEvent");
    if(eventFunc != NULL) eventFunc = event;
    #endif

    mainFunc(&alt::ICore::Instance());

    return true;
}

bool CppResource::Stop()
{
    if(stopFunc) stopFunc();
    return true;
}

bool CppResource::OnEvent(const alt::CEvent* event)
{
    if(!eventFunc) return true;
    else return eventFunc(event);
}