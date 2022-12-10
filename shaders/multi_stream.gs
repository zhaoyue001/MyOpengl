#version 410

#extension GL_ARB_gpu_shader5: require 
layout(points) in;
layout(points, max_vertices = 2) out;

layout(stream = 1,location = 6) out vec4 position;

void main()
{
	for (int  i = 1; i < 2; i++) {
    position = vec4( 1.0,  1.0, 0.0, 1.0);
    EmitStreamVertex(i);
	//EndStreamPrimitive(i);
	}
}
