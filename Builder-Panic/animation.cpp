#include "animation.h"



Animation::Animation(const sf::IntRect &frame, const float &framerate, const int &length)
    : framerate_(framerate), frame_(frame)
{
    frames_.push_back(addAnimation(frame,length));
    this->setTextureRect(frames_[0][0]);
}

Animation::Animation(const sf::IntRect &frame, const float &framerate)
    : framerate_(framerate), frame_(frame)
{

}

std::vector<sf::IntRect> Animation::addAnimation(const sf::IntRect &frame , const int length){
    std::vector<sf::IntRect> frames;
    sf::IntRect startRect = sf::IntRect(frame.top * frame.width,
                                        frame.top * frame.height,
                                        frame.width,
                                        frame.height);
    frames.push_back(startRect);
    frames.push_back(startRect);
    sf::IntRect endRect = sf::IntRect(frame.top * frame.width + frame.width * (length -1),
                                      (frame.top) * frame.height,
                                      frame.width,
                                      frame.height);
    frames.push_back(endRect);
    return frames;

}

