#pragma once

#include <iostream> // we're going to be loading files so need these
#include <fstream>
#include <string>
using namespace std;

class FileLoader
{
public:
	FileLoader();
	~FileLoader();
	
//	int height;
//	int width;
	int comp;
	

	char* Load(char const *filename, int*, int*); // specifically for graphics
	
	const char* LoadText(char const *filename);
	
};

