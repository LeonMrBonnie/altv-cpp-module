#include "../cpp-module.h"
#include "Core.h"

void Core::Log(char* message)
{
    alt::ICore::Instance().LogColored(message);
}