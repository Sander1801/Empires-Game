#ifndef __VERTEX_H
#define __VERTEX_H

// Include GLM
#undef countof
#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#undef countof

struct Vertex 
{
	glm::vec2 v2TexCoords;
	glm::vec3 v3Position;
	glm::vec3 v3Normal;
	glm::vec3 v3Tangent;
	glm::vec3 v3Bitangent;
};

#endif