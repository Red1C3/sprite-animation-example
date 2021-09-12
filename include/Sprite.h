#pragma once
#include <vector>
#include <string>
#include <GL/glew.h>
#include <SFML/Graphics/Image.hpp>
#include <exception>
#include <assert.h>
#include<SFML/System/Clock.hpp>
class Sprite
{
private:
    Sprite();
    std::vector<GLuint> textures;
    GLuint VAO, VBO, EBO;
    int currentTexInd;
    float spf;
    sf::Clock timer;

public:
    void init(std::vector<std::string> texPaths,int fps);
    static Sprite &instance();
    void draw();
    void terminate();
};