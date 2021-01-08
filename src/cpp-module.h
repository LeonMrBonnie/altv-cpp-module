#pragma once

#define CPP_MODULE_VERSION "0.0.1"

#if defined(unix) || defined(__unix__) || defined(__unix)
#define IS_UNIX
#endif

// SDK
#include "alt-sdk/SDK.h"
#include "Log.h"
#include "module-sdk/Main.h"

// Module
#include "runtime.h"
#include "resource.h"