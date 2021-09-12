#include <Sprite.h>
using namespace std;
using namespace sf;
Sprite::Sprite() {}
Sprite &Sprite::instance()
{
    static Sprite sprite;
    return sprite;
}
void Sprite::init(vector<string> texPaths)
{
    textures.resize(texPaths.size());
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
}
void Sprite::terminate(){
    for (unsigned i = 0; i < textures.size();++i){
        glDeleteTextures(1, &textures[i]);
    }
}