#pragma once
#include "glslprogram.h"

class Triforce
{
	GLuint vboID, vaoID;
public:
	GLSLProgram *shaders;
	GLSLProgram* shaders1;
	glm::mat4 modelMatrix;
	//...and an accumulator for rotatation:
	float angle = 0.f;
	float rotationSpeed = 0.f;
	glm::vec3 axis = glm::vec3(1.0f, 1.f, 0.f);

	void Update(float seconds);
	void Draw();
	void Triforce::DrawOutline();
	Triforce(GLSLProgram* theShaderProgram);
	~Triforce();
};