/**
 * @file gamestateeditor.h
 * @author Vikrant Sarang
 * @date May 2015
 */

#ifndef GAMESTATEEDITOR_H
#define GAMESTATEEDITOR_H

#include <SFML/Graphics.hpp>
#include "gamestate.h"

class GameStateEditor : public GameState {
    public:
        GameStateEditor(Game* game);
        virtual void draw(const float dt);
        virtual void update(const float dt);
        virtual void handleInput();

    private:
        sf::View gameView;
        sf::View guiView;
};

#endif // GAMESTATESTART_H
