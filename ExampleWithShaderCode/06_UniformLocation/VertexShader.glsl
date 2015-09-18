#version 330 
  
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 vertexcolor;

uniform vec3  dominatingColor;
uniform float yFilp;

out vec3 fragmentcolor;

void main()
{
    gl_Position = vec4(position.x, position.y, position.z, 1.0);
	gl_Position.y=gl_Position.y*yFilp;
	fragmentcolor = dominatingColor;
}