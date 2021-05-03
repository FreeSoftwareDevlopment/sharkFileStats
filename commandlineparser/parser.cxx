#include "parser.h"
using namespace parser;

returns<uint8_t, std::vector<returns<std::string, uint8_t>>> parser::parse(uint8_t old, args<uint8_t> arguments[], const unsigned int as, int argc, char* argv[]) {
	uint8_t newuint = old;
	std::vector<returns<std::string, uint8_t>> v;
	if (argc > 1) {
		for (int x{ 1 }; x < argc; x++) {
			std::string current = std::string((argv)[x]);
			for (unsigned int y{ 0 }; y < as; y++) {
				if (arguments[y].tosearch == current && !arguments[y].usedbefore) {
					newuint |= arguments[y].numToOr;
					if (arguments[y].retN && x + 1 < argc) {
						x++;
						if (v.max_size() > v.size())
							v.push_back(returns<std::string, uint8_t>(std::string(argv[x]), arguments[y].numToOr));
					}
					arguments[y].usedbefore = true;
				}
			}
		}
	}
	returns<uint8_t, std::vector<returns<std::string, uint8_t>>> rl;
	rl.mainval = newuint;
	rl.bval = v;
	return rl;
}