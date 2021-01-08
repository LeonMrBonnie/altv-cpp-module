#include "cpp-module.h"

EXPORT bool altMain(alt::ICore* core)
{
    alt::ICore::SetInstance(core);
    auto& runtime = CppRuntime::Instance();
    core->RegisterScriptRuntime("c++", &runtime);
    Log::Colored << "Loaded C++ module. Version ~y~v" CPP_MODULE_VERSION << Log::Endl;

    return true;
}

EXPORT uint32_t GetSDKVersion()
{
	return alt::ICore::SDK_VERSION;
}