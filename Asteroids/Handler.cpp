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
#include "Asteroid.hpp"
#include "entity_state_t.hpp"

// this is not good programming practice but I'm too lazy to fix it right now
Handler::~Handler() {
    for(int i = 0; i < gameObjects.size(); i++) {
        delete gameObjects[i];
    }
}

void Handler::notify(char data) {
    
    for(int i = 0; i < gameObjects.size(); i++) {
        
        gameObjects.at(i)->notify(data);
        
    }
    
}

void Handler::init(sf::RenderWindow &window) {
    
    for(int i = 0; i < gameObjects.size(); i++) {
        
        gameObjects.at(i)->init(window);
        
    }
    
}

void Handler::render(sf::RenderWindow &window, game_state_t gameState) {
    
    if(gameState == PLAYING) {
        
        for(int i = 0; i < gameObjects.size(); i++) {
            
            gameObjects.at(i)->render(window);
            
        }
    }
    
}

void Handler::update(sf::RenderWindow &window, game_state_t gameState) {
    
    if(gameState == PLAYING) {
        
        for(int i = 0; i < gameObjects.size(); i++) {
            
            gameObjects.at(i)->update(window);
            
        }
        
    }
    
}

void Handler::cleanUp() {
    
    decltype(gameObjects.begin()) it;
    
    for(it = gameObjects.begin(); it != gameObjects.end(); it++) {
        if((*it)->getEntityState() == DEAD) {
            it = gameObjects.erase(it);
            it--;
        }
    }
    
}

void Handler::collision() {
    
    for(int i = 0; i < gameObjects.size(); i++) {
        
        for(int j = 0; j < gameObjects.size(); j++) {

            
            Entity *entityObject = gameObjects[i];
            Entity *entityObject2 = gameObjects[j];
            
            sf::IntRect object(entityObject->sprite.getGlobalBounds());
            sf::IntRect object2(entityObject2->sprite.getGlobalBounds());
            
            
            if(object.intersects(object2) && entityObject != entityObject2) {
                
                entityObject->collision(entityObject2->getEntityType());
                entityObject2->collision(entityObject->getEntityType());
                
            }
            
        }
        
    }
    
}
