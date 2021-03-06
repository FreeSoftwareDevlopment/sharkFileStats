#include "firstuniversalWINuLINUXcpp.h"
#include <parser.h>
#include <stchar.h>

using namespace std;
using namespace parser;

void sharkName() {
	cout << "DStat\n<c> Sharkbyteprojects\nhttps://github.com/FreeSoftwareDevlopment/sharkFileStats/" << endl;
}

#define cxJson (shark::uminiint)0b001
#define cxCurrentpath (shark::uminiint)0b010
#define cxExtendet (shark::uminiint)0b100
#define cxNone (shark::uminiint)0b000

template<typename booltype = shark::BOOL>
char* booltostring(booltype x) {
	char* bExists = stchar::stringtochar(std::string("false"));
	if (x) {
		free(bExists);
		bExists = stchar::stringtochar(std::string("true"));
	}
	return bExists;
}

void content(shark::uminiint cx, char* path = ".") {
	shark::BOOL cExtendet = cx & cxExtendet, cJson = cx & cxJson;
	shark::int64 freediskspace = disks::freeDiskSpace(path);
	shark::BOOL isFolder = disks::isPathFolder(path) & dfile, exists = disks::fileExists(path);
	shark::int64 freeRam, ram;
	shark::BOOL RamOK{ 0 };
	tie(freeRam, ram, RamOK) = mem::getMemPhys();
	if (cJson) {
		cout << "{" << "\"currentFreeSpace\": " << freediskspace;
		if (RamOK != 0) {
			cout << ", \"freePhysMem\": " << freeRam << ", \"totalPhysRam\": " << ram;
		}
		if (cExtendet) {
			auto sycn{ chrono::system_clock::now().time_since_epoch().count() * chrono::milliseconds::period::num / chrono::milliseconds::period::den },
				stcn{ chrono::steady_clock::now().time_since_epoch().count() * chrono::milliseconds::period::num / chrono::milliseconds::period::den };
			cout << ", \"targetOS\": \"" << ostype << "\", \"pathexists\": " << booltostring(exists) <<
				", \"isPathFile\": " << booltostring(isFolder) << ", \"ramFailed\": " << booltostring(!RamOK) <<
				", \"systemclock\": " << sycn << ", \"steadyclock\": " << stcn;
		}
	}
	else {
		sharkName();
		cout << "Current Free Space: " << freediskspace << " bytes\n";
		if (cExtendet) {
			auto sycn{ chrono::system_clock::now().time_since_epoch().count() * chrono::milliseconds::period::num / chrono::milliseconds::period::den },
				stcn{ chrono::steady_clock::now().time_since_epoch().count() * chrono::milliseconds::period::num / chrono::milliseconds::period::den };
			cout << "Compiled for OS: " << ostype << "\n" << "Selected Path: " << path << "\n" <<
				"Selected Path Exists: " << booltostring(exists) << "\n" <<
				"Is Path File: " << booltostring(isFolder) << "\n" <<
				"System Clock: " << sycn << " seconds\n" <<
				"Steady Clock: " << stcn << " seconds\n";
		}
		if (RamOK != 0) {
			cout << "Free Physical Memory: " << freeRam <<
				"\nTotal Physical Memory: " << ram << "\n";
		}
		cout << flush;
	}
	if (cJson) {
		cout << "}" << endl;
	}
}

int main(int argc, char* argv[])
{
	const unsigned int lenght = 3;
	parser::args<shark::uminiint> nc[lenght] = {
		parser::args<shark::uminiint>(cxJson, std::string("-json")),
		parser::args<shark::uminiint>(cxExtendet, std::string("-ext")),
		parser::args<shark::uminiint>(cxCurrentpath, std::string("-cpath"), true)
	};
	returns<shark::uminiint, std::vector<returns<std::string, shark::uminiint>>> parsed = parse(cxNone, nc, lenght, argc, argv);
	if (parsed.bval.size() > 0) {
		for (unsigned int x{ 0 }; x < parsed.bval.size(); x++) {
			if (parsed.bval[x].bval == cxCurrentpath) {
				content(parsed.mainval, stchar::stringtochar(parsed.bval[x].mainval));
				return 0;
			}
		}

	}
	content(parsed.mainval);
	return 0;
}
