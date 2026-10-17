#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

out vec4 finalColor;
uniform float dt;


void main(){
    vec2 uv = gl_FragCoord.xy;
    float Dist = distance(uv.xy , vec2(400. , 300.));

    float a = 1.0 - smoothstep(98.0 , 102.0 , 100);
    finalColor = vec4(1.0, abs(sin(dt*0.1)), 0.3, a);
}