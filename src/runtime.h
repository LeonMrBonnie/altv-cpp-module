#pragma once
#include "cpp-module.h"

class CppRuntime : public alt::IScriptRuntime
{
public:
    CppRuntime() {};
    alt::IResource::Impl* CreateImpl(alt::IResource* resource) override;
    void DestroyImpl(alt::IResource::Impl* impl) override;

    static CppRuntime& Instance()
	{
		static CppRuntime _instance;
		return _instance;
	}
};