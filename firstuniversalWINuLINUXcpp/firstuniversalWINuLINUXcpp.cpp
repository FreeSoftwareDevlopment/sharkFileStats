﻿#include "firstuniversalWINuLINUXcpp.h"
#include <parser.h>
#include <stchar.h>

using namespace std;
using namespace parser;

void sharkName() {
	cout << "DStat\n<c> Sharkbyteprojects" << endl;
}

#define cxJson (shark::uminiint)0b001
#define cxCurrentpath (shark::uminiint)0b010
#define cxExtendet (shark::uminiint)0b100
#define cxNone (shark::uminiint)0b000

void content(shark::uminiint cx, char* path = ".") {
	shark::BOOL cExtendet = cx & cxExtendet, cJson = cx & cxJson;
	shark::int64 freediskspace = disks::freeDiskSpace(path);
	if (cJson) {
		cout << "{" << "\"currentFreeSpace\": " << freediskspace;
		if (cExtendet) {
			cout << ", \"targetOS\": \"" << ostype << "\"";
		}
	}
	else {
		sharkName();
		cout << "Current Free Space: " << freediskspace << " bytes\n";
		if (cExtendet) {
			cout << "Compiled for OS: " << ostype << "\n" << "Selected Path: " << path << "\n";
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