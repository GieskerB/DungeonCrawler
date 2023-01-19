#ifndef ITEM_ARMOR_HPP_
#define ITEM_ARMOR_HPP_

#include "RigidItem.hpp"

class Armor: public RigidItem {

public:

	// Konstruktor für zufällige Rüstung
	Armor(const string type, const int &x, const int &y, const int &size,
			SVG *pointer);

	// Konstruktor für bestimmte Rüstung
	Armor(const string type, const int &x, const int &y, const int &size,
			SVG *pointer, const Material *material, const Rarity *rarity);

	/*
	 * Getter
	 */

	virtual float getDefense() const;

};

#endif /* ITEM_ARMOR_HPP_ */
