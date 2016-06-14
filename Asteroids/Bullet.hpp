//
//  Bullet.hpp
//  Asteroids
//
//  Created by Eric on 5/28/16.
//  Copyright © 2016 Eric. All rights reserved.
//

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include "entity_t.hpp"
#include <iostream>

#ifndef Bullet_hpp
#define Bullet_hpp

class Bullet : public Entity {
    
    double rotation, deltaX, deltaY;
    
    double speed = 3;
    
    int frameLife = 60, framesPassed = 0;
    
    double degreesToRadians(double degrees);
    
    bool makeRotationRandom = false;
    
    sf::Texture texture;
    
public:
    
    Bullet(int x, int y, entity_t entityType, entity_state_t entityState, double rotation) : Entity(x, y, entityType, entityState), rotation(rotation) {}
    Bullet(int x, int y, entity_t entityType, entity_state_t entityState) : Entity(x, y, entityType, entityState) {makeRotationRandom = true;}
    ~Bullet();
    
    void shouldDie();
    
    void notify(char keyData);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    void init(sf::RenderWindow &window);
    void collision(entity_t type);
    
    void death();
    
};

#endif /* Bullet_hpp */
