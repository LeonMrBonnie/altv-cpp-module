#pragma once
#include "cpp-module.h"

class CppRuntime;
class CppResource : public alt::IResource::Impl
{
public:
    CppResource(CppRuntime* runtime, alt::IResource* resource);
    ~CppResource();

    bool Start()
    {
        return true;
    }
    bool Stop()
    {
        return true;
    }

    bool OnEvent(const alt::CEvent *ev)
    {
        return true;
    }
    void OnTick()
    {

    }

    void OnCreateBaseObject(alt::IBaseObject* object)
    {

    }
    void OnRemoveBaseObject(alt::IBaseObject* object)
    {

    }
};