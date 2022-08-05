#include "utils.h"
#include <stdarg.h> // va_list, va_start, va_arg, va_end

void Utils::print(std::string file, int line, std::string func, std::string fmt, ...)
{
    std::size_t found;
	std::string newFmt;
    va_list args;

    found = file.rfind('/');
    if ( found != std::string::npos &&
         found != (file.length() - 1) )
    {
        file = file.substr(found+1);
    }

    newFmt = file + "(" + std::to_string(line) + ") " + func + ": " + fmt  + "\n";

    va_start(args, fmt);
    vprintf(newFmt.c_str(), args);
    va_end(args);
}
