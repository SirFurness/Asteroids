//
//  Asteroid.hpp
//  Asteroids
//
//  Created by Eric on 5/26/16.
//  Copyright © 2016 Eric. All rights reserved.
//

#ifndef Asteroid_hpp
#define Asteroid_hpp

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include "Handler.hpp"

class Asteroid : public Entity {
private:
    const int WIDTH = 800, HEIGHT = 600;
    
    sf::Texture texture;
    
    double deltaX = 0, deltaY = 0;
   
    int acceleration = 2;
    
    unsigned isInvincible = 1<<7, collidedData = 1<<6;
public:
    
    Asteroid(int x, int y, entity_t entityType, entity_state_t entityState) : Entity(x, y, entityType, entityState) {}
    ~Asteroid() {}
    
    void notify(char keyData);
    void init(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    void collision(entity_t type);
    
    bool shouldSpawnBullet(double &rotation);
    
    bool isFlickering();
    
    void death();
    
};

#endif /* Asteroid_hpp */
