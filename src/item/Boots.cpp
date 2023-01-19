#ifndef ITEM_BOOTS_CPP_
#define ITEM_BOOTS_CPP_

#include "../../includes/item/Boots.hpp"

Boots::Boots(const int &x, const int &y, const int &size, SVG *pointer) :
		Armor("boots", x, y, size, pointer) {

}

// Konstrukot für bestimmte Boots
Boots::Boots(const int &x, const int &y, const int &size, SVG *pointer,
		const Material *material, const Rarity *rarity) :
		Armor("boots", x, y, size, pointer, material, rarity) {

}

// toString
 string Boots::toString() const {
	string rar = this->rarity->str;
	rar[0] = toupper(rar[0]);
	string mat = this->material->str;
	mat[0] = toupper(mat[0]);

	return rar + " " + mat + " Boots";
}

float Boots::getDefense() const {
	return this->Armor::getDefense() * multiplier;
}

#endif /* ITEM_BOOTS_HPP_ */
