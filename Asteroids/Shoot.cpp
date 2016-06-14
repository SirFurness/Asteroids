//
//  Shoot.cpp
//  Asteroids
//
//  Created by Eric Paul on 6/11/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

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