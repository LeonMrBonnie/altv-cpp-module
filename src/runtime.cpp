#include "runtime.h"

CppRuntime::CppRuntime()
{

}

alt::IResource::Impl* CppRuntime::CreateImpl(alt::IResource* impl)
{
    auto resource = new CppResource(this, impl);
    return resource;
}

void CppRuntime::DestroyImpl(alt::IResource::Impl* impl)
{
    CppResource* resource = dynamic_cast<CppResource*>(impl);
    if(resource != nullptr) delete resource;
}