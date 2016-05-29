//
//  Asteroid.cpp
//  Asteroids
//
//  Created by Eric Paul on 5/26/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
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
    
    random_device rd;
    
    mt19937 mt(rd());
    
    uniform_int_distribution<int> dist(-5, 5);
    
    acceleration = dist(mt);
    
    // loads the asteroid image
    if(!texture.loadFromFile(resourcePath()+"asteroid.png")) {
        cout << "Couldn't load asteroid image!" << endl;
        return EXIT_FAILURE;
    }
    
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    
    deltaX = dist(mt);
    deltaY = dist(mt);
    
    
}

// just moves the asteroid and makes it wrap around
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

bool Asteroid::notify(char keyData, char &otherData) {
    bool shouldKill = true;
    
    if((otherData & isInvincible) == isInvincible) {
        shouldKill = false;
    }
    
    if((otherData & collidedData) == collidedData && shouldKill == true) {
        // this means the asteroid will be destroyed
        return true;
    }
    
    // this means that the asteroid should not be destroyed
    return false;
    
}