//
//  Player.hpp
//  Asteroids


#include "Entity.hpp"
#include "Shoot.hpp"
#include "Animation.hpp"

#ifndef Player_hpp
#define Player_hpp

class Player : public Entity {
private:
    
    double acceleration = 0.3, rotation = 0, deltaX, deltaY, friction = 0.98, maxSpeed = 15;

    unsigned char keyData = 0, upData = 1<<7, spaceData = 1<<6, leftData = 1<<5, rightData = 1<<4, pressedData = 1<<3, releasedData = 1<<2, upReleased = 1<<1;
    
    unsigned char otherData = 0, isInvincible = 1<<7, collidedData = 1<<6;
    
    sf::Texture texture, moveTexture;
    
    // converts degrees to radians so that sin and cos function can be used more easily
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
    int flickerLengthInv = 2;
    
    //says whether spriteflickering is active so that game knows not to take damage
    bool isFlickeringInv = true;
    
    // these do the exact same thing as the variables above except for the accerleration image and not the player
    bool everyotherMove = false, flickerSpeedMove = 2, isFlickeringMove = true, drawMove = false;
    int framesPassedMove = 20;
    
    bool movingUp = false;
    
    bool spawnBullet = false;
    
    void collided();
    
    void movementFrames();

    void invincibilityFrames();
    
    Shoot shoot;
    
    void drawHealth(sf::RenderWindow &window);
    sf::Sprite healthSprite;
    
    //Animation animation;
    
public:
    
    int health;
    
    Player(int x, int y, int health, entity_t entityType, entity_state_t entityState) : Entity(x, y, entityType, entityState), health(health), shoot(30) {}
    ~Player() {}
    
    void init(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    void collision(entity_t type);
    
    
    bool isFlickering();
    
    void death();
    
    bool shouldSpawnBullet(double &rotation);
    
    void move(sf::RenderWindow &window);
    
    void notify(char keyData);
};

#endif /* Player_hpp */
