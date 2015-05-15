/**
 * @file texturemanager.h
 * @author Vikrant Sarang
 * @date May 2015
 */
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager {
    public:
        TextureManager();
        void loadTexture(const std::string &name, const std::string &filename);
        sf::Texture &get(const std::string &name);
    private:
        std::map<std::string, sf::Texture> textures;
};

#endif // TEXTUREMANAGER_H
