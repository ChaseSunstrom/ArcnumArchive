#version 330 core
out vec4 frag_color;
  
in vec3 color;
in vec2 texture_coord;

unifrom sampler2D text;

void main()
{
    frag_color = texture(text, texture_coord) * vec4(color, 1.0);
} 