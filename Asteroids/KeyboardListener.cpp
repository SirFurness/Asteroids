//
//  InputListener.cpp
//  Asteroids
//
//  Created by Eric Paul on 5/23/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

#include "KeyboardListener.hpp"

bool KeyboardListener::listen(sf::RenderWindow &window) {
    
    sf::Event event;
    
    while(window.pollEvent(event)) {
        
        if(event.type == sf::Event::KeyPressed) {
            
            return true;
            
        }
        
    }
    
}
