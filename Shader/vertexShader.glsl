#version 330
layout(location=0) in vec2 pos;
out vec2 pos_out;
void main(){
  pos_out=pos;
  gl_Position=vec4(pos,0,1);
}