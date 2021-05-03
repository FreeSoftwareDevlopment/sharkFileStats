#pragma once
#include "../global.h"

#pragma comment(lib, "user32.lib")

#ifdef linux
#include <sys/statvfs.h>
#else
#ifdef  windows
#include <Windows.h>
#else
#error Diskstats: OS not Supported!
#endif
#endif

namespace disks {
	shark::int64 freeDiskSpace(char* drivename);
}