#ifndef ITEM_BOOTS_HPP_
#define ITEM_BOOTS_HPP_

#include "Armor.hpp"

class Boots: public Armor {

private:

	// Attribute
	static constexpr float multiplier = 0.15f;

public:

	// Konstrukot für zufällige Boots
	Boots(const int &x, const int &y, const int &size, SVG *pointer);

	// Konstrukot für bestimmte Boots
	Boots(const int &x, const int &y, const int &size, SVG *pointer,
			const Material *material, const Rarity *rarity);

	// toString
	string toString() const override;

	float getDefense() const override;

};

#endif /* ITEM_BOOTS_HPP_ */
