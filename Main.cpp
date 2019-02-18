/* We still have a generic hello cubes entry function
 * this is C code, but it has the purpose of setting up the important
 * classes we need to play the game
*/

#include "../Headers/Game.h"
#include "../Headers/Graphics/Graphics.h"
#include "Headers/tiny_obj_loader.h"
// GLM
#undef countof
#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#undef countof
// EGL and GLES
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
// Standard C++
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <sys/time.h>
#include "bcm_host.h"
#include <vector>

int main(int argc, char *argv[])
{
	// The only thing we really don't want game to do is init the graphics, since its machine specific
	// and easier to do here one time
	Graphics Graphics;  // Create a 1 time instance of a graphics class;
	Graphics.esInitContext();
	Graphics.init_ogl(1200, 800); // Set any size we want, but screen size is a good idea
	
	// Having set up Graphics, make an instance of the game, and go play.
	Game	TheGame;
	TheGame.OnEnter(&Graphics); // We will let the game know where the graphics instance is, as we are still a bit dependant on it
	TheGame.OnUpdate();
}
