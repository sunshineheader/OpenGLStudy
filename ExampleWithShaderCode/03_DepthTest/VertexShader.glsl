#version 330 
  
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 vertexcolor;

out vec3 fragmentcolor;

void main()
{
    gl_Position = vec4(position.x, position.y, position.z, 1.0);
	fragmentcolor = vertexcolor;
}