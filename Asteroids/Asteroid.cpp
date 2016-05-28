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

using namespace sf;
using namespace std;

void Asteroid::init(RenderWindow &window) {
    
    srand((double) time(0));
    
    acceleration = rand() % 5 + 1;
    
    if(!texture.loadFromFile(resourcePath()+"asteroid.png")) {
        cout << "Couldn't load asteroid image!" << endl;
        return EXIT_FAILURE;
    }
    
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    
    double rotation = rand() % 100 +1;
    
    deltaX = sin(3.14159625*rotation/189)*acceleration;
    deltaY = cos(3.14159625*rotation/189)*acceleration;
    
    
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

bool Asteroid::notify(char keyData, char &otherData) {
    
    bool shouldKill = true;
    
    if((otherData & isInvincible) == isInvincible) {
        return false;
    }
    
    if((otherData & collidedData) == collidedData && shouldKill == true) {
        return true;
    }
    
    return false;
    
}