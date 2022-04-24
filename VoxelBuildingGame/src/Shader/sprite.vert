#version 330 core
layout (location = 0) in vec4 aVertex;
uniform mat4 model;

out vec2 texCoord;
void main()
{
    gl_Position = model * vec4(aVertex.xy, 0.0, 1.0);
    texCoord = aVertex.zw;
}