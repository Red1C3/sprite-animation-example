#pragma once
#include<vector>
#include<string>
#include<GL/glew.h>
#include<SFML/Graphics/Image.hpp>
#include<exception>
#include<assert.h>
class Sprite
{
private:
    Sprite();
    std::vector<GLuint> textures;

public:
    void init(std::vector<std::string> texPaths);
    static Sprite &instance();
    void terminate();
};