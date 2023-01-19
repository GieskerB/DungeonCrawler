#ifndef ITEM_HELMET_CPP_
#define ITEM_HELMET_CPP_

#include "../../includes/item/Helmet.hpp"

Helmet::Helmet(const int &x, const int &y, const int &size, SVG *pointer) :
		Armor("helmet", x, y, size, pointer) {

}

// Konstrukot für bestimmte Helmet
Helmet::Helmet(const int &x, const int &y, const int &size, SVG *pointer,
		const Material *material, const Rarity *rarity) :
		Armor("helmet", x, y, size, pointer, material, rarity) {

}

// toString
 string Helmet::toString() const {
	string rar = this->rarity->str;
	rar[0] = toupper(rar[0]);
	string mat = this->material->str;
	mat[0] = toupper(mat[0]);

	return rar + " " + mat + " Helmet";
}

float Helmet::getDefense() const {
	return this->Armor::getDefense() * multiplier;
}

#endif /* ITEM_HELMET_HPP_ */
