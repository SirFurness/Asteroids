//
//  Player.cpp
//  Asteroids
//
//  Created by Eric on 5/21/16.
//  Copyright © 2016 Eric. All rights reserved.
//

#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include <cmath>
#include "Shoot.hpp"

using namespace sf;
using namespace std;

void Player::init(RenderWindow &window) {
    
    health = 3;
    entityState = ALIVE;
    
    if(!texture.loadFromFile(resourcePath()+"asteroidShip.png")) {
        std::cout << "Couldn't load ship texture!" << std::endl;
        return EXIT_FAILURE;
    }
    
    texture.setSmooth(true);
    
    if(!moveTexture.loadFromFile(resourcePath()+"asteroidShipMoving.png")) {
        std::cout << "Couldn't load moving ship texture!" << std::endl;
        return EXIT_FAILURE;
    }
    
    moveTexture.setSmooth(true);
    
    //sprite.setScale(1.6, 1.6);
    sprite.setTexture(texture);
    sprite.setPosition(WIDTH/2, HEIGHT/2);
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    
    
    healthSprite.setTexture(texture);
    healthSprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    
    //animation.startAnimation(animation.getFrames(animation.loadImage(resourcePath()+"explosion.png"), 5, 8, 500, 800), 0.1);
}

void Player::notify(char keyData) {
    
    
    if(!(keyData == 0)) {
        this->keyData = keyData;
    }
    
}

void Player::collision(entity_t type) {
    
    switch(type) {
        case EASY_ATTACKER:
        case ENEMY_BULLET:
        case ASTEROID:
            if(!isFlickering()) {
                death();
            }
            break;
        default:
            break;
    }
    
}

void Player::drawHealth(RenderWindow &window) {
    
    for(int i = 0; i < health; i++) {
        
        healthSprite.setPosition(20*(i+1), 20);
        window.draw(healthSprite);
        
    }
    
}

void Player::render(RenderWindow &window) {
    
    invincibilityFrames();
    
    movementFrames();
    
    if(draw)
        window.draw(sprite);
    
    drawHealth(window);
    
}

void Player::invincibilityFrames() {
    
    if(!(framesPassedInv >= (60*flickerLengthInv))) {
        isFlickeringInv = true;
        
        framesPassedInv += 1;
        
        if((framesPassedInv%flickerSpeedInv)==0) {
            everyotherInv = !everyotherInv;
        }
        
        if(everyotherInv) {
            draw = true;
        }
        else {
            draw = false;
        }
    }
    else {
        isFlickeringInv = false;
        draw = true;
    }
    
}

void Player::movementFrames() {
    isFlickeringMove = true;
    
    framesPassedMove += 1;
    
    if((framesPassedMove%flickerSpeedMove) == 0) {
        everyotherMove = !everyotherMove;
    }
    
    if(everyotherMove && movingUp) {
        drawMove = true;
    }
    else {
        drawMove = false;
    }
    
    if(waitUntilReleased) {
        drawMove = false;
    }
    
    if(drawMove) {
        sprite.setTexture(moveTexture);
    }
    else {
        sprite.setTexture(texture);
    }
    
    
}

void Player::move(RenderWindow &window) {
    
    shoot.update();
    
    if(!waitUntilReleased) {
        if((keyData & upData) == upData) {
            
            double movementX = (sin(degreesToRadians(sprite.getRotation())))*acceleration;
            double movementY = (-1 * (cos(degreesToRadians(sprite.getRotation()))))*acceleration;
            
            deltaX += movementX;
            deltaY += movementY;
            
            if((deltaX/movementX) > maxSpeed) {
                deltaX = maxSpeed*movementX;
            }
            
            if((deltaY/movementY) > maxSpeed) {
                deltaY = maxSpeed*movementY;
            }
            
            movingUp = true;
            
            
        }
        else {
            deltaX *= friction;
            deltaY *= friction;
            movingUp = false;
            isFlickeringMove = false;
            
        }
        
    }
    else if((keyData & upReleased) == upReleased) {
        waitUntilReleased = false;
    }
    
    if((keyData & leftData) == leftData) {
        
        sprite.rotate(-5);
        
    }
    else if((keyData & rightData) == rightData) {
        sprite.rotate(5);
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
    
    if(((keyData & spaceData) == spaceData) && shoot.shouldSpawnBullet()) {
        spawnBullet = true;
    }
    else {
        spawnBullet = false;
    }
    
}

void Player::update(RenderWindow &window) {
    
    move(window);
    
}

bool Player::shouldSpawnBullet(double &changeRotation) {
    
    
    changeRotation = sprite.getRotation();
    
    return spawnBullet;
    
    
}

double Player::degreesToRadians(double degrees) {
    return (3.14159625*degrees/189);
}

void Player::death() {
    
    if(!isFlickering()) {
        health -= 1;
    }
    
    if(health <= 0) {
        entityState = DEAD;
    }
    else {
        sprite.setPosition(WIDTH/2, HEIGHT/2);
        
        deltaX = 0;
        deltaY = 0;
        
        waitUntilReleased = true;
        
        framesPassedInv = 0;
    }
}

bool Player::isFlickering() {
    return isFlickeringInv;
}

/*
 void Player::followMouse(RenderWindow &window) {
 
 
 double hypotenuse = sqrt(pow((player.getGlobalBounds().left-sf::Mouse::getPosition(window).x), 2)+pow((player.getGlobalBounds().top-sf::Mouse::getPosition().y),2));
 
 double height = ((player.getGlobalBounds().top) - (sf::Mouse::getPosition(window).y));
 
 double length = ((player.getGlobalBounds().left)-(sf::Mouse::getPosition(window).y));
 
 double angle = asin(height)*180/3.14159;
 
 
 double deltaY = player.getGlobalBounds().top - sf::Mouse::getPosition(window).y;
 
 double deltaX = player.getGlobalBounds().left - sf::Mouse::getPosition(window).x;
 
 double angle = (atan2(deltaY, deltaX)*180/3.14159)-110;
 
 player.setRotation(angle);
 
 
 }
 */