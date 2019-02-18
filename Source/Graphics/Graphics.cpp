#include "../Headers/Graphics/Graphics.h"

using namespace glm;

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
}

void Graphics::esInitContext()
{
	if (p_state != NULL)
	{
		memset(p_state, 0, sizeof(Target_State));
	}
}

/*
Set up the EGL and in the case of Raspberry DispamX
Set up OpenGL states needed
*/
void Graphics::init_ogl( int width, int height)
{
	int32_t success = 0;
	EGLBoolean result;
	EGLint num_config;

	bcm_host_init(); //RPI needs this

	//RPI setup is a little different to normal EGL
	DISPMANX_ELEMENT_HANDLE_T DispmanElementH;
	DISPMANX_DISPLAY_HANDLE_T DispmanDisplayH;
	DISPMANX_UPDATE_HANDLE_T DispmanUpdateH;
	VC_RECT_T dest_rect;
	VC_RECT_T src_rect;
	EGLConfig config;

	// get an EGL display connection
	state.display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

	// initialize the EGL display connection
	result = eglInitialize(state.display, NULL, NULL);
	
	// get an appropriate EGL frame buffer configuration
	result = eglChooseConfig(state.display, attribute_list, &config, 1, &num_config);
	assert(EGL_FALSE != result);

	// get an appropriate EGL frame buffer configuration
	result = eglBindAPI(EGL_OPENGL_ES_API);
	assert(EGL_FALSE != result);

	// create an EGL rendering context
	state.context = eglCreateContext(state.display, config, EGL_NO_CONTEXT, context_attributes);
	assert(state.context != EGL_NO_CONTEXT);

	// create an EGL window surface

	state.width = width;
	state.height = height;

	dest_rect.x = 100;
	dest_rect.y = 100;
	dest_rect.width = state.width; // it needs to know our window size
	dest_rect.height = state.height;

	src_rect.x = 0;
	src_rect.y = 0;
	src_rect.width = (width) << 16;
	src_rect.height = (height) << 16;

	DispmanDisplayH = vc_dispmanx_display_open(0);
	DispmanUpdateH = vc_dispmanx_update_start(0);

	DispmanElementH = 	vc_dispmanx_element_add(
		DispmanUpdateH,
		DispmanDisplayH,
		0/*layer*/,
		&dest_rect,
		0/*source*/,
		&src_rect,
		DISPMANX_PROTECTION_NONE, 
		0 /*alpha value*/,
		0/*clamp*/,
		(DISPMANX_TRANSFORM_T) 0/*transform*/);

	state.nativewindow.element = DispmanElementH;
	state.nativewindow.width = state.width;
	state.nativewindow.height = state.height;
	vc_dispmanx_update_submit_sync(DispmanUpdateH);

	state.surface = eglCreateWindowSurface(state.display, config, &(state.nativewindow), NULL);
	assert(state.surface != EGL_NO_SURFACE);

	    // connect the context to the surface
	result = eglMakeCurrent(state.display, state.surface, state.surface, state.context);
	assert(EGL_FALSE != result);

	// Disable vSync because we want more frames per seconds in debug mode.
	eglSwapInterval(state.display, 0);

	// Some OpenGLES2.0 states that we might need
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	
	// Setup the viewport
	glViewport(0, 0, width, height);
}