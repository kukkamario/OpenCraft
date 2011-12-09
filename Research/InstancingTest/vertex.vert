#version 130

uniform mat4 modelViewProjectionMatrix;
uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;

in vec3 texCoordIn;
in vec3 vertex;
in vec3 normal;
in float light;

out vec3 normal_out;
out vec3 texCoord;
out float light_out;

void main(void)
{
    normal_out = normal;
    texCoord = texCoordIn;
    light_out = light;

    gl_Position = modelViewProjectionMatrix *vec4(vertex,1);
}
