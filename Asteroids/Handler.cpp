//
//  Handler.cpp
//  Asteroids
//
//  Created by Eric Paul on 5/21/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

#include "Handler.hpp"
#include <iostream>

Handler::~Handler() {
    for(int i = 0; i < gameObjects.size(); i++) {
        delete gameObjects[i];
    }
}

void Handler::init(sf::RenderWindow &window) {
    
    for(int i = 0; i < gameObjects.size(); i++) {
        
        gameObjects.at(i)->init(window);
        
    }
    
}

void Handler::render(sf::RenderWindow &window) {
    
    for(int i = 0; i < gameObjects.size(); i++) {
        
        gameObjects.at(i)->render(window);
        
    }
    
}

void Handler::update(sf::RenderWindow &window) {
    
    for(int i = 0; i < gameObjects.size(); i++) {
        
        gameObjects.at(i)->update(window);
        
    }
    
}