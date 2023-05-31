

#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <map>


TextureManager::TextureManager()
{

}

void TextureManager::loadTexture(const std::string& texture_name, const std::string& file_name)
{
    sf::Texture texture;

    texture.loadFromFile(file_name);

    this->textures[texture_name] = texture;

    return;

}

sf::Texture& TextureManager::getTexture(const std::string& texture)
{
    return this->textures.at(texture);
}
