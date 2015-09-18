#version 330 
  
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 vertexcolor;

uniform mat4 modelTransformMatrix;
uniform mat4 projectionMatrix;

out vec3 fragmentcolor;

void main()
{
    vec4 myVector = vec4(position.x, position.y, position.z, 1.0);
	vec4 newPosition= modelTransformMatrix * myVector;
	vec4 projectionPosition = projectionMatrix * newPosition;
	gl_Position = projectionPosition;
	fragmentcolor = vertexcolor;
}