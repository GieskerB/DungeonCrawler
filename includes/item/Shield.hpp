#ifndef ITEM_SHIELD_HPP_
#define ITEM_SHIELD_HPP_

#include "RigidItem.hpp"

class Shield: public RigidItem {

private:

	// Attribute
	constexpr static float baseDodgeChance = 0.075;
	float dodgeChance;

public:

	// Konstruktor für ein zufälliges Schild
	Shield(const int &x, const int &y, const int &size, SVG *pointer);

	// Konstruktor für ein bestimmtes Schild
	Shield(const int &x, const int &y, const int &size, SVG *pointer,
			const Material *material, const Rarity *rarity);

	/*
	 * Getter
	 */

	const float& getDodgeChance() const;

	// toString
	string toString() const override;

};

#endif /* ITEM_SHIELD_HPP_ */
