#include <cstdio> // printf
#include <string>

#define printf(fmt, ...) Utils::print(__FILE__, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__);

class Utils
{
	public:
		static void print(std::string file, int line, std::string func, std::string fmt, ...);
};
