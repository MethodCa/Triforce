#version 400

layout(location = 0) in vec3 position; //from VBO stream
uniform mat4 modelMatrix; //uniform variable coming from our program
layout(location = 1) in vec3 fcolour;
out vec3 fragcolour;

void main(void)
{
   vec4 a = vec4(position, 1.0);

   //transform the vertices by the modelMatrix
   a =  modelMatrix * a;

   fragcolour = fcolour;
   gl_Position = a;
} 