#version 330 

in vec2 fragmenttexcrood;
out vec4 FragColor;
uniform sampler2D gSampler;

void main()
{
  FragColor =  texture(gSampler, fragmenttexcrood);
}