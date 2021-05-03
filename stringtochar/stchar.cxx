#include "stchar.h"

char* stchar::stringtochar(string stri) {
	int lengthd = stri.length() + 1;
	char* content{ (char*)malloc(lengthd + 1) };
	if (content == nullptr || content == NULL) {
		throw ("Malloc Err");
		return (char*)"";
	}
#ifdef strcpy_s_use //DEFINE strcpy_s_use to use strcpy_s instead of strncpy (strncpy works better on linux, both work on windows)
	strcpy_s(content, lengthd, stri.c_str());
#else
	strncpy(content, stri.c_str(), lengthd);
#endif
	return content;
}