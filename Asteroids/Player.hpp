//
//  Player.hpp
//  Asteroids
//
//  Created by Eric Paul on 5/21/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

#include "Entity.hpp"

#ifndef Player_hpp
#define Player_hpp

class Player : public Entity {
private:
    
    const int WIDTH = 800, HEIGHT = 600;
    
    double acceleration = 0.3, rotation = 0, deltaX, deltaY, friction = 0.98, maxSpeed = 15;
    
    int health;
    unsigned char data = 0, upData = 1<<7, downData = 1<<6, leftData = 1<<5, rightData = 1<<4, pressedData = 1<<3, releasedData = 1<<2, upReleased = 1<<1;
    
    sf::Texture texture;
    
    double degreesToRadians(double degrees);
    
    void collided();
    
public:
    Player(int x, int y, int health) : Entity(x, y), health(health) {}
    
    
    void init(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    
    void death();
    
    void move(sf::RenderWindow &window);
    //void followMouse(sf::RenderWindow &window);
    
    //double getRotation(sf::RenderWindow &window);
    
    bool notify(char data, bool collided);
};

#endif /* Player_hpp */
