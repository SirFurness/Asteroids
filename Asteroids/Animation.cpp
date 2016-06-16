//
//  Animation.cpp
//  Asteroids
//
//  Created by Eric Paul on 6/14/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

#include "Animation.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

void Animation::startAnimation(const std::vector<sf::Sprite> &frames, int seconds) {
    
    this->frames = frames;
    this->ticksPerFrame = seconds * 60;
    totalFrames = frames.size();
    
}

void Animation::startAnimation(const std::vector<sf::Sprite> &frames, int seconds, int currentFrame) {
    
    this->frames = frames;
    this->ticksPerFrame = seconds * 60;
    this->currentFrame = currentFrame;
    
}

bool Animation::isAnimationDone() {
    return (currentFrame == totalFrames ? true : false);
}

sf::Sprite Animation::animate() {
    
    return frames[currentFrame];
    
    currentFrame+= 1;
}

std::vector<sf::Sprite> Animation::getFrames(const sf::Sprite &texture, int rows, int columns, int imageWidth, int imageHeight) {
    
    std::vector<sf::Sprite> returnSprites;
    
    const int width = imageWidth / columns;
    const int height = imageHeight / rows;
    
    for(int i = 1; i <= rows*columns; i++) {
    
        sf::IntRect sourceRect(i*width, i*height, width, height);
        
        sf::Sprite sprite(*texture.getTexture(), sourceRect);
        
        returnSprites.push_back(sprite);
        
        
    }
    
    return returnSprites;
    
}