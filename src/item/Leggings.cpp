#ifndef ITEM_LEGGINGS_CPP_
#define ITEM_LEGGINGS_CPP_

#include "../../includes/item/Leggings.hpp"

Leggings::Leggings(const int &x, const int &y, const int &size, SVG *pointer) :
		Armor("leggings", x, y, size, pointer) {

}

// Konstrukot für bestimmte Leggings
Leggings::Leggings(const int &x, const int &y, const int &size, SVG *pointer,
		const Material *material, const Rarity *rarity) :
		Armor("leggings", x, y, size, pointer, material, rarity) {

}

// toString
 string Leggings::toString() const {
	string rar = this->rarity->str;
	rar[0] = toupper(rar[0]);
	string mat = this->material->str;
	mat[0] = toupper(mat[0]);

	return rar + " " + mat + " Leggings";
}

float Leggings::getDefense() const {
	return this->Armor::getDefense() * multiplier;
}

#endif /* ITEM_LEGGINGS_HPP_ */
