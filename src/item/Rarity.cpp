#ifndef ITEM_RARITY_CPP_
#define ITEM_RARITY_CPP_

#include "../../includes/item/Rarity.hpp"

/*
 * Java-like Enum-Class für konstatne Objekte
 */
//Rarity::Rarity(const Rarity &rar) = delete;
// Konstruktor
Rarity::Rarity(const string tag, const float mult, const int red,
		const int green, const int blue) :
		str(tag), multiplier(mult), r(red), g(green), b(blue) {
}

// Methoden

/*
 * Gibt eine zufällige Seltenheit zurück.
 * Wertvollere Seltenheit kommt seltener vor
 */
const Rarity* Rarity::random() {
	switch ((rand() % 100) + 1) {
	case 1 ... 29:
		return &COMMON;
	case 30 ... 57:
		return &UNCOMMON;
	case 58 ... 78:
		return &RARE;
	case 79 ... 92:
		return &EPIC;
	case 93 ... 99:
		return &LEGENDARY;
	default:
		return &MYTHIC;
	}
}

/*
 * Muss aus unerklärlichen Gründen selbst geschrieben werden
 */
bool Rarity::operator==(const Rarity &rar) const {
	return this->str == rar.str;
}
const Rarity Rarity::COMMON { "common", 1.00, 255, 255, 255 };
const Rarity Rarity::UNCOMMON { "uncommon", 1.05, 0, 170, 0 };
const Rarity Rarity::RARE { "rare", 1.10, 0, 0, 170 };
const Rarity Rarity::EPIC { "epic", 1.15, 170, 0, 170 };
const Rarity Rarity::LEGENDARY { "legendary", 1.25, 255, 170, 0 };
const Rarity Rarity::MYTHIC { "mythic", 1.40, 255, 85, 255 };

#endif /* ITEM_RARITY_HPP_ */
