#include "Triforce.h"

//#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp> //for matrix transformation functions
#define BUFFER_OFFSET(i) ((char *)NULL + (i))

Triforce::Triforce(GLSLProgram* theShaderProgram)
{
	shaders = theShaderProgram;
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	// An array of 3 vectors which represents 3 vertices
	static const GLfloat g_vertex_buffer_data[] =
	{
		//triangle #0######################################
		-0.4f, -0.f, 0.f, //lower left corner ->1
		1.0f, 1.f, 0.0f, // color
		0.4f, -0.f, 0.0f, //lower right corner ->2
		1.0f, 1.f, 0.0f, // color
		0.0f, 0.8f, 0.0f, //top corner ->3
		1.0f, 1.f, 0.0f, // color

		//back triangle #0
		0.4f, -0.f, 0.2f, //lower right corner ->2
		1.0f, 1.0f, 0.0f, // color
		-0.4f, -0.f, 0.2f, //lower left corner ->1
		1.0f, 1.0f, 0.0f, // color
		0.0f, 0.8f, 0.2f, //top corner ->3
		1.0f, 1.0f, 0.0f, // color

		//triangle #1######################################
		-0.4f, -0.f, 0.f, //lower left corner ->1
		1.0f, 1.0f, 0.0f, // color
		-0.8f, -0.8f, 0.0f, //backside, top corner -> 5
		1.0f, 1.0f, 0.0f, // color
		0.0f, -0.8f, 0.0f, //backside, lower right corner ->6
		1.0f, 1.0f, 0.0f, // color

		//back triangle #1
		0.0f, -0.8f, 0.2f, //backside, lower right corner ->6
		1.0f, 1.0f, 0.0f, // color
		-0.8f, -0.8f, 0.2f, //backside, top corner -> 5
		1.0f, 1.0f, 0.0f, // color
		-0.4f, -0.f, 0.2f, //lower left corner ->1
		1.0f, 1.0f, 0.0f, // color

		//####################triangle#2 - left edge of triforce 
		0.0f, -0.8f, 0.0f, //backside, lower right corner ->6
		1.0f, 1.0f, 0.0f, // color
		0.8f, -0.8f, -0.0f, //->7
		1.0f, 1.0f, 0.0f, // color
		0.4f, -0.f, 0.0f, //lower right corner ->2
		1.0f, 1.0f, 0.0f, // color

		//back triangle#2 - left edge of triforce 
		0.8f, -0.8f, 0.2f, //->7
		1.0f, 1.0f, 0.0f, // color
		0.0f, -0.8f, 0.2f, //backside, lower right corner ->6
		1.0f, 1.0f, 0.0f, // color
		0.4f, -0.f, 0.2f, //lower right corner ->2
		1.0f, 1.0f, 0.0f, // color

		//******** triangle #0Base 1
		-0.4f, -0.f, 0.f, //lower left corner ->1
		1.0f, 0.85f, 0.0f, // color
		0.4f, -0.f, 0.2f, //lower right corner ->2 profundo
		1.0f, 0.85f, 0.0f, // color
		0.4f, -0.f, 0.0f, //lower right corner ->2
		1.0f, 0.85f, 0.0f, // color

		-0.4f, -0.f, 0.f, //lower left corner ->1
		1.0f, 0.99f, 0.0f, // color
		-0.4f, -0.f, 0.2f, //lower left corner ->1 profundo
		1.0f, 0.99f, 0.0f, // color
		0.4f, -0.f, 0.2f, //lower right corner ->2 profundo
		1.0f, 0.99f, 0.0f, // color

		//triangle #0 right side
		0.4f, -0.f, 0.0f, //lower right corner ->2
		1.0f, 0.85f, 0.0f, // color
		0.4f, -0.f, 0.2f, //lower right corner ->2 profundo
		1.0f, 0.85f, 0.0f, // color
		0.0f, 0.8f, 0.0f, //top corner ->3
		1.0f, 0.85f, 0.0f, // color

		0.0f, 0.8f, 0.0f, //top corner ->3
		1.0f, 0.85f, 0.0f, // color
		0.4f, -0.f, 0.2f, //lower right corner ->2 profundo
		1.0f, 0.85f, 0.0f, // color
		0.0f, 0.8f, 0.2f, //top corner ->3 prof
		1.0f, 0.85f, 0.0f, // color

		//triangle #0 left side
		-0.4f, -0.f, 0.f, //lower left corner ->1
		1.0f, 0.85f, 0.0f, // color
		0.0f, 0.8f, 0.0f, //top corner ->3
		1.0f, 0.85f, 0.0f, // color
		0.0f, 0.8f, 0.2f, //top corner ->3 prof
		1.0f, 0.85f, 0.0f, // color

		0.0f, 0.8f, 0.2f, //top corner ->3 prof
		1.0f, 0.85f, 0.0f, // color
		-0.4f, -0.f, 0.2f, //lower left corner ->1 profundo
		1.0f, 0.85f, 0.0f, // color
		-0.4f, -0.f, 0.f, //lower left corner ->1
		1.0f, 0.85f, 0.0f, // color

		//triangle #1 Base
		-0.8f, -0.8f, 0.0f, //backside, top corner -> 5
		1.0f, 0.85f, 0.0f, // color
		0.0f, -0.8f, 0.2f, //backside, lower right corner ->6 prof
		1.0f, 0.85f, 0.0f, // color
		0.0f, -0.8f, 0.0f, //backside, lower right corner ->6
		1.0f, 0.85f, 0.0f, // color

		-0.8f, -0.8f, 0.0f, //backside, top corner -> 5
		1.0f, 0.85f, 0.0f, // color
		-0.8f, -0.8f, 0.2f, //backside, top corner -> 5 prof
		1.0f, 0.85f, 0.0f, // color
		0.0f, -0.8f, 0.2f, //backside, lower right corner ->6 prof
		1.0f, 0.85f, 0.0f, // color

		//triangle #1 left side
		-0.4f, -0.f, 0.f, //lower left corner ->1
		1.0f, 0.85f, 0.0f, // color
		-0.8f, -0.8f, 0.2f, //backside, top corner -> 5 prof
		1.0f, 0.85f, 0.0f, // color
		-0.8f, -0.8f, 0.0f, //backside, top corner -> 5
		1.0f, 0.85f, 0.0f, // color

		-0.4f, -0.f, 0.f, //lower left corner ->1
		1.0f, 0.85f, 0.0f, // color
		-0.4f, -0.f, 0.2f, //lower left corner ->1 profundo
		1.0f, 0.85f, 0.0f, // color
		-0.8f, -0.8f, 0.2f, //backside, top corner -> 5 prof
		1.0f, 0.85f, 0.0f, // color

		//triangle #1right
		-0.4f, -0.f, 0.f, //lower left corner ->1
		1.0f, 0.85f, 0.0f, // color
		0.0f, -0.8f, 0.0f, //backside, lower right corner ->6
		1.0f, 0.85f, 0.0f, // color
		0.0f, -0.8f, 0.2f, //backside, lower right corner ->6 prof
		1.0f, 0.85f, 0.0f, // color

		0.0f, -0.8f, 0.2f, //backside, lower right corner ->6 prof
		1.0f, 0.85f, 0.0f, // color
		-0.4f, -0.f, 0.2f, //lower left corner ->1 prof
		1.0f, 0.85f, 0.0f, // color
		-0.4f, -0.f, 0.f, //lower left corner ->1
		1.0f, 0.85f, 0.0f, // color

		// triangle#2 Base
		0.8f, -0.8f, -0.0f, //->7
		1.0f, 0.85f, 0.0f, // color
		0.0f, -0.8f, 0.0f, //backside, lower right corner ->6
		1.0f, 0.85f, 0.0f, // color
		0.0f, -0.8f, 0.2f, //backside, lower right corner ->6 prof
		1.0f, 0.85f, 0.0f, // color

		0.0f, -0.8f, 0.2f, //backside, lower right corner ->6 prof
		1.0f, 0.85f, 0.0f, // color
		0.8f, -0.8f, 0.2f, //->7 prof
		1.0f, 0.85f, 0.0f, // color
		0.8f, -0.8f, -0.0f, //->7
		1.0f, 0.85f, 0.0f, // color

		//triangle#2 left
		0.0f, -0.8f, 0.0f, //backside, lower right corner ->6
		1.0f, 0.85f, 0.0f, // color
		0.4f, -0.f, 0.0f, //lower right corner ->2
		1.0f, 0.85f, 0.0f, // color
		0.4f, -0.f, 0.2f, //lower right corner ->2 prof
		1.0f, 0.85f, 0.0f, // color

		0.4f, -0.f, 0.2f, //lower right corner ->2 prof
		1.0f, 0.85f, 0.0f, // color
		0.0f, -0.8f, 0.2f, //backside, lower right corner ->6 prof
		1.0f, 0.85f, 0.0f, // color
		0.0f, -0.8f, 0.0f, //backside, lower right corner ->6
		1.0f, 0.85f, 0.0f, // color

		//triangle#2 right
		0.8f, -0.8f, 0.0f, //->7
		1.0f, 0.85f, 0.0f, // color
		0.8f, -0.8f, 0.2f, //->7 prof
		1.0f, 0.85f, 0.0f, // color
		0.4f, -0.f, 0.2f, //lower right corner ->2 prof
		1.0f, 0.85f, 0.0f, // color

		0.4f, -0.f, 0.2f, //lower right corner ->2 prof
		1.0f, 0.85f, 0.0f, // color
		0.4f, -0.f, 0.0f, //lower right corner ->2 
		1.0f, 0.85f, 0.0f, // color
		0.8f, -0.8f, 0.0f, //->7
		1.0f, 0.85f, 0.0f, // color
		//************************************************************
	};

	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vboID);

	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vboID);

	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	//Position Data
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		6 * sizeof(GLfloat),  // stride
		(void*)0            // array buffer offset
	);

	//COLOR data
	glVertexAttribPointer(
		1,                  // attribute 1. No particular reason for 1, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		6 * sizeof(GLfloat),  // stride
		BUFFER_OFFSET(sizeof(GLfloat) * 3)            // array buffer offset
	);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1); //channel 1

	glBindVertexArray(0); // Disable our Vertex Array Object? 

	glBindBuffer(GL_ARRAY_BUFFER, 0);// Disable our Vertex Buffer Object

	return;
}

Triforce::~Triforce()
{
	// delete VBO when object destroyed
	glDeleteBuffers(1, &vboID);
	glDeleteVertexArrays(1, &vaoID);
}

void Triforce::Draw()
{
	//send the modelMatrix to the shader
	shaders->setUniform("modelMatrix", modelMatrix);

	glBindVertexArray(vaoID);
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 200); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glBindVertexArray(0);
}

void Triforce::Update(float seconds)
{
	angle += seconds * glm::radians(rotationSpeed);

	//reset angle if it gets bigger than needed
	if (angle > glm::two_pi<float>())
		angle -= glm::two_pi<float>();

	//calculate model matrix 
	modelMatrix = glm::mat4(1.f); //identity matrix
	//note the order of operations here: translate THEN rotate!
	//modelMatrix = glm::translate(modelMatrix, glm::vec3(0.5f, 0.5f, 0.f));
	modelMatrix = glm::rotate(modelMatrix, angle, axis);
	//modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f, 0.1f, 1.0f));
}