#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

/*
    Clase proveniente de Texture Manager
    Carga y guarda las texturas
*/

class TextureManager
{
    private:
        std::map<std::string, sf::Texture> textures;

    public:
        TextureManager();

        void cargar_textura(const std::string&, const std::string&);

        sf::Texture& get_textura(const std::string&);
};
#endif
