#version 330 core
out vec4 FragColor;
uniform vec3 objectColor;
uniform vec3 lightColor;
void main()
{
    if (objectColor.x > 0.0f) {
        FragColor = vec4(lightColor * objectColor, 1.0);
    } else {
        FragColor = vec4(lightColor, 1.0);
    }
    
}