/**
 * @file texturemanager.cpp
 * @author Vikrant Sarang
 * @date May 2015
 */

#include "texturemanager.h"

TextureManager::TextureManager() {

}

void TextureManager::loadTexture(const std::string &name, const std::string &filename) {
    sf::Texture texture;
    texture.loadFromFile(filename);
    textures[name] = texture;
}

sf::Texture &TextureManager::get(const std::string &name) {
    return textures[name];
}
