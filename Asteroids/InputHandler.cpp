//
//  InputHandler.cpp
//  Asteroids
//
//  Created by Eric on 5/24/16.
//  Copyright © 2016 Eric. All rights reserved.
//

#include "InputHandler.hpp"
#include <iostream>
#include "game_state_t.hpp"
#include <map>

char InputHandler::createData(sf::Event event, game_state_t gameState) {
    
    if(gameState == PLAYING) {
        
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
    }
    
    else if(gameState == MENU) {
        
        switch (event.key.code) {
            case sf::Keyboard::Y:
                data |= yData;
                break;
            default:
                data = 0;
                break;
        }
        
    }
    
    return data;
}
