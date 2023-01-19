#ifndef ENTITY_CPP
#define ENTITY_CPP

// Version mit Klassen in hpp und cpp unterteilt (mit World-Einbindung)
// & verschiedenen Enemytypen (funktionstüchtig) ~Version vom 16.01.23
// damaged wurde geändert und gibt jetzt zurück, ob das Entity gestorben ist (died wurde gelöscht)

#include "../includes/Entity.hpp"
#include <iostream>
Entity::Entity(){
	hp = 1;
	damage = 0;
    world = nullptr;
}

//Konstruktor für Spieler
Entity::Entity(int hp, int damage) : Image(){
    this->hp = hp;
    this->damage = damage;
    this->world = nullptr;
}

//Kontrktor für Enemy
Entity::Entity(World *world) : Image(){
    this->hp = 0;
    this->damage = 0;
    this->world = world;
}

// Getter

int Entity::getHp(){
    return hp;
}

int Entity::getDamage(){
    return damage;
}

// Setter

void Entity::setHP(int newHp){
    if (newHp <= 0){
        std::cout << "Unzulässige HP für Entity";
    }

    else{
        hp = newHp;
    }
}

void Entity::setDamage(int newDmg){
    if (newDmg <= 0){
        std::cout << "Unzulässiger Schaden für Entity";
    }

    else{
        damage = newDmg;
    }
}

//Funktinoen

bool Entity::damaged(int damage){
    if (damage < hp){
        hp -= damage;
        return false;
    }
    else{
        return true;
    }
}

bool Entity::moveIsLegal(int x, int y){
    if(world != nullptr and world->isWalkable(x / world->getBlockSize(), y / world->getBlockSize())){
        return true;
    }
    return false;
}

void Entity::setKoord(int x, int y){
    this->moveTo(x,y);
}

#endif
