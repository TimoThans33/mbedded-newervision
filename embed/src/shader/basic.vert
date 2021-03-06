#version 120
uniform mat4 MVP;
attribute vec2 vertex_buffer;
attribute vec3 velocity_color;
varying vec4 color;
void main()
{
    gl_Position = MVP * vec4(vertex_buffer.x, vertex_buffer.y, 0, 1.0);
    color = vec4( velocity_color.r , velocity_color.g , velocity_color.b, 1.0);
}