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
    unsigned char keyData = 0, upData = 1<<7, downData = 1<<6, leftData = 1<<5, rightData = 1<<4, pressedData = 1<<3, releasedData = 1<<2, upReleased = 1<<1;
    
    unsigned char otherData = 0, isInvincible = 1<<7, collidedData = 1<<6;
    
    sf::Texture texture, moveTexture;
    
    double degreesToRadians(double degrees);
    
    /*this counts the frames that have passed since the invisiblity frames started. once it reaches a certain number it stops
     to start invicbility frames again don't call the function just set this framesPassed to 0;
     */
    int framesPassedInv = 0;
    
    //should draw the sprite. this is here so that sprite flickering can happen during invincibility frames
    bool draw = true;
    
    //keeps track of it being everyother frame for invinciblity frames
    bool everyotherInv = false;
    
    //makes it so that to move forward after dying the player has to release the key and then press it down again
    bool waitUntilReleased = false;
    
    //speed that ship flickers at
    int flickerSpeedInv = 4;
    
    //length in seconds that the sprite flickering should last
    int flickerLengthInv = 1;
    
    //says whether spriteflickering is active so that game knows not to take damage
    bool isFlickeringInv = true;
    
    bool everyotherMove = false, flickerSpeedMove = 2, isFlickeringMove = true, drawMove = false;
    int framesPassedMove = 0;
    
    bool movingUp = false;
    
    void collided();
    
    void movementFrames();
    
    void invincibilityFrames();
    
public:
    Player(int x, int y, int health) : Entity(x, y), health(health) {}
    
    void init(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    
    void death();
    
    void move(sf::RenderWindow &window);
    //void followMouse(sf::RenderWindow &window);
    
    //double getRotation(sf::RenderWindow &window);
    
    bool notify(char keyData, char &otherData);
};

#endif /* Player_hpp */
