#ifndef __SHADER_H
#define __SHADER_H

// Standard C++
#include <string>

class Shader
{
public:
	unsigned int ID;

	// Constructor generates the shader on the fly
	Shader(const char* vertexPath, const char* fragmentPath);

	// Activate the shader
	void Use();

	// Utility uniform functions
	void SetBool(const std::string &name, bool value) const;
	void SetInt(const std::string &name, int value) const;
	void SetFloat(const std::string &name, float value) const;
};
#endif