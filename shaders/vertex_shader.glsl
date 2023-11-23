#version 330 core

layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 color;
out vec2 texture_coord;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    color = aColor;
	texture_coord = vec2(aTexCoord.x, aTexCoord.y);
}