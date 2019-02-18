#pragma once

#include "TerminalOutput.h"
// External Libraries
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
// Standard C++
#include <iostream>

#ifdef _DEBUG
	// glGetShaderInfoLog 
	#define GetShaderStatus(vertexShader, status, type) { \
		int SUCCESS; \
		char INFOLOG[512]; \
		glGetShaderiv(vertexShader, status, &SUCCESS); \
		if (!SUCCESS) { \
			glGetShaderInfoLog(vertexShader, 512, NULL, INFOLOG); \
			PRINTINFO("ERROR::SHADER::"); \
			PRINTINFO(type); \
			PRINTINFO("::COMPILATION_FAILED\n"); \
			PRINTINFO(INFOLOG); \
			PRINTINFO("\n"); \
		}; \
	}

	// glGetProgramInfoLog
	#define GetProgramStatus(shaderProgram, status) { \
		int SUCCESS; \
		char INFOLOG[512]; \
		glGetProgramiv(shaderProgram, status, &SUCCESS); \
		if (!SUCCESS) { \
			glGetProgramInfoLog(shaderProgram, 512, NULL, INFOLOG); \
			PRINTINFO("ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n"); \
			PRINTINFO(INFOLOG); \
			PRINTINFO("\n"); \
		}; \
	}

	#define glCheckError_(file, line) \
	{ \
		GLenum errorCode; \
		while ((errorCode = glGetError()) != GL_NO_ERROR) \
		{ \
			std::string error; \
			switch (errorCode) \
			{ \ 
			case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break; \
			case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break; \
			case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break; \
			case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break; \
			case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break; \
			} \
			std::cout << error << " | " << file << " (" << line << ")" << std::endl; \
		} \
	} 
	#define glCheckError() glCheckError_(__FILE__, __LINE__) 
#else
	#define GetShaderStatus(vertexShader, status, type)
	#define GetProgramStatus(vertexShader, status)
	#define glCheckError()
#endif