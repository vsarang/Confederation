/**
 * @file gamestateeditor.cpp
 * @author Vikrant Sarang
 * @date May 2015
 */

#include "gamestateeditor.h"

GameStateEditor::GameStateEditor(Game* game) {
    this->game = game;
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    guiView.setSize(pos);
    gameView.setSize(pos);
    pos *= 0.5f;
    guiView.setCenter(pos);
    gameView.setCenter(pos);
}

void GameStateEditor::draw(const float dt) {
    game->window.clear(sf::Color::Black);
    game->window.draw(game->background);
}

void GameStateEditor::update(const float dt) {

}

void GameStateEditor::handleInput() {
    sf::Event event;
    while (game->window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                game->window.close();
                break;
            case sf::Event::Resized: {
                guiView.setSize(event.size.width, event.size.height);
                gameView.setSize(event.size.width, event.size.height);
                game->background.setPosition(game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
                sf::Vector2u bgSize = game->background.getTexture()->getSize();
                game->background.setScale(float(event.size.width)/bgSize.x, float(event.size.height)/bgSize.y);
                break;
            }
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    game->window.close();
                }
                break;
            default:
                break;
        }
    }
}
