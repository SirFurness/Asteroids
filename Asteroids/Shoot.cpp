//
//  Shoot.cpp
//  Asteroids


#include "Shoot.hpp"

void Shoot::update() {
    
    if(shootDelayLeft > 0) {
        --shootDelayLeft;
    }
    else if(shootDelayLeft <= 0) {
        spawnBullet = true;
    }
    
}

bool Shoot::shouldSpawnBullet() {
    
    shootDelayLeft = spawnBullet ? shootDelay : shootDelayLeft;
    
    bool returnValue = spawnBullet;
    
    spawnBullet = false;
    
    return returnValue;
    
    
}
