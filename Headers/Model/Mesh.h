#ifndef __MESH_H
#define __MESH_H

// Standard C++
#include <vector>

// Forward Declaration
class Shader;
struct Texture;
struct Vertex;

class Mesh {
public:
	/// Functions
	Mesh(std::vector<unsigned int> a_vIndices, std::vector<Texture> a_vTextures, std::vector<Vertex> a_vVertices);
	~Mesh();

	/* 
	 * Render the mesh
	 * 
	 * @params { Shader shader } Program transforming inputs to outputs.
	 */
	void OnDraw(Shader a_Shader);

	/// Variables
	std::vector<unsigned int> m_vIndices;
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