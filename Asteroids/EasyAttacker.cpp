//
//  EasyAttacker.cpp
//  Asteroids
//
//  Created by Eric Paul on 6/1/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

#include "EasyAttacker.hpp"
#include "ResourcePath.hpp"
#include <iostream>
#include <random>

using namespace std;
using namespace sf;

void EasyAttacker::init(sf::RenderWindow &window) {
    
    random_device rd;
    
    mt19937 mt(rd());
    
    uniform_int_distribution<int> dist(-5, 5);
    
    if(!texture.loadFromFile(resourcePath()+"easyAttacker.png")) {
        std::cout << "Failed to load easyAttaker.png!" << std::endl;
        
        return EXIT_FAILURE;
    }
    
    sprite.setTexture(texture);
    sprite.scale(1.8, 1.8);
    sprite.setPosition(x, y);
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    
    deltaX = dist(mt);
    deltaY = dist(mt);
    
}

void EasyAttacker::collision(entity_t type) {
    switch(type) {
        case PLAYER:
        case PLAYER_BULLET:
            //case ASTEROID:
            //case ENEMY_BULLET:
            death();
            break;
        default:
            break;
    }
}

void EasyAttacker::death() {
    entityState = DEAD;
}

bool EasyAttacker::shouldSpawnBullet() {
    
    if(delay == 0) {
        delay = 30;
        return true;
    }
    return false;
    //return shoot.shouldSpawnBullet();
}

void EasyAttacker::notify(char keyData) {
    
}

void EasyAttacker::update(sf::RenderWindow &window) {
    shoot.update();
    
    if(delay > 0) {
        --delay;
    }
    
    sprite.move(deltaX, deltaY);
    
    Vector2f newPos = sprite.getPosition();
    
    if(sprite.getPosition().x > WIDTH) {
        newPos.x = 0;
    }
    else if(sprite.getPosition().x < 0) {
        newPos.x = WIDTH;
    }
    
    if(sprite.getPosition().y > HEIGHT) {
        newPos.y = 0;
    }
    else if(sprite.getPosition().y < 0) {
        newPos.y = HEIGHT;
    }
    
    sprite.setPosition(newPos);
    
}

void EasyAttacker::render(sf::RenderWindow &window) {
    window.draw(sprite);
}

EasyAttacker::~EasyAttacker() {
    
}
