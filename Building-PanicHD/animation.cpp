#include "animation.h"

Animation::Animation(const sf::IntRect &frame, const float &framerate, const int &length)
    : framerate_(framerate), frame_(frame)
{
    frames_.push_back(addAnimation(frame, length));
    this->setTextureRect(frames_[0][0]);
}

Animation::Animation(const sf::IntRect &frame, const float &framerate)
    : framerate_(framerate), frame_(frame)
{
}

std::vector<sf::IntRect> Animation::addAnimation(const sf::IntRect &frame, const int &length)
{
    std::vector<sf::IntRect> frames;
    sf::IntRect startRect = sf::IntRect(frame.top * frame.width,
                                        frame.top * frame.height,
                                        frame.width,
                                        frame.height);
    frames.push_back(startRect);
    frames.push_back(startRect);
    sf::IntRect endRect = sf::IntRect(frame.top * frame.width + frame.width * (length - 1),
                                      (frame.top) * frame.height,
                                      frame.width,
                                      frame.height);
    frames.push_back(endRect);
    startRect.left = frame.width;
    startRect.width = -std::abs(startRect.width);
    frames.push_back(startRect);
    frames.push_back(startRect);
    endRect.width = -std::abs(endRect.width);
    frames.push_back(endRect);
    return frames;
}

void Animation::playAnimation(const float &dt)
{
    timer += dt;
    int startRect;
    if(faceRight){
        startRect = 0;
    }else{
        startRect = 3;
    }
    if (timer > 1 / framerate_)
    {
        timer = 0.f;
        if (frames_[switcher][startRect + 1] != frames_[switcher][startRect + 2])
        {
            frames_[switcher][startRect + 1].left += std::abs(frames_[switcher][startRect].width);
        }
        else
        {
            frames_[switcher][startRect + 1] = frames_[switcher][startRect];
        }
        this->setTextureRect(frames_[switcher][startRect + 1]);
    }
}
