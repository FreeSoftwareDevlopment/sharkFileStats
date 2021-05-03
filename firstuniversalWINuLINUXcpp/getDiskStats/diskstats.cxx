#include "diskstats.h"
shark::int64 disks::freeDiskSpace(char* drivename) {
	shark::int64 val{ -1 };
#if !defined(linux)&&defined(windows)
	if (GetDiskFreeSpaceExA(drivename, (PULARGE_INTEGER)&val, NULL, NULL) == FALSE) {
		val = -1;
	}
#else
	struct statvfs sfs;
	statvfs(drivename, &sfs);
	val = (shark::int64)(sfs.f_bsize * sfs.f_bfree);
#endif
	return val;
}