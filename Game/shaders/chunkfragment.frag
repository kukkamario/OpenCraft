uniform sampler2D qt_Texture0;
varying vec4 qt_TexCoord0;



vec3 sh_light_groove(vec3 normal){
    float x = normal.x;
    float y = normal.y;
    float z = normal.z;

    const float C1 = 0.429043;
    const float C2 = 0.511664;
    const float C3 = 0.743125;
    const float C4 = 0.886227;
    const float C5 = 0.247708;

    return (
        C1 * vec3( 0.0203348, -0.0044201, -0.0452180) * (x * x - y * y) +
        C3 * vec3(-0.0935561, -0.1254260, -0.1525629) * z * z +
        C4 * vec3( 0.3783264,  0.4260425,  0.4504587) -
        C5 * vec3(-0.0935561, -0.1254260, -0.1525629) +
        2.0 * C1 * vec3(-0.0621750, -0.0554432, -0.0396779) * x * y +
        2.0 * C1 * vec3(-0.0572703, -0.0502192, -0.0363410)  * x * z +
        2.0 * C1 * vec3( 0.0077820, -0.0148312, -0.0471301) * y * z +
        2.0 * C2 * vec3(-0.1033028, -0.1031690, -0.0884924)  * x +
        2.0 * C2 * vec3( 0.2887813,  0.3586803,  0.4147053) * y +
        2.0 * C2 * vec3( 0.0379030,  0.0295216,  0.0098567)  * z
    );
}


vec3 sh_light_beach(vec3 normal){
    float x = normal.x;
    float y = normal.y;
    float z = normal.z;

    const float C1 = 0.429043;
    const float C2 = 0.511664;
    const float C3 = 0.743125;
    const float C4 = 0.886227;
    const float C5 = 0.247708;

    return (
        C1 * vec3( 0.3697189,  0.3097930,  0.2029923) * (x * x - y * y) +
        C3 * vec3(-0.0319670, -0.0214051, -0.0147691) * z * z +
        C4 * vec3( 0.6841148,  0.6929004,  0.7069543) -
        C5 * vec3(-0.0319670, -0.0214051, -0.0147691) +
        2.0 * C1 * vec3(-0.1690202, -0.1703022, -0.1525870) * x * y +
        2.0 * C1 * vec3( 0.1641816,  0.1377558,  0.1010403)  * x * z +
        2.0 * C1 * vec3(-0.0837808, -0.0940454, -0.1027518) * y * z +
        2.0 * C2 * vec3(-0.4496467, -0.4155184, -0.3416573)  * x +
        2.0 * C2 * vec3( 0.3173355,  0.3694407,  0.4406839) * y +
        2.0 * C2 * vec3(-0.1747193, -0.1737154, -0.1657420)  * z
    );
}


vec3 sh_light_tomb(vec3 normal){
    float x = normal.x;
    float y = normal.y;
    float z = normal.z;

    const float C1 = 0.429043;
    const float C2 = 0.511664;
    const float C3 = 0.743125;
    const float C4 = 0.886227;
    const float C5 = 0.247708;

    return (
        C1 * vec3( 0.5515260,  0.4222179,  0.4162488) * (x * x - y * y) +
        C3 * vec3(-0.3742487, -0.2755962, -0.2875017) * z * z +
        C4 * vec3( 1.0351604,  0.7603549,  0.7074635) -
        C5 * vec3(-0.3742487, -0.2755962, -0.2875017) +
        2.0 * C1 * vec3( 0.6430452,  0.4971454,  0.5156357) * x * y +
        2.0 * C1 * vec3(-0.1694954, -0.1343096, -0.1335315)  * x * z +
        2.0 * C1 * vec3(-0.1150112, -0.0936603, -0.0839287) * y * z +
        2.0 * C2 * vec3( 0.7110400,  0.5423169,  0.5587956)  * x +
        2.0 * C2 * vec3( 0.4442150,  0.3430402,  0.3403777) * y +
        2.0 * C2 * vec3(-0.2247797, -0.1828517, -0.1705181)  * z
    );
}

vec3 get_eye_normal(vec2 viewport, mat4 inverse_projection){
    vec4 device_normal = vec4(((gl_FragCoord.xy/viewport)-0.5)*2.0, 0.0, 1.0);
    return normalize((inverse_projection * device_normal).xyz);
}

vec3 gamma(vec3 color){
    return pow(color, vec3(1.0/2.0));
}

vec3 fog(vec3 color, vec3 fcolor, float depth, float density){
    const float e = 2.71828182845904523536028747135266249;
    float f = pow(e, -pow(depth*density, 2));
    return mix(fcolor, color, f);
}





uniform vec2 viewport;
uniform mat3 normalmatrix;
uniform mat4 inverse_projection;
uniform sampler2DArray material

out vec3 fragment;



void main(void)
{
    gl_FragColor = texture2D(qt_Texture0, qt_TexCoord0.st);
}
