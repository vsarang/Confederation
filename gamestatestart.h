/**
 * @file gamestatestart.h
 * @author Vikrant Sarang
 * @date May 2015
 */

#ifndef GAMESTATESTART_H
#define GAMESTATESTART_H

#include <SFML/Graphics.hpp>
#include "gamestate.h"
#include "gamestateeditor.h"

class GameStateStart : public GameState {
    public:
        GameStateStart(Game* game);
        virtual void draw(const float dt);
        virtual void update(const float dt);
        virtual void handleInput();

    private:
        sf::View view;

        void handleKeyPress(sf::Event event);
        void loadGame();
};

#endif // GAMESTATESTART_H
