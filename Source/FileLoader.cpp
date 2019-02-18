#include "../Headers/FileLoader.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../Headers/stb_image.h"


FileLoader::FileLoader()
{
}

FileLoader::~FileLoader()
{
}


char* FileLoader::Load(char const *filename, int* width, int* height)
{ 

	unsigned char *data = stbi_load(filename, width, height, &comp, 4); // Ask it to load 4 componants since its rgba
	return (char*) data; 
}


// Will load a standard style text file
const char* FileLoader::LoadText(char const *filename)
{
	string line;
	
	ifstream myfile(filename);
	
	if (myfile.is_open())
	{
		getline(myfile, line, (char) myfile.eof()); // *this.eof isn't ideal but it works
		myfile.close();
	}
	
	return line.c_str();
	
}