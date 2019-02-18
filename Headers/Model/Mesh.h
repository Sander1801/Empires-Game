#ifndef __MESH_H
#define __MESH_H

#include "../Headers/Asset Manager/Texture.h"
// Standard C++
#include <vector>

// Forward Declaration
class Shader;
struct Vertex;

class Mesh {
public:
	/// Functions
	Mesh(std::vector<unsigned short>& a_vIndices, std::vector<Vertex>& a_vVertices, std::vector<Texture> a_vTextures = std::vector<Texture>());
	~Mesh();

	/* 
	 * Render the mesh
	 * 
	 * @params { Shader shader } Program transforming inputs to outputs.
	 */
	void OnDraw(Shader a_Shader);

	/// Variables
	std::vector<unsigned short> m_vIndices;
	std::vector<Texture> m_vTextures;
	std::vector<Vertex> m_vVertices;

private:
	/// Variables
	unsigned int VBO, EBO;
	
	/// Functions
	/*
	 * Prepare the mesh: generate buffers, bind buffers, et cetera.
	 *
	 */
	void SetupMesh();
};
#endif