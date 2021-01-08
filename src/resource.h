#pragma once
#include "cpp-module.h"

class CppRuntime;
class CppResource : public alt::IResource::Impl
{   
    using MainFunction = void (*)(alt::ICore* core);
    using StopFunction = void (*)();
    using EventFunction = bool (*)(const alt::CEvent* ev);

    CppRuntime* runtime;
    alt::IResource* resource;
    std::string main;

    MainFunction mainFunc;
    StopFunction stopFunc;
    EventFunction eventFunc;

public:
    CppResource(CppRuntime* runtime, alt::IResource* resource);
    ~CppResource() = default;

    bool Start();
    bool Stop();

    bool OnEvent(const alt::CEvent* event);
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