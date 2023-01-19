#ifndef ENEMY_HPP
#define ENEMY_HPP

// Version mit Klassen in hpp und cpp unterteilt (mit World-Einbindung)
// & verschiedenen Enemytypen (funktionstüchtig) ~Version vom 16.01.23

#include "World.hpp"
#include "Entity.hpp"

class World;

class Enemy : public Entity{

public:
    Enemy();

    // Erzeugt einen Default Enemy (zum Debuggen)
//    Enemy(World *world, int x, int y, int level);

    // Beide folgenen Konstruktoren erzeugen einen Random Enemy
    Enemy(int level, World *view);
    Enemy(int level, World *view, int x, int y);

    // Gegner bewegen sich random einen Schritt, der Legal ist
    void move();

private:
    // Funktion, die im Konstruktor aufgerufen wird und das Bild, hp & dmg zuweist
    void pickEnemyType(int level, int enemyNo);

};
#endif
