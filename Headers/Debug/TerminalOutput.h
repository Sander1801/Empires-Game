#pragma once

#include "../Config.h"

// Output log
#ifdef Debug
#define PRINTINFO(stuff) std::cout << (stuff);
#else
#define PRINTINFO(stuff)
#endif