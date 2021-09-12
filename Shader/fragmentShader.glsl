#version 330
out vec4 color;
in vec2 pos_out;
uniform sampler2D textureA;
void main(){
  vec2 uv=(pos_out+1)/2;
  uv.y*=-1;
  color=texture(textureA,uv);
}