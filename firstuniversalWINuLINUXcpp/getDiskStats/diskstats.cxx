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

shark::BOOL disks::fileExists(char* filename) {
#if !defined(linux)&&defined(windows)
	return PathFileExistsA(filename);
#else
	struct stat buffer;
	return (stat(filename, &buffer) == 0);
#endif
}

shark::uminiint disks::isPathFolder(char* filename) {
	shark::uminiint ret = dnothing;
#if !defined(linux)&&defined(windows)
	DWORD x = GetFileAttributesA(filename);
	if (x && FILE_ATTRIBUTE_DIRECTORY) {
		ret |= dfolder;
	}
	else {
		ret |= dfile;
	}
#else
	struct stat st;
	if (stat(filename, &st) == 0) {
		if (st.st_mode & S_IFDIR)
		{
			ret |= dfolder;
		}
		else if (st.st_mode & S_IFREG)
		{
			ret |= dfile;
		}
		else {
			ret |= derr;
		}
	}
	else {
		ret |= derr;
	}
#endif
	return ret;
}