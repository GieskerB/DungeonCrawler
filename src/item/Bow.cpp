#ifndef ITEM_BOW_CPP_
#define ITEM_BOW_CPP_

#include "../../includes/item/Bow.hpp"


const float Bow::attackSpeed = 0.9f; // Speed in CPS

Bow::Bow(const int &x, const int &y, const int &size, SVG *pointer) :
		Weapon("bow", x, y, size, pointer) {

}

// Konstrukto für bestimmten Bogen
Bow::Bow(const int &x, const int &y, const int &size, SVG *pointer,
		const Material *material, const Rarity *rarity) :
		Weapon("bow", x, y, size, pointer, material, rarity) {

}

// toString
string Bow::toString() const {
	string rar = this->rarity->str;
	rar[0] = toupper(rar[0]);
	string mat = this->material->str;
	mat[0] = toupper(mat[0]);

	return rar + " " + mat + " Bow";
}


const float& Bow::getAttackSpeed() const {
	return Bow::attackSpeed;
}

#endif /* ITEM_BOW_HPP_ */
