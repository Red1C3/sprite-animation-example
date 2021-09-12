#include <Sprite.h>
using namespace std;
using namespace sf;
Sprite::Sprite() {}
Sprite &Sprite::instance()
{
    static Sprite sprite;
    return sprite;
}
void Sprite::init(vector<string> texPaths,int fps)
{
    textures.resize(texPaths.size());
    currentTexInd = 0;
    spf = 1.0f / (float)fps;
    for (unsigned i = 0; i < texPaths.size(); ++i)
    {
        Image image;
        auto result = image.loadFromFile(texPaths[i]);
        if (!result)
        {
            throw exception();
        }
        glGenTextures(1, &textures[i]);
        glBindTexture(GL_TEXTURE_2D, textures[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y,
                     0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
        assert(glGetError() == 0);
    }
    float vertices[8] = {-1, -1,
                         -1, 1,
                         1, -1,
                         1, 1};
    unsigned indices[6] = {2, 0, 1,
                           2, 1, 3};
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned) * 6, indices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    assert(glGetError() == 0);
    timer.restart();
}
void Sprite::draw(){
    if(timer.getElapsedTime().asSeconds()>=spf){
        timer.restart();
        currentTexInd++;
        currentTexInd = currentTexInd % textures.size();
        glBindTexture(GL_TEXTURE_2D, textures[currentTexInd]);
    }
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
void Sprite::terminate()
{
    glBindVertexArray(0);
    for (unsigned i = 0; i < textures.size(); ++i)
    {
        glDeleteTextures(1, &textures[i]);
    }
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);
}