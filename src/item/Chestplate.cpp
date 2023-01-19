#ifndef ITEM_CHESTPLATE_CPP_
#define ITEM_CHESTPLATE_CPP_

#include "../../includes/item/Chestplate.hpp"

Chestplate::Chestplate(const int &x, const int &y, const int &size,
		SVG *pointer) :
		Armor("chestplate", x, y, size, pointer) {

}

// Konstrukot für bestimmte Chestplate
Chestplate::Chestplate(const int &x, const int &y, const int &size,
		SVG *pointer, const Material *material, const Rarity *rarity) :
		Armor("chestplate", x, y, size, pointer, material, rarity) {

}

// toString
 string Chestplate::toString() const {
	string rar = this->rarity->str;
	rar[0] = toupper(rar[0]);
	string mat = this->material->str;
	mat[0] = toupper(mat[0]);

	return rar + " " + mat + " Chestplate";
}

float Chestplate::getDefense() const{
	return this->Armor::getDefense() * multiplier;
}

#endif /* ITEM_CHESTPLATE_HPP_ */
