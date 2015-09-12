#version 330 

in vec3  fragmentcolor;
out vec4 color;

void main()
{
    color = vec4(fragmentcolor.x,fragmentcolor.y,fragmentcolor.z, 1.0f);
}