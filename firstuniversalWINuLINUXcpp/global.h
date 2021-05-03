#pragma once
#ifndef globalsharkx
#define globalsharkx 0x0
#include "osspec.h"
#include <string.h>
#ifdef linux
//GLOBAL LINUX HEADERS
#include <stddef.h>
#else
#ifdef  windows
//GLOBAL WIN HEADERS
#else
#error OS not Supported!
#endif
#endif

namespace shark {
	typedef unsigned char BOOL;
	typedef long long int64;
	typedef unsigned char uminiint;
}
#endif