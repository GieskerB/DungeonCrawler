#ifndef ENEMY_CPP
#define ENEMY_CPP

// Version mit Klassen in hpp und cpp unterteilt (mit World-Einbindung)
// & verschiedenen Enemytypen (funktionstüchtig) ~Version vom 16.01.23

#include "../includes/Enemy.hpp"

Enemy::Enemy(){}

/*
Enemy::Enemy(World *world, int x, int y, int level) : Entity(1, 1, world, "pics/entity/enemy/stray.png", x, y){
    this->hp = 5 * level;
    this->damage = 5 * level;
    this->setSize(world->getBlockSize() * 0.8, world->getBlockSize() * 0.8);
}
*/

Enemy::Enemy(int level, World *world) : Entity(world){
    //1:1 aus dem Image-Konstruktor genommen
    this->x = 50;
    this->y = 50;
    this->w = 8;
    this->h = 8;

    pickEnemyType(level, (rand() % 4)); // Der Typ wird random gewählt

    // Funktionen aus Image, die im Konstruktor aufgerufen wird
    this->id = world->addElement(this);
    this->svg = world;
    this->create(); 

    this->setAttribute("image-rendering", "pixelated");
    this->setSize(world->getBlockSize() * 0.8, world->getBlockSize() * 0.8);
}

Enemy::Enemy(int level, World *world, int x, int y) : Entity(world){
    //1:1 aus dem Image-Konstruktor genommen
    this->x = x;
    this->y = y;
    this->w = 8;
    this->h = 8;
    
    pickEnemyType(level, (rand() % 4)); // Der Typ wird random gewählt

    // Funktion aus Image, die im Konstruktor aufgerufen wird
    this->id = world->addElement(this);
    this->svg = world;
    this->create();
    
    this->setAttribute("image-rendering", "pixelated");  
    this->setSize(world->getBlockSize() * 0.8, world->getBlockSize() * 0.8);
}

// Funktionen

void Enemy::move(){
    int xPos = this->getX();
    int yPos = this->getY();
    int newX, newY;
    do{
        newX = xPos + (rand() % 2) - 1;
        newY  = yPos + (rand() % 2) - 1;          
    } while (!moveIsLegal(newX, newY));
        
    this->moveTo(newX, newY);
}

void Enemy::pickEnemyType(int level, int enemyNo){
    // path ist aus Image und wird im Konstruktor gesetzt
    
    switch (enemyNo){ 
    case 1:  // Zombie
        this->hp = level * 3;
        this->damage = level * 1;
        this->path = "pics/entity/enemy/zombie.png";
        break;
    case 2: // Creeper
        this->hp = level * 4;
        this->damage = level * 2;
        this->path = "pics/entity/enemy/creeper.png";
        break;
    case 3: // Skeleton
        this->hp = level * 4;
        this->damage = level * 3;
        this->path = "pics/entity/enemy/skeleton.png";
        break;
    case 4: // Stray
        this->hp = level * 5;
        this->damage = level * 3;
        this->path = "pics/entity/enemy/stray.png";
        break;    
    default:
        this->hp = level * 3;
        this->damage = level * 1;
        this->path = "pics/entity/enemy/husk.png";
        break;
    }
}

#endif