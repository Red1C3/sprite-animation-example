/*
MIT License

Copyright (c) 2021 Mohammad Issawi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <GL/glew.h>
#include <assert.h>
#include <iostream>
#include <Sprite.h>
#include <Shader.h>
using namespace std;
using namespace sf;
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "Please provide a FPS and the sprites" << endl;
        return -1;
    }
    int fps = atoi(argv[1]);
    ContextSettings ctxSettings;
    ctxSettings.antialiasingLevel = 0;
    ctxSettings.depthBits = 0;
    ctxSettings.majorVersion = 3;
    ctxSettings.minorVersion = 3;
    ctxSettings.stencilBits = 0;
    Window window(VideoMode(1024, 1024), "sprite-animation-example", Style::Default, ctxSettings);
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        cout << "Failed to init glew, probably GPU doesn't support OpenGL 3.3" << endl;
        return -1;
    }
    vector<string> args;
    for (int i = 2; i < argc; ++i)
    {
        args.push_back(argv[i]);
    }
    Sprite::instance().init(args,fps);
    Shader shader("./Shader/vertexShader.glsl", "./Shader/fragmentShader.glsl");
    glUseProgram(shader.id);
    assert(glGetError() == 0);
    while (1)
    {
        Event event;
        //SFML event handling
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                Sprite::instance().terminate();
                assert(glGetError() == 0);
                return 0;
                break;
            case Event::Resized:
                glViewport(0, 0, event.size.width, event.size.height);
                break;
            default:
                break;
            }
        }
        glClear(GL_COLOR_BUFFER_BIT);
        Sprite::instance().draw();
        window.display();
    }
}