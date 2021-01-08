#pragma once
#include "module-sdk/Core.h"

class Core : public SDK::ICore
{
public:
    Core() {};
    void Log(char* message) override;
};
