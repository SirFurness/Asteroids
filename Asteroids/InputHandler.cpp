//
//  InputHandler.cpp
//  Asteroids
//
//  Created by Eric on 5/24/16.
//  Copyright © 2016 Eric. All rights reserved.
//

#include "InputHandler.hpp"
#include <iostream>

char InputHandler::createData(sf::Event event) {
    
    if(event.type == sf::Event::KeyPressed) {
        data |= pressedData;
        
        switch(event.key.code) {
            case sf::Keyboard::Up:
            case sf::Keyboard::W:
                data |= upData;
                data &= ~upReleased;
                break;
            default:
                break;
        }
        
        switch(event.key.code) {
            case sf::Keyboard::Left:
            case sf::Keyboard::A:
                data |= leftData;
                data &= ~rightData;
                break;
            case sf::Keyboard::Right:
            case sf::Keyboard::D:
                data |= rightData;
                data &= ~leftData;
            default:
                break;
        }
        
        switch(event.key.code) {
            case sf::Keyboard::Space:
                data |= spaceData;
                break;
            default:
                break;
        }
        
    }
    
    if(event.type == sf::Event::KeyReleased) {
        
        data |= releasedData;
        
        switch(event.key.code) {
            case sf::Keyboard::Up:
            case sf::Keyboard::W:
                data |= upReleased;
                data &= ~upData;
                break;
            default:
                break;
        }
        
        switch(event.key.code) {
            case sf::Keyboard::Left:
            case sf::Keyboard::A:
                data &= ~leftData;
                break;
            case sf::Keyboard::Right:
            case sf::Keyboard::D:
                data &= ~rightData;
                break;
            default:
                break;
        }
        
        switch(event.key.code) {
            case sf::Keyboard::Space:
                data &= ~spaceData;
                break;
            default:
                break;
        }
        
    }
    
    
    
    return data;
    
    
}
