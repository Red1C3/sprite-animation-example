#pragma once
#include <GL/glew.h>
#include <helpers.h>
#include<map>
#include<glm/glm.hpp>
class Shader
{
public:
    Shader(const char *vertexShaderPath, const char *fragmentShaderPath);
    ~Shader();
    GLuint id;
};