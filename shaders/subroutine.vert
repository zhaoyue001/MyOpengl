 #version 400
       
       #extension GL_ARB_shader_subroutine : require
       
       subroutine void subroutineType1(inout float);
       subroutine void subroutineType2(inout float);
       subroutine void subroutineType3(inout float);
       
       subroutine(subroutineType1, subroutineType2, subroutineType3) void function(inout float result)
       {
           result += float(0.123) + float(gl_VertexID);
       }
       
       subroutine uniform subroutineType1 subroutine_uniform1;
       subroutine uniform subroutineType2 subroutine_uniform2;
       subroutine uniform subroutineType3 subroutine_uniform3;
       
       out vec4 result;
       
       void main()
       {
           result = vec4(0, 1, 2, 3);
       
           subroutine_uniform1(result.x);
           subroutine_uniform2(result.y);
           subroutine_uniform3(result.z);
       
           result.w += result.x + result.y + result.z;
       }