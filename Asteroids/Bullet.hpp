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

#ifndef Bullet_hpp
#define Bullet_hpp

class Bullet : public Entity {
    
    const int WIDTH = 800, HEIGHT = 600;
    
    double rotation, deltaX, deltaY;
    
    double speed = 3;
    
    int frameLife = 1*(60), framesPassed = 0;
    
    double degreesToRadians(double degrees);
    
    sf::Texture texture;
    
public:
    
    Bullet(int x, int y, entity_t entityType, entity_state_t entityState, double rotation) : Entity(x, y, entityType, entityState), rotation(rotation) {}
    ~Bullet();
    
    void shouldDie();
    
    bool shouldSpawnBullet(double &rotation);
    
    void notify(char keyData);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    void init(sf::RenderWindow &window);
    void collision(entity_t type);
    
    bool isFlickering();
    
    void death();
    
};

#endif /* Bullet_hpp */
