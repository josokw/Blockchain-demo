#include "ClocksTimers.h"

#include <ctime>
#include <string>

char timeFormat[] = {"%Y/%m/%d-%H.%M.%S"};

std::string timepointAsString(const std::chrono::system_clock::time_point &tp)
{
   // convert to system time (C-lib and POSIX)
   time_t t{std::chrono::system_clock::to_time_t(tp)};
   std::string ts{ctime(&t)}; // convert to calendar time
   ts.resize(ts.size() - 1);  // skip trailing newline

   char tstr[] = "yyyy/mm/dd-HH:MM:SS";
   strftime(tstr, 80, timeFormat, std::localtime(&t));

   return tstr;
}
