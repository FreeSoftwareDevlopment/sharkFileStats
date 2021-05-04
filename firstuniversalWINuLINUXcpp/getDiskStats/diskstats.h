#pragma once
#include "../global.h"

#pragma comment(lib, "user32.lib")

#ifdef linux
#include <sys/statvfs.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#else
#ifdef  windows
#include <Windows.h>
#include <Shlwapi.h>
#pragma comment(lib, "Shlwapi.lib")
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