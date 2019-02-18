#pragma once

// Output log
#ifdef _DEBUG
#define PRINTINFO(stuff) std::cout << (stuff);
#else
#define PRINTINFO(stuff)
#endif