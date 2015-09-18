#version 330 
  
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 vertexcolor;

uniform mat4 fullTransformMatrix;
out vec3 fragmentcolor;

void main()
{
    vec4 myVector = vec4(position.x, position.y, position.z, 1.0);
	gl_Position = fullTransformMatrix * myVector;
	fragmentcolor = vertexcolor;
}