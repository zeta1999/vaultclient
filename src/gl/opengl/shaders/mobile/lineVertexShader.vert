#version 300 es

layout(std140) uniform type_u_EveryObject
{
    vec4 u_colour;
    vec4 u_thickness;
    layout(row_major) mat4 u_worldViewProjectionMatrix;
} u_EveryObject;

layout(location = 0) in vec4 in_var_POSITION;
layout(location = 1) in vec4 in_var_COLOR0;
layout(location = 2) in vec4 in_var_COLOR1;
out vec4 varying_COLOR0;
out vec2 varying_TEXCOORD0;

vec2 _33;

void main()
{
    vec4 _46 = vec4(in_var_POSITION.xyz, 1.0) * u_EveryObject.u_worldViewProjectionMatrix;
    float _48 = _46.w;
    vec2 _52 = ((_46.xy / vec2(_48)) * vec2(0.5)) + vec2(0.5);
    vec4 _57 = vec4(in_var_COLOR0.xyz, 1.0) * u_EveryObject.u_worldViewProjectionMatrix;
    vec2 _63 = ((_57.xy / vec2(_57.w)) * vec2(0.5)) + vec2(0.5);
    vec4 _69 = vec4(in_var_COLOR1.xyz, 1.0) * u_EveryObject.u_worldViewProjectionMatrix;
    vec2 _75 = ((_69.xy / vec2(_69.w)) * vec2(0.5)) + vec2(0.5);
    vec2 _79 = _52;
    _79.x = _52.x * u_EveryObject.u_thickness.y;
    vec4 _82 = vec4(_75.x, _75.y, _69.z, _69.w);
    _82.x = _75.x * u_EveryObject.u_thickness.y;
    vec4 _85 = vec4(_63.x, _63.y, _57.z, _57.w);
    _85.x = _63.x * u_EveryObject.u_thickness.y;
    vec2 _88 = normalize(_79 - _85.xy);
    vec2 _91 = normalize(_82.xy - _79);
    vec2 _93 = normalize(_88 + _91);
    vec2 _108 = vec2(-_93.y, _93.x) * ((u_EveryObject.u_thickness.x * 0.5) * (1.0 + (pow(0.5 - (dot(_88, _91) * 0.5), 7.0) * 7.0)));
    vec2 _111 = _108;
    _111.x = _108.x / u_EveryObject.u_thickness.y;
    vec2 _120 = _33;
    _120.x = 1.0 + _48;
    gl_Position = _46 + vec4((_111 * in_var_POSITION.w) * _48, 0.0, 0.0);
    varying_COLOR0 = u_EveryObject.u_colour;
    varying_TEXCOORD0 = _120;
}

