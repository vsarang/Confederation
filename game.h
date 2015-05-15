/**
 * @file game.h
 * @author Vikrant Sarang
 * @date May 2015
 */

#ifndef GAME_H
#define GAME_H

#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "texturemanager.h"

class GameState;

class Game {
    public:
        std::stack<GameState*> states;
        sf::RenderWindow window;
        sf::Sprite background;
        TextureManager textureManager;

        Game();
        ~Game();
        void gameLoop();
        void pushState(GameState* state);
        void popState();
        void changeState(GameState* state);
        GameState* peekState();
    private:
        void loadTextures();
};

#endif // GAME_H
