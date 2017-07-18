//
//  EasyAttacker.hpp
//  Asteroids


#ifndef EasyAttacker_hpp
#define EasyAttacker_hpp

#include "Entity.hpp"
#include "Shoot.hpp"

class EasyAttacker : public Entity{
private:
    sf::Texture texture;
    
    double deltaX = 0, deltaY = 0;
    
    int acceleration = 2;
    
    bool spawnBullet = true;
    
    int delay = 30;
    
    Shoot shoot;
    
    
public:
    
    EasyAttacker(int x, int y, entity_t entityType, entity_state_t entityState) : Entity(x, y, entityType, entityState), shoot(30) {}
    ~EasyAttacker();
    
    void notify(char keyData);
    
    void init(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    
    bool shouldSpawnBullet();
    
    void collision(entity_t type);
    
    void death();
    
};

#endif /* EasyAttacker_hpp */
