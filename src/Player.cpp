#ifndef PLAYER_CPP
#define PLAYER_CPP

// Version mit Klassen in hpp und cpp unterteilt (mit World-Einbindung)
// & verschiedenen Enemytypen (funktionstüchtig) ~Version vom 16.01.23

#include "../includes/Player.hpp"
const string defaultskin = "../pics/entity/player/steve.png";

Player::Player() {
	maxHP = 0;
	stepSize = 0;
	strengthEffect = 1;
    resistenceEffect = 1;
}

Player::Player(int hp, int damage) : Entity(hp, damage){
    maxHP = hp;
    strengthEffect = 1;
    resistenceEffect = 1;
    stepSize = 0;

    //1:1 aus dem Image-Konstruktor genommen    
    this->x = 0;
    this->y = 0;
    this->w = 8;
    this->h = 8;
}

Player::Player(int hp, int damage, int x, int y) : 
        Entity(hp, damage){
    maxHP = hp;
    strengthEffect = 1;
    resistenceEffect = 1;
    stepSize = 0;
    
    //1:1 aus dem Image-Konstruktor genommen
    this->x = x;
    this->y = y;
    this->w = 8;
    this->h = 8;
}


// Getter

int Player::getMaxHP(){
    return maxHP;
}


// Setter

void Player::setMaxHP(int newMaxHP){
    if (newMaxHP > 0)
    {
        maxHP = newMaxHP;
    }
    else
    {
        std::cout << "Ungültige maxHP für Spieler";
    }
}

void Player::setWorld(World *world){
  if(this->world != nullptr){
        this->removeFromView();
    }

    this->path = "pics/entity/player/steve.png";

    // Funktionen aus Image, die im Konstruktor aufgerufen wird
    this->id = world->addElement(this);
    this->svg = world;
    this->create();

    this->world = world;
    this->setAttribute("image-rendering", "pixelated");  
    this->stepSize = world->getBlockSize();
    this->setSize(world->getBlockSize() * 0.8, world->getBlockSize() * 0.8);
}


// Funktionen

void Player::drinkPotion(Potion &potion){
    string effect = potion.getEffectType();
    float effstrength = potion.getEffectStrength();

    if (effect == "Health")
    {
        hp = maxHP;
    }
    else if (effect == "Strength")
    {
        strengthEffect += effstrength;
    }
    else if (effect == "Resistence")
    {
        resistenceEffect += effstrength;
    }

    else
    {
        std::cout << "Ungültiger übergebener Effekt";
    }
}

void Player::move(string key){

    int newX = this->getX();
    int newY = this->getY();
    if(key != ""){

        if(key == "w"){
            newY -= stepSize;
        }
        else if(key == "a"){
            newX -= stepSize;
        }
        else if(key == "s"){
            newY += stepSize;
        }
        else if(key == "d"){
            newX += stepSize;
        }
           
        if(moveIsLegal(newX, newY)){
            moveTo(newX, newY);
        }
    }
}

#endif