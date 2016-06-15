//
//  Asteroid.cpp
//  Asteroids
//
//  Created by Eric on 5/26/16.
//  Copyright © 2016 Eric. All rights reserved.
//

#include "Asteroid.hpp"
#include <iostream>
#include "ResourcePath.hpp"
#include <algorithm>
#include <cmath>
#include <random>

using namespace sf;
using namespace std;

void Asteroid::init(RenderWindow &window) {
    
    acceleration = dist(mt);
    
    if(splitTimes == 1) {
        if(!texture.loadFromFile(resourcePath()+"asteroid.png")) {
            cout << "Couldn't load asteroid image!" << endl;
            return EXIT_FAILURE;
        }
    }
    else {
        if(!texture.loadFromFile(resourcePath()+"asteroidSmall.png")) {
            cout << "Couldn't load asteroidSmall  image!" << endl;
            return EXIT_FAILURE;
        }
    }
    
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    
    if(!deltaAlreadyMade) {
        deltaX = dist(mt);
        deltaY = dist(mt);
    }
    
    while(deltaX == 0) {
        deltaX = dist(mt);
    }
    while(deltaY == 0) {
        
        deltaY = dist(mt);
    }
    
}

void Asteroid::asteroidSplit(std::shared_ptr<Asteroid> &asteroid1, std::shared_ptr<Asteroid> &asteroid2) {
    
    std::shared_ptr<Asteroid> asteroidTemp(new Asteroid(sprite.getPosition().x, sprite.getPosition().y, deltaX, dist(mt), ASTEROID, ALIVE));
    std::shared_ptr<Asteroid> asteroidTemp2(new Asteroid(sprite.getPosition().x, sprite.getPosition().y, deltaX, dist(mt), ASTEROID, ALIVE));
    
    asteroid1 = asteroidTemp;
    asteroid2 = asteroidTemp2;
    
    asteroid1->splitTimes += 1;
    asteroid2->splitTimes += 1;
    
}

void Asteroid::death() {
    entityState = DEAD;
}

void Asteroid::collision(entity_t type) {
    
    if(type == PLAYER && (!isInvincible)) {
        death();
    }
    else if(type == PLAYER_BULLET || type == ENEMY_BULLET) {
        death();
    }
    
}

void Asteroid::operator=(const Asteroid &asteroid) {
    
    x = asteroid.sprite.getPosition().x;
    y = asteroid.sprite.getPosition().y;
    
    // sprite = asteroid.sprite;
    
    deltaX = asteroid.deltaX;
    deltaY = asteroid.deltaY;
    
    isInvincible = asteroid.isInvincible;
    
}

void Asteroid::update(RenderWindow &window) {
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
void Asteroid::render(RenderWindow &window) {
    window.draw(sprite);
}

void Asteroid::notify(char keyData) {
    
    
}