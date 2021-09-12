# sprite-animation-example
A simple sprites animator using OpenGL 3.3 with C++
## What it can do?
Basically it takes an FPS and a number of sprites and plays them with the given FPS.
## Usage
Provide the FPS and Sprites paths like the following:
```
./sae 60 ./sprite1.png ./sprite2.png
```
You can use whatever count of sprites you want of course
### Supported images formats
PNG,BMP,TGA and JPG, other formats may work too, only PNG was tested (The mentioned above should work flawlessly though).
## Build
The recommended way is to use Meson.
However, you can build without it, with the required dependencies included and linked ofc.
Note that after building the binary is expecting "Shader" folder to be in the same directory as the executable.
### Dependencies
- [SFML](https://www.sfml-dev.org) (Link against at least Windows, System and Graphics modules)
- [GLEW](http://glew.sourceforge.net/)

Also note that, while the project uses OpenGL 3.3, I think the same code should work with versions 2.0-latest, check the docs of the version you desire to use to make sure !
## License 
Under MIT License, check [License](./LICENSE)

Made with Retro Kittens Dancing