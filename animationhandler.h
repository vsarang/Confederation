/**
 * @file animation_handler.h
 * @author Vikrant Sarang
 * @date May 2015
 */

#ifndef ANIMATIONHANDLER_H
#define ANIMATIONHANDLER_H

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
    public:
        unsigned int startFrame;
        unsigned int endFrame;
        float duration;

        Animation(unsigned int startFrame, unsigned int endFrame, float duration) {
            this->startFrame = startFrame;
            this->endFrame = endFrame;
            this->duration = duration;
        }
        unsigned int numFrames() {
            return endFrame - startFrame + 1;
        }
};

class AnimationHandler {
    public:
        AnimationHandler();
        AnimationHandler(const sf::IntRect &frame);
        void addAnimation(Animation &animation);
        void update(const float dt);
        void changeAnimation(int newAnim);
        sf::IntRect frame;
    private:
        std::vector<Animation> animations;
        float t;
        int curAnim;
};

#endif // ANIMATIONHANDLER_H
