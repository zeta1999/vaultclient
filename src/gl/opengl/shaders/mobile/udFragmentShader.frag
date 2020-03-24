#version 300 es
precision mediump float;
precision highp int;

uniform highp sampler2D SPIRV_Cross_Combinedtexture0sampler0;
uniform highp sampler2D SPIRV_Cross_Combinedtexture1sampler1;

in highp vec2 in_var_TEXCOORD0;
layout(location = 0) out highp vec4 out_var_SV_Target;

void main()
{
    out_var_SV_Target = vec4(texture(SPIRV_Cross_Combinedtexture0sampler0, in_var_TEXCOORD0).xyz, 1.0);
    gl_FragDepth = texture(SPIRV_Cross_Combinedtexture1sampler1, in_var_TEXCOORD0).x;
}

