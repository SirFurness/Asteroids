//
//  Animation.hpp
//  Asteroids
//
//  Created by Eric Paul on 6/14/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

#ifndef Animation_hpp
#define Animation_hpp

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

class Animation {
    
private:
    
    std::vector<sf::Sprite> frames;
    
    int currentFrame = 0, totalFrames = 0;
    
    int ticksPerFrame;
    
public:
    
    void startAnimation(const std::vector<sf::Sprite> &, int );
    void startAnimation(const std::vector<sf::Sprite> &, int , int );
    
    sf::Sprite animate();
    
    sf::Sprite getCurrentFrame();
    
    bool isAnimationDone();
    
    std::vector<sf::Sprite> getFrames(const sf::Sprite&, int, int, int, int);
    sf::Sprite loadImage(const std::string &filepath) {
        
        sf::Texture image;
        
        if(!image.loadFromFile(filepath)) {
            std::cout << "Failed to load image!" << std::endl;
            throw std::exception();
        }
        
        sf::Sprite sprite;
        sprite.setTexture(image);
        
        return sprite;
        
    }
    
};

#endif /* Animation_hpp */
