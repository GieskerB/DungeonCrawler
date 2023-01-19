#ifndef ITEM_POTION_CPP_
#define ITEM_POTION_CPP_

#include "../../includes/item/Potion.hpp"

Potion::Potion(const string &color, const int &x, const int &y, const int &size,
		SVG *pointer) :
		Item("potion/" + color, x, y, size, pointer) {

	this->effectType = (EffectType) (rand() % 3);
	this->effectStrength = (rand() / 100) / 100.0;
}

// Konstruktor für einen bestimmten Trank
Potion::Potion(const string &color, const int &x, const int &y, const int &size,
		SVG *pointer, const EffectType &effectType, const int &effectStrength,
		const Rarity *rarity) :
		Item("potion/" + color, x, y, size, pointer, rarity) {

	this->effectType = effectType;
	this->effectStrength = effectStrength;
}

/*
 * Getter & Setter
 */

string Potion::getEffectType() const {
	switch (this->effectType) {

	case EffectType::HEALTH:
		return "Health";
	case EffectType::STRENGTH:
		return "Strength";
	case EffectType::RESISTENCE:
		return "Resistence";
	default:
		return "None";
	}
}

const Potion::EffectType& Potion::getEffectTypeIndex() const {
	return this->effectType;
}

float Potion::getEffectStrength() const {
	return this->effectStrength * this->rarity->multiplier;
}

// toString
 string Potion::toString() const {
	string rar = this->rarity->str;
	rar[0] = toupper(rar[0]);
	string eff = this->getEffectType();

	return rar + " " + eff + " Potion";
}

#endif /* ITEM_POTION_HPP_ */
