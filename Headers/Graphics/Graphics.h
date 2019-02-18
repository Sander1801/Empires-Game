#pragma once

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <sys/time.h>
#include "bcm_host.h"
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
#include <vector>
// Include GLM
#undef countof
#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#undef countof

// this is just for fun, the CPU can't hold such a big number but does not mind you trying to define it.
#define PI				3.14159265358979323846264338327950288419716939937510582097494459072381640628620899862803482534211706798f
#define DEG2RAD(x) (x*PI)/180
#define RAD2DEG(x) x*(180/PI)


//most standard OGL demos use int versions of TRUE and FALSE (careful not to mix up with bool true and false)
#define TRUE 1
#define FALSE 0

typedef struct
{
   // save a Handle to a program object
	GLuint programObject;
		// Attribute locations
	GLint  positionLoc;
	GLint  texCoordLoc;
	
	// Sampler location
	GLint samplerLoc;
	// Texture handle
	GLuint textureId;
	
} ObjectData;

typedef struct Target_State
{
	uint32_t width;
	uint32_t height;

	EGLDisplay display;
	EGLSurface surface;
	EGLContext context;

	EGL_DISPMANX_WINDOW_T nativewindow;
	ObjectData *object_data;
	void(*draw_func)(struct Target_State*);
	
} Target_State;

static const EGLint attribute_list[] =
{
	EGL_RED_SIZE,
	8,
	EGL_GREEN_SIZE,
	8,
	EGL_BLUE_SIZE,
	8,
	EGL_ALPHA_SIZE,
	8,
//	EGL_SAMPLE_BUFFERS,1, // of we want AA, we need to uncomment these, there's a small time penalty but nicer graphics
//	EGL_SAMPLES,4, 
	EGL_DEPTH_SIZE,5,
	EGL_SURFACE_TYPE,
	EGL_WINDOW_BIT,
	EGL_NONE
};

static const EGLint context_attributes[] =
{
	EGL_CONTEXT_CLIENT_VERSION,
	2,
	EGL_NONE
};

class Graphics 
{
public:
	Graphics();
	~Graphics();
	
	Target_State state; 
	Target_State* p_state = &state;
		
	void init_ogl(int width, int height);
	void esInitContext();
};