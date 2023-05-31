
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager
{
    private:
        std::map<std::string, sf::Texture> textures;

    public:
        TextureManager();

        void loadTexture(const std::string& texture_name, const std::string& file_name);

        sf::Texture& getTexture(const std::string& texture);
};
#endif
