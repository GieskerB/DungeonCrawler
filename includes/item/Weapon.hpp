#ifndef ITEM_WEAPON_HPP_
#define ITEM_WEAPON_HPP_

#include "RigidItem.hpp"

class Weapon: public RigidItem {

public:

	// Konstruktor für zufällige Waffe
	Weapon(const string type, const int &x, const int &y, const int &size,
			SVG *pointer);

	// Konstruktor für bestimmte Waffe
	Weapon(const string type, const int &x, const int &y, const int &size,
			SVG *pointer, const Material *material, const Rarity *rarity);

	/*
	 * Getter
	 */

	float getDamage() const;

	virtual const float& getAttackSpeed() const = 0;

};

#endif /* ITEM_WEAPON_HPP_ */
