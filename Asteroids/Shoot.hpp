//
//  Shoot.hpp
//  Asteroids


#ifndef Shoot_hpp
#define Shoot_hpp

class Shoot {
private:
    int shootDelayLeft = 0;
    int shootDelay = 30;
    bool spawnBullet = true;
public:
    
    Shoot(int shootDelay) : shootDelay(shootDelay) {}
    
    bool shouldSpawnBullet();
    
    void update();
    
    
};

#endif /* Shoot_hpp */
