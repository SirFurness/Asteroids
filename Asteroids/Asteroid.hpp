//
//  Asteroid.hpp
//  Asteroids
//


#ifndef Asteroid_hpp
#define Asteroid_hpp

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

class Asteroid : public Entity {
private:
    
    sf::Texture texture;
    
    std::vector<sf::Texture> textures;
    
    double deltaX = 0, deltaY = 0;
    bool deltaAlreadyMade;
   
    int acceleration = 2;
    
    std::random_device rd;
    
    std::mt19937 mt;
    
    std::uniform_int_distribution<int> dist;
public:
    bool isInvincible = false;
    int splitTimes = 1;
    int maxSplitTimes = 3;
    
    Asteroid(entity_t entityType, entity_state_t entityState) : Entity(x, y, entityType, entityState), mt(rd()), dist(-5, 5), deltaAlreadyMade(false) {x = dist(mt); y = dist(mt);}
    Asteroid(int x, int y, entity_t entityType, entity_state_t entityState) : Entity(x, y, entityType, entityState), mt(rd()), dist(-5, 5), deltaAlreadyMade(false) {}
    Asteroid(int x, int y, double deltaX, double deltaY, entity_t entityType, entity_state_t entityState) : Entity(x, y, entityType, entityState), deltaX(deltaX), deltaY(deltaY), mt(rd()), dist(-5, 5), deltaAlreadyMade(true) {}
    ~Asteroid() {}
    
    void notify(char keyData);
    void init(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    void collision(entity_t type);
    
    void operator=(const Asteroid &asteroid);
    
    void asteroidSplit(std::shared_ptr<Asteroid> &asteroid1, std::shared_ptr<Asteroid> &asteroid2);
    
    void death();
    
};

#endif /* Asteroid_hpp */
