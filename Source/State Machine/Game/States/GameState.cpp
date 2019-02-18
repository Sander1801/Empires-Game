#include "../Headers/State Machine/Game/States/GameState.h"
#include "../Headers/Graphics/Vertex.h"
#include "../Headers/Model/Mesh.h"
#include "../Headers/Debug/TerminalOutput.h"
// Standard C++
#include <vector>
#include <iostream>

GameState::GameState(GameDataRef a_GameStateData) :
	m_GameStateData(a_GameStateData),
	shader("/home/pi/projects/StandardLinux/Resources/Shaders/Triangle.vs", "/home/pi/projects/StandardLinux/Resources/Shaders/Triangle.fs")
{
}

void GameState::OnEnter()
{
	std::vector<Vertex> a_vertex;
	Vertex vert;
	vert.v3Position = glm::vec3(0.5f, 0.5f, 0.0f);
	a_vertex.push_back(vert);
	Vertex vert2;
	vert2.v3Position = glm::vec3(0.5f, -0.5f, 0.0f);
	a_vertex.push_back(vert2);
	Vertex vert3;
	vert3.v3Position = glm::vec3(-0.5f, -0.5f, 0.0f);
	a_vertex.push_back(vert3);
	Vertex vert4;
	vert4.v3Position = glm::vec3(-0.5f, 0.5f, 0.0f);
	a_vertex.push_back(vert4);

	std::vector<unsigned short> a_vIndices;
	a_vIndices.push_back(0);
	a_vIndices.push_back(1);
	a_vIndices.push_back(3);
	a_vIndices.push_back(1);
	a_vIndices.push_back(2);
	a_vIndices.push_back(3);
	
	mesh = new Mesh(a_vIndices, a_vertex);
}

void GameState::OnUpdate(float a_fDeltaTime)
{
}

void GameState::OnDraw()
{
	// Clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader.Use();
	mesh->OnDraw(shader);

	// After our draw we need to swap buffers to display on screen
	eglSwapBuffers(m_GameStateData->graphics->state.display, m_GameStateData->graphics->state.surface);
}

void GameState::OnExit()
{ 
}