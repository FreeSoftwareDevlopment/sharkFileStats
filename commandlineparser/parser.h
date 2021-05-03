#pragma once
#include <vector>
#include <string>
#include <stdint.h>
namespace parser {
	template<typename T>
	class args {
	public:
		std::string tosearch;
		T numToOr;
		bool retN = false;
		bool usedbefore = false;
		args(T numToOrx, std::string tosearchx, bool retNeed = false) {
			this->numToOr = numToOrx;
			this->tosearch = tosearchx;
			this->retN = retNeed;
		}
	};

	template<typename T, typename B>
	struct returns {
	public:
		T mainval;
		B bval;
		returns(T mainval, B b) {
			this->mainval = mainval;
			bval = b;
		}
		returns() {

		}
	};

	returns<uint8_t, std::vector<returns<std::string, uint8_t>>> parse(uint8_t old, args<uint8_t> arguments[], const unsigned int as, int argc, char* argv[]);
}
