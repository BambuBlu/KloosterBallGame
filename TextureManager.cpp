#include "TextureManager.h"

TextureManager::TextureManager()
{

}

void TextureManager::cargar_textura(const std::string& _nombre, const std::string& _ubicacion)
{
    sf::Texture texture;

    texture.loadFromFile(_nombre);

    this->textures[_ubicacion] = texture;

    return;

}

sf::Texture& TextureManager::get_textura(const std::string& _textura)
{
    return this->textures.at(_textura);
}
