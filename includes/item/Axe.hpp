#ifndef ITEM_AXE_HPP_
#define ITEM_AXE_HPP_

#include "Weapon.hpp"

class Axe: public Weapon {

private:

	// Attribute
	static const float attackSpeed; // Speed in CPS

public:

	// Konstruktor für zufälligen Bogen
	Axe(const int &x, const int &y, const int &size, SVG *pointer);

	// Konstruktor für bestimmten Bogen
	Axe(const int &x, const int &y, const int &size, SVG *pointer,
			const Material *material, const Rarity *rarity);

	// toString
	string toString() const override;

	const float& getAttackSpeed() const override;
};

#endif /* ITEM_AXE_HPP_ */
