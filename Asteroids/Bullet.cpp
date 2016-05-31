//
//  Bullet.cpp
//  Asteroids
//
//  Created by Eric on 5/28/16.
//  Copyright © 2016 Eric. All rights reserved.
//

#include "Bullet.hpp"
#include "ResourcePath.hpp"
#include <iostream>

void Bullet::init(sf::RenderWindow &window) {
    
    if(!(texture.loadFromFile(resourcePath()+"Bullet.png"))) {
        
        std::cout << "Failed to load \"Bullet.png\"!" << std::endl;
        return EXIT_FAILURE;
        
    }
    
    texture.setSmooth(true);
    
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    sprite.setScale(2, 2);
    
}

void Bullet::update(sf::RenderWindow &window) {
    sprite.move(1, 1);
}

void Bullet::render(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Bullet::collision(entity_t type) {
    
}

void Bullet::notify(char keyData) {
    
}

void Bullet::death() {
    
}