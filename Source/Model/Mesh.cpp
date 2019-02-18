#include "../Headers/Model/Mesh.h"
#include "../Headers/Graphics/Shader.h"
#include "../Headers/Graphics/Vertex.h"
#include "../Headers/Debug/TerminalOutput.h"
#include "../Headers/Debug/ShaderDebug.h"
// EGL and GLES
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
// Standard C++
#include <stddef.h> 
#include <iostream>

Mesh::Mesh(std::vector<unsigned short>& a_vIndices, std::vector<Vertex>& a_vVertices, std::vector<Texture> a_vTextures) :
	m_vIndices(a_vIndices),
	m_vVertices(a_vVertices),
	m_vTextures(a_vTextures)
{
	SetupMesh();
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Mesh::OnDraw(Shader a_Shader)
{
	// Bind appropriate textures
	for (unsigned int i = 0; i < m_vTextures.size(); i++)
	{
		// Active proper texture unit before binding
		glActiveTexture(GL_TEXTURE0 + i); 
		
		// Set the sampler to the correct texture unit
		glUniform1i(glGetUniformLocation(a_Shader.ID, (m_vTextures[i].sType).c_str()), i);
		
		// Bind the texture
		glBindTexture(GL_TEXTURE_2D, m_vTextures[i].ID);
	}  

	// Draw mesh
	glDrawElements(GL_TRIANGLES, m_vIndices.size(), GL_UNSIGNED_SHORT, 0);
	glCheckError(); // In debug mode only

	// Set everything back to defaults once configured.
	glActiveTexture(GL_TEXTURE0);
}

void Mesh::SetupMesh()
{
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	
	/// Load data into vertex buffers
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// GL_STATIC_DRAW: the data will most likely not change at all or very rarely.
	// GL_DYNAMIC_DRAW : the data is likely to change a lot.
	// GL_STREAM_DRAW : the data will change every time it is drawn
	glBufferData(GL_ARRAY_BUFFER, m_vVertices.size() * sizeof(Vertex), &m_vVertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_vIndices.size() * sizeof(unsigned short), &m_vIndices[0], GL_STATIC_DRAW);

	/// Set the vertex attribute pointers	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, v3Normal));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, v2TexCoords));

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, v3Tangent));
	
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, v3Bitangent)); 

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glCheckError(); // In debug mode only
}
