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

// this is not good programming practice but I'm too lazy to fix it
Handler::~Handler() {
    for(int i = 0; i < gameObjects.size(); i++) {
        delete gameObjects[i];
    }
}

void Handler::notify(char data, char otherData) {
    
    for(int i = 0; i < gameObjects.size(); i++) {
        
        if(gameObjects.at(i)->notify(data, otherData)) {
            gameObjects.at(i) = gameObjects.back();
            gameObjects.pop_back();

        }
        
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
            collision(gameObjects.at(i));
            
        }
        
    }
    
}

void Handler::collision(Entity *entityObject) {
    
    for(int i = 0; i < gameObjects.size(); i++) {
        
        sf::FloatRect object(entityObject->sprite.getGlobalBounds());
        sf::FloatRect object2(gameObjects.at(i)->sprite.getGlobalBounds());
        
        if(object.intersects(object2) && object2 != object && entityObject->getEntityType() != gameObjects.at(i)->getEntityType()) {
            
            otherData |= collidedData;
            
            if(gameObjects.at(i)->notify(0, otherData)) {
                gameObjects.at(i) = gameObjects.back();
                gameObjects.pop_back();
            }
            
            decltype(gameObjects)::iterator it = gameObjects.begin();
            
            it = std::find(gameObjects.begin(), gameObjects.end(), entityObject);
            
            int position = 0;
            
            if(it != gameObjects.end()) {
                position = std::distance(gameObjects.begin(), it);
            }
            if(entityObject->notify(0,  otherData)) {
                gameObjects.at(position) = gameObjects.back();
                gameObjects.pop_back();
                
            }
        }
        
    }
    
}

/*
 void Handler::listen(sf::RenderWindow &window) {
 for(int i = 0; i < listener.size(); i++) {
 
 listener.at(i).listen(window);
 
 }
 }
 */
