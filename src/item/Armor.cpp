#ifndef ITEM_ARMOR_CPP_
#define ITEM_ARMOR_CPP_

#include "../../includes/item/Armor.hpp"

Armor::Armor(const string type, const int &x, const int &y, const int &size,
		SVG *pointer) :
		RigidItem("armor/", type, x, y, size, pointer, Material::randomArmor()) {

}

// Konstruktor für bestimmte Rüstung
Armor::Armor(const string type, const int &x, const int &y, const int &size,
		SVG *pointer, const Material *material, const Rarity *rarity) :
		RigidItem("armor/", type, x, y, size, pointer,
				Material::checkArmor(material), rarity) {

}

/*
 * Getter
 */

float Armor::getDefense() const {
	return this->material->baseDefense * this->rarity->multiplier;
}

#endif /* ITEM_ARMOR_HPP_ */
