//
//  Handler.cpp
//  Asteroids
//
//  Created by Eric on 5/21/16.
//  Copyright © 2016 Eric. All rights reserved.
//

#include "Handler.hpp"
#include <iostream>
#include <vector>
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "entity_state_t.hpp"
#include "Player.hpp"
#include <memory>

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
        
        for(int i = 0; i < toBeAdded.size(); i++) {
            gameObjects.push_back(toBeAdded.at(i));
        }
        
        toBeAdded.clear();
        
        for(int i = 0; i < gameObjects.size(); i++) {
            
            
            gameObjects.at(i)->update(window);
            switch(gameObjects.at(i)->getEntityType()) {
                case PLAYER:
                    playerSpecifics(std::static_pointer_cast<Player>(gameObjects.at(i)), window);
                    break;
                case EASY_ATTACKER:
                    easyAttackerSpecifics(std::static_pointer_cast<EasyAttacker>(gameObjects.at(i)), window);
                    break;
                case ASTEROID:
                    asteroidSpecifics(std::static_pointer_cast<Asteroid>(gameObjects.at(i)), window);
                    break;
                default:
                    break;
            }
            
            
        }
        
    }
    
}

void Handler::cleanUp(sf::RenderWindow &window, game_state_t gameState) {
    
    decltype(gameObjects.begin()) it;
    
    for(it = gameObjects.begin(); it != gameObjects.end(); it++) {
        if((*it)->getEntityState() == DEAD) {
            
            switch((*it)->getEntityType()) {
                case ASTEROID:
                    splitAsteroid(std::static_pointer_cast<Asteroid>(*it), window);
                    break;
                case PLAYER:
                    gameState = LOSE;
                    break;
                default:
                    break;
            }
            
            
            it = gameObjects.erase(it);
            it--;
        }
    }
    
}

void Handler::splitAsteroid(std::shared_ptr<Asteroid> asteroid, sf::RenderWindow &window) {
    
    if(asteroid->splitTimes < 2) {
        
        std::shared_ptr<Asteroid> asteroid1, asteroid2;
        asteroid->asteroidSplit(asteroid1, asteroid2);
        
        asteroid1->init(window);
        asteroid2->init(window);
        
        toBeAdded.push_back(std::static_pointer_cast<Entity>(asteroid1));
        toBeAdded.push_back(std::static_pointer_cast<Entity>(asteroid2));
    }
    
}

void Handler::asteroidSpecifics(std::shared_ptr<Asteroid> asteroid, sf::RenderWindow &window) {
    
    for(int i = 0; i < gameObjects.size(); i++) {
        
        if(gameObjects.at(i)->getEntityType() == PLAYER) {
            
            std::shared_ptr<Player> player(std::static_pointer_cast<Player>(gameObjects.at(i)));
            
            asteroid->isInvincible = player->isFlickering();
            
        }
        
    }
    
}

void Handler::easyAttackerSpecifics(std::shared_ptr<EasyAttacker> easyAttacker, sf::RenderWindow &window) {
    
    if(easyAttacker->shouldSpawnBullet()) {
        std::shared_ptr<Bullet> bullet(new Bullet(easyAttacker->sprite.getPosition().x, easyAttacker->sprite.getPosition().y, ENEMY_BULLET, ALIVE));
        bullet->init(window);
        gameObjects.push_back(bullet);
    }
    
    
}

void Handler::playerSpecifics(std::shared_ptr<Player> player, sf::RenderWindow &window) {
    
    double rotation = 0.0;
    
    if(player->shouldSpawnBullet(rotation)) {
        std::shared_ptr<Bullet> bullet(new Bullet(player->sprite.getPosition().x, player->sprite.getPosition().y, PLAYER_BULLET, ALIVE, rotation));
        bullet->init(window);
        gameObjects.push_back(bullet);
    }
    
}

bool Handler::isCollidingWithInvinciblePlayer(std::shared_ptr<Entity> entityObject, std::shared_ptr<Entity> entityObject2) {
    
    if(entityObject->getEntityType() == PLAYER) {
        if((std::static_pointer_cast<Player>(entityObject))->isFlickering()) {
            return true;
        }
    }
    else if(entityObject->getEntityType() == PLAYER) {
        if((std::static_pointer_cast<Player>(entityObject2))->isFlickering()) {
            return true;
        }
    }
    
    return false;
    
}

void Handler::collision(sf::RenderWindow &window) {
    
    for(int i = 0; i < gameObjects.size(); i++) {
        
        for(int j = 0; j < gameObjects.size(); j++) {
            
            
            auto entityObject = gameObjects[i];
            auto entityObject2 = gameObjects[j];
            
            sf::IntRect object(entityObject->sprite.getGlobalBounds());
            sf::IntRect object2(entityObject2->sprite.getGlobalBounds());
            
            
            if(object.intersects(object2) && entityObject != entityObject2) {
                
                if(!(isCollidingWithInvinciblePlayer(entityObject, entityObject2))) {
                    entityObject->collision(entityObject2->getEntityType());
                    entityObject2->collision(entityObject->getEntityType());
                }
            }
            
        }
        
    }
    
}
