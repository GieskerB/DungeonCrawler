#ifndef ITEM_POTION_HPP_
#define ITEM_POTION_HPP_

#include "Item.hpp"

class Potion: public Item {

public:

	enum class EffectType {
		HEALTH, STRENGTH, RESISTENCE
	};

private:

	// Attribute
	EffectType effectType;
	float effectStrength;

public:

	// Konstruktor für einen zufälligen Trank
	Potion(const string &color, const int &x, const int &y, const int &size,
			SVG *pointer);

	// Konstruktor für einen bestimmten Trank
	Potion(const string &color, const int &x, const int &y, const int &size,
			SVG *pointer, const EffectType &effectType,
			const int &effectStrength, const Rarity *rarity);

	/*
	 * Getter & Setter
	 */

	string getEffectType() const;

	const EffectType& getEffectTypeIndex() const;

	float getEffectStrength() const;

	// toString
	string toString() const override;

};

#endif /* ITEM_POTION_HPP_ */
