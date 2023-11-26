#version 330 core
out vec4 FragColor;
  
in vec2 TexCoord;

uniform vec4 color;
uniform sampler2D tex;

void main()
{
    vec4 text = texture(tex, TexCoord);

    if (text != 0)
    {
        
		FragColor = text * color;
	}
    else 
	{
        FragColor = color;
	}
}