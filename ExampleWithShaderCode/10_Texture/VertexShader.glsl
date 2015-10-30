#version 330 
  
layout (location = 0) in vec3 vertexposition;
layout (location = 1) in vec2 vertextexcrood;
out vec2 fragmenttexcrood;
void main()
{
	fragmenttexcrood = vertextexcrood;
    gl_Position =  vec4(vertexposition.xyz,1.0);
}