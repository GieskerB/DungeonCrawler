#ifndef ITEM_SWORD_HPP_
#define ITEM_SWORD_HPP_

#include "Weapon.hpp"

class Sword: public Weapon {

public:

	// Attribute
	static const float attackSpeed; // Speed in CPS

	// Konstrukto für zufälligen Bogen
	Sword(const int &x, const int &y, const int &size, SVG *pointer);

	// Konstrukto für bestimmten Bogen
	Sword(const int &x, const int &y, const int &size, SVG *pointer,
			const Material *material, const Rarity *rarity);

	// toString
	string toString() const override;

	const float& getAttackSpeed() const override;
};

#endif /* ITEM_SWORD_HPP_ */
