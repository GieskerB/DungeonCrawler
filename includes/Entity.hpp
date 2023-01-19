#ifndef ENTITY_HPP
#define ENTITY_HPP

// Version mit Klassen in hpp und cpp unterteilt (mit World-Einbindung)
// & verschiedenen Enemytypen (funktionstüchtig) ~Version vom 16.01.23
// damaged wurde geändert und gibt jetzt zurück, ob das Entity gestorben ist (died wurde gelöscht)

//#include <algoviz/SVG.hpp>
#include "SVG.hpp"
#include "World.hpp"
#include <iostream>

class World;

class Entity: public Image {
protected:
	int hp;
	int damage;
	World *world;

public:

	Entity();

	//Konstruktor für Spieler
	Entity(int hp, int damage);

	//Konstruktor für die Gegner
	Entity(World *world);

	int getHp();
	int getDamage();
	void setHP(int newHp);
	void setDamage(int newDmg);
	
	// damaged wird aufgerufen, wenn das Entity verletzt wird
	// Zieht Leben ab. Wenn das Entity daran stirbt wird true ausgegeben
	bool damaged(int damage);

	// Zum manuellen Setzen der Koordinaten
	void setKoord(int x, int y);

protected:
	// Überprüft, ob der geplante Schritt gültig ist oder der Rand bzw. ein Block im Weg ist
	bool moveIsLegal(int x, int y);

};

#endif
