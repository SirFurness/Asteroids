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

using namespace sf;
using namespace std;

void Asteroid::init(RenderWindow &window) {
    
    if(!texture.loadFromFile(resourcePath()+"asteroid.png")) {
        cout << "Couldn't load asteroid image!" << endl;
        return EXIT_FAILURE;
    }
    
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    
    
}

void Asteroid::update(RenderWindow &window) {
    
}

void Asteroid::render(RenderWindow &window) {
    window.draw(sprite);
}

bool Asteroid::notify(char data, bool collided) {
    if(collided) {
        return true;
        cout << "hit asteroid like for real" << endl;
    }
    else {
        return false;
    }
}