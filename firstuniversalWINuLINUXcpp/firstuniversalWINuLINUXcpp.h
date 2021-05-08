#pragma once 
#include <iostream>
#include "global.h"
#include <tuple>
#include "getDiskStats/diskstats.h"

#ifdef linux
//LINUX HEADERS
#else
#ifdef  windows
//WIN HEADERS
#else
#error Main: OS not Supported!
#endif
#endif