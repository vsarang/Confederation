/**
 * @file animation_handler.cpp
 * @author Vikrant Sarang
 * @date May 2015
 */

#include "animationhandler.h"

AnimationHandler::AnimationHandler() {
    t = 0.0f;
    curAnim = -1;
}

AnimationHandler::AnimationHandler(const sf::IntRect &frame) {
    this->frame = frame;
    t = 0.0f;
    curAnim = -1;
}

void AnimationHandler::addAnimation(Animation &animation) {
    animations.push_back(animation);
}

void AnimationHandler::update(const float dt) {
    if (animations.size() <= curAnim || curAnim < 0) {
        return;
    }

    float duration = animations[curAnim].duration;
    unsigned int numFrames = animations[curAnim].numFrames(); 
    t += dt;
    if (t > duration * numFrames) {
        t = 0.0f;
    }
    unsigned int curFrame = (unsigned int) (t/duration) % numFrames;
    frame.left = frame.width * curFrame;
    frame.top = frame.height * curAnim;
}

void AnimationHandler::changeAnimation(int newAnim) {
    if (newAnim < 0 || animations.size() <= newAnim) {
        return;
    }
    if (0 < newAnim && newAnim < animations.size()) {
        curAnim = newAnim;
        t = 0.0f;
    }
}
