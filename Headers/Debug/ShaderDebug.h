#pragma once

#include "../Config.h"
#include "TerminalOutput.h"
// External Libraries
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
// Standard C++
#include <iostream>

#ifdef Debug
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
#else
#define GetShaderStatus(vertexShader, status, type)
#define GetProgramStatus(vertexShader, status)
#endif