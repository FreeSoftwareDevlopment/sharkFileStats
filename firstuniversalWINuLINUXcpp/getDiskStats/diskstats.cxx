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

//MEMSTATS
std::tuple<shark::int64, shark::int64, shark::BOOL> mem::getMemPhys() {
	//0 fremmem; 1 mem; 2 ok
	std::tuple<shark::int64, shark::int64, shark::BOOL> t;
#if !defined(linux)&&defined(windows)
	MEMORYSTATUSEX memstat;
	memstat.dwLength = sizeof(memstat);
	shark::BOOL state = GlobalMemoryStatusEx((LPMEMORYSTATUSEX)&memstat);
	if (state) {
		std::get<1>(t) = memstat.ullTotalPhys;
		std::get<0>(t) = memstat.ullAvailPhys;
	}
	std::get<2>(t) = state;
#else
	shark::int64 pages = sysconf(_SC_PHYS_PAGES);
	shark::int64 page_size = sysconf(_SC_PAGE_SIZE);
	shark::int64 pagesFree = sysconf(_SC_AVPHYS_PAGES);
	std::get<1>(t) = pages * page_size;
	std::get<0>(t) = pagesFree * page_size;
	std::get<2>(t) = 1;
#endif
	return t;
}