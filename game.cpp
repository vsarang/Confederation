/**
 * @file game.cpp
 * @author Vikrant Sarang
 * @date May 2015
 */

#include "game.h"
#include "gamestate.h"

Game::Game() {
    loadTextures();
    window.create(sf::VideoMode(800, 600), "Confederations");
    window.setFramerateLimit(60);
    background.setTexture(textureManager.get("background"));
}

Game::~Game() {
    while (!states.empty()) {
        popState();
    }
}

void Game::gameLoop() {
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if (peekState() == nullptr) {
            continue;
        }

        GameState* curState = peekState();
        curState->handleInput();
        curState->update(dt);
        window.clear(sf::Color::Black);
        curState->draw(dt);
        window.display();
    }
}

void Game::pushState(GameState* state) {
    states.push(state);
}

void Game::popState() {
    delete states.top();
    states.pop();
    return;
}

void Game::changeState(GameState* state) {
    if (!states.empty()) {
        popState();
    }
    pushState(state);
    return;
}

GameState* Game::peekState() {
    if (states.empty()) {
        return nullptr;
    } else {
        return states.top();
    }
}

void Game::loadTextures() {
    textureManager.loadTexture("background", "media/background.png");
}
