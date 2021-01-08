#include "runtime.h"

CppRuntime::CppRuntime()
{
    sdk = new Core();
}

alt::IResource::Impl* CppRuntime::CreateImpl(alt::IResource* impl)
{
    auto resource = new CppResource(this, impl);
    //resources.emplace(&resource);
    return resource;
}

void CppRuntime::DestroyImpl(alt::IResource::Impl* impl)
{
    CppResource* resource = dynamic_cast<CppResource*>(impl);
    if(resource != nullptr) 
    {
        //resources.erase(resource);
        delete resource;
    }
}