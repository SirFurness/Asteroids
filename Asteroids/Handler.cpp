//
//  Handler.cpp
//  Asteroids
//
//  Created by Eric Paul on 5/21/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

#include "Handler.hpp"
#include <iostream>
#include <vector>

Handler::~Handler() {
    for(int i = 0; i < gameObjects.size(); i++) {
        delete gameObjects[i];
    }
}

void Handler::notify(char data, bool collided) {
    
    for(int i = 0; i < gameObjects.size(); i++) {
        
        gameObjects.at(i)->notify(data, collided);
        
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
        
        collision(gameObjects.at(i));
        gameObjects.at(i)->update(window);
        
    }
    
}

void Handler::collision(Entity *entityObject) {
    
    std::vector<int> erase;
    
    for(int i = 0; i < gameObjects.size(); i++) {
        
        sf::FloatRect object(entityObject->sprite.getGlobalBounds());
        sf::FloatRect object2(gameObjects.at(i)->sprite.getGlobalBounds());
        
        if(object.intersects(object2) && object2 != object) {
            
            if(entityObject->notify(0,  true)) {
                erase.push_back(i);
            }
            gameObjects.at(i)->notify(0, true);
            
        }
        
    }
    
    
    for(int i = 0; i < erase.size(); i++) {
        gameObjects.erase((gameObjects.begin()+erase.at(i))-1);
    }
    
}

/*
void Handler::listen(sf::RenderWindow &window) {
    for(int i = 0; i < listener.size(); i++) {
        
        listener.at(i).listen(window);
        
    }
}
*/
