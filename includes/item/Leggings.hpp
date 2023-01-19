#ifndef ITEM_LEGGINGS_HPP_
#define ITEM_LEGGINGS_HPP_

#include "Armor.hpp"

class Leggings: public Armor {

private:

	// Attribute
	static constexpr float multiplier = 0.30f;

public:

	// Konstrukot für zufällige Leggings
	Leggings(const int &x, const int &y, const int &size, SVG *pointer) ;

	// Konstrukot für bestimmte Leggings
	Leggings(const int &x, const int &y, const int &size, SVG *pointer,
			const Material *material, const Rarity *rarity) ;

	// toString
	string toString() const override ;

	float getDefense() const override ;

};

#endif /* ITEM_LEGGINGS_HPP_ */
