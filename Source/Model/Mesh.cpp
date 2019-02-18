#include "../Headers/Model/Mesh.h"
#include "../Headers/Graphics/Shader.h"
#include "../Headers/Graphics/Vertex.h"
#include "../Headers/Asset Manager/Texture.h"
// EGL and GLES
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
// Standard C++
#include <stddef.h> 

Mesh::Mesh(std::vector<unsigned int> a_vIndices, std::vector<Texture> a_vTextures, std::vector<Vertex> a_vVertices)
{
	a_vIndices = m_vIndices;
	a_vTextures = m_vTextures;
	a_vVertices = m_vVertices;

	SetupMesh();
}

Mesh::~Mesh()
{
}

void Mesh::OnDraw(Shader a_Shader)
{
}

void Mesh::SetupMesh()
{
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	
	/// Load data into vertex buffers
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, m_vVertices.size() * sizeof(Vertex), &m_vVertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_vIndices.size() * sizeof(unsigned int), &m_vIndices[0], GL_STATIC_DRAW);

	/// Set the vertex attribute pointers
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, v3Position));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, v3Normal));

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, v3Tangent));
	
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, v3Bitangent));
}
