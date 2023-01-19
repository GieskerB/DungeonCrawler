#ifndef ITEM_CHESTPLATE_HPP_
#define ITEM_CHESTPLATE_HPP_

#include "Armor.hpp"

class Chestplate: public Armor {

private:

	// Attribute
	static constexpr float multiplier = 0.40f;

public:

	// Konstrukot für zufällige Chestplate
	Chestplate(const int &x, const int &y, const int &size, SVG *pointer) ;

	// Konstrukot für bestimmte Chestplate
	Chestplate(const int &x, const int &y, const int &size, SVG *pointer,
			const Material *material, const Rarity *rarity) ;

	// toString
	string toString() const override ;

	float getDefense() const override ;

};

#endif /* ITEM_CHESTPLATE_HPP_ */
