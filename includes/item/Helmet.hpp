#ifndef ITEM_HELMET_HPP_
#define ITEM_HELMET_HPP_

#include "Armor.hpp"

class Helmet: public Armor {

private:

	// Attribute
	static constexpr float multiplier = 0.15f;

public:

	// Konstrukot für zufällige Helmet
	Helmet(const int &x, const int &y, const int &size, SVG *pointer);

	// Konstrukot für bestimmte Helmet
	Helmet(const int &x, const int &y, const int &size, SVG *pointer,
			const Material *material, const Rarity *rarity);

	// toString
	string toString() const override;

	float getDefense() const override;
};

#endif /* ITEM_HELMET_HPP_ */
