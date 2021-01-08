#pragma once
#include "cpp-module.h"
#include "./sdk/Core.h"

class CppRuntime : public alt::IScriptRuntime
{
    Core* sdk;

public:
    CppRuntime();
    alt::IResource::Impl* CreateImpl(alt::IResource* resource) override;
    void DestroyImpl(alt::IResource::Impl* impl) override;

    Core* GetSDK()
    {
        return sdk;
    }

    static CppRuntime& Instance()
	{
		static CppRuntime _instance;
		return _instance;
	}
};