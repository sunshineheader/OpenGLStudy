#version 330 
  
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 vertexcolor;
uniform float gScale;
out vec3 fragmentcolor;

void main()
{
    gl_Position = vec4(gScale * position.x, gScale * position.y, position.z, 1.0);
	fragmentcolor = vertexcolor;
}