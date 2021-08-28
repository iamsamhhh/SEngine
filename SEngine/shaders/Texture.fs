#version 330 core
out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D container;
uniform sampler2D face;
uniform float mixValue;

void main()
{
    FragColor = mix(texture(container, TexCoord), texture(face, TexCoord), mixValue);
}
