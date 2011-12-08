#version 130

uniform sampler2D textureArray;
uniform mat4 inverseProjectionMatrix;

in vec3 texCoord;
in vec3 normal_out;
in float light_out;

out vec4 fragColor;
uniform vec2 viewportSize;


void main(void)
{

    fragColor = texture(textureArray, texCoord.xy)*vec4(light_out,light_out,light_out,1.0);
}


