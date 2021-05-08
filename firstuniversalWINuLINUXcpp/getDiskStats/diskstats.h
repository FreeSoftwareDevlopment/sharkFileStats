#pragma once
#include "../global.h"

#include <tuple>

#ifdef linux
#include <sys/statvfs.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#else
#ifdef  windows
#include <Windows.h>
#include <Shlwapi.h>
#include <sysinfoapi.h>
#pragma comment(lib, "Shlwapi.lib")
#pragma comment(lib, "User32.lib")
#else
#error Diskstats: OS not Supported!
#endif
#endif

#define dfolder 0b0001
#define dfile 0b0010
#define dnothing 0b0000
#define derr 0b0000

namespace disks {
	shark::int64 freeDiskSpace(char* drivename);
	shark::BOOL fileExists(char* filename);
	shark::uminiint isPathFolder(char* filename);
}

namespace mem {
	std::tuple<shark::int64, shark::int64, shark::BOOL> getMemPhys();
}