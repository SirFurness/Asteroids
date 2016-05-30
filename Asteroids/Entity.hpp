//
//  Entity.hpp
//  Asteroids
//
//  Created by Eric Paul on 5/21/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp


#include <SFML/Graphics.hpp>
#include <vector>
#include "entity_t.hpp"
#include "entity_state_t.hpp"

class Entity {
protected:
    
    int x, y;
    //int width, height;
    
    entity_t entityType;
    
    entity_state_t entityState;
    
    void death();
    
public:
    
    sf::Sprite sprite;
    
    virtual void init(sf::RenderWindow &window) = 0;
    virtual void update(sf::RenderWindow &window) = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    
    virtual void notify(char keyData) = 0;
    
    virtual void collision(entity_t type) = 0;
    
    virtual ~Entity() {};
    
    int getX() {return x;}
    int getY() {return y;}
    //int getHeight() {return height;}
    //int getWidth() {return width;}
    
    void setX(int x) {this->x = x;}
    void setY(int y) {this->x = y;}
    //void setHeight(int height) {this->x = height;}
    //void setWidth(int width) {this->x = width;}
    
    void setEntityType(entity_t entityType) {this->entityType = entityType;}
    entity_t getEntityType() {return entityType;}
    
    void setEntityState(entity_state_t entityState) {this->entityState = entityState;}
    entity_state_t getEntityState() {return entityState;}
    
    Entity(int x, int y, entity_t entityType, entity_state_t entityState) : x(x), y(y), entityType(entityType), entityState(entityState) {}
    
};

#endif /* Entity_hpp */
