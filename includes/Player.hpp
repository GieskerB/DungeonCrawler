#ifndef PLAYER_HPP
#define PLAYER_HPP

// Version mit Klassen in hpp und cpp unterteilt (mit World-Einbindung)
// & verschiedenen Enemytypen (funktionstüchtig) ~Version vom 16.01.23

#include "World.hpp"
#include "Entity.hpp"
#include "items.hpp"

class World;

class Player: public Entity {

private:
	

	// Speichert nicht die aktuellen HP, sondern die im vollregenerierten Zustand
	int maxHP; 
	float strengthEffect;
	float resistenceEffect;
	int stepSize;

public:

	// Konstruktoren
	Player();
	Player(int hp, int damage);
	Player(int hp, int damage, int x, int y) ;

	int getMaxHP();
	void setMaxHP(int newMaxHP);
	void setWorld(World *world); 

	// Wird aufgerufen, wenn der Spieler einen Trank aufnimmt
	// Gibt dementsprechend Effekte
	void drinkPotion(Potion &potion);

	// Je nach Eingabe (wasd) wird der Spieler bewegt, wenn der Schritt legal ist
	void move(string key);
};
#endif

/* Infos zur Klasse:
	Man kann einen Spieler ohne zugehörige Welt erstellen. Diese kann über die setWorld-Methode zugeordnet werden.
	Waffen- und Rüstungsslots fehlen noch
	In der World-Klasse muss momentan noch ein Nullptr für den Spieler übergeben werden und manuell 
	über setWorld zugewiesen werden
 */

