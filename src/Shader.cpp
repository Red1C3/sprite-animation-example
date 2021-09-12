#include <Shader.h>
using namespace std;
using namespace glm;
Shader::Shader(const char *vertexShaderPath, const char *fragmentShaderPath)
{
    auto vertexShaderCode = readBin(vertexShaderPath);
    auto fragmentShaderCode = readBin(fragmentShaderPath);
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    auto data = vertexShaderCode.data();
    GLint size = vertexShaderCode.size();
    int result;
    glShaderSource(vertexShader, 1, &data, &size);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
    assert(result != GL_FALSE);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    data = fragmentShaderCode.data();
    size = fragmentShaderCode.size();
    glShaderSource(fragmentShader, 1, &data, &size);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
    assert(result != GL_FALSE);
    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id);
    glGetProgramiv(id, GL_LINK_STATUS, &result);
    assert(result != GL_FALSE);
    glDetachShader(id, vertexShader);
    glDetachShader(id, fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    assert("Failed to compile shader" && glGetError() == 0);
}