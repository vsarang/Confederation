/**
 * @file gamestatestart.cpp
 * @author Vikrant Sarang
 * @date May 2015
 */

#include "gamestatestart.h"

GameStateStart::GameStateStart(Game* game) {
    this->game = game;
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    view.setSize(pos);
    pos *= 0.5f;
    view.setCenter(pos);
}

void GameStateStart::draw(const float dt) {
    game->window.setView(view);
    game->window.clear(sf::Color::Black);
    game->window.draw(game->background);
}

void GameStateStart::update(const float dt) {

}

void GameStateStart::handleInput() {
    sf::Event event;
    while (game->window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                game->window.close();
                break;
            case sf::Event::Resized: {
                view.setSize(event.size.width, event.size.height);
                game->background.setPosition(game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
                sf::Vector2u bgSize = game->background.getTexture()->getSize();
                game->background.setScale(float(event.size.width)/bgSize.x, float(event.size.height)/bgSize.y);
                break;
            }
            case sf::Event::KeyPressed:
                handleKeyPress(event);
                break;
            default:
                break;
        }
    }
}

void GameStateStart::handleKeyPress(sf::Event event) {
    switch (event.key.code) {
        case sf::Keyboard::Escape:
            game->window.close();
            break;
        case sf::Keyboard::Space:
            loadGame();
            break;
        default:
            break;
    }
}

void GameStateStart::loadGame() {
    game->pushState(new GameStateEditor(game));
}
