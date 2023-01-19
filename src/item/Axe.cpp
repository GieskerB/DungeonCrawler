#ifndef ITEM_AXE_CPP_
#define ITEM_AXE_CPP_

#include "../../includes/item/Axe.hpp"


	const float Axe::attackSpeed = 1.0f; // Speed in CPS

Axe::Axe(const int &x, const int &y, const int &size, SVG *pointer) :
		Weapon("axe", x, y, size, pointer) {

}

// Konstruktor für bestimmten Bogen
Axe::Axe(const int &x, const int &y, const int &size, SVG *pointer,
		const Material *material, const Rarity *rarity) :
		Weapon("axe", x, y, size, pointer, material, rarity) {

}

// toString
 string Axe::toString() const {
	string rar = this->rarity->str;
	rar[0] = toupper(rar[0]);
	string mat = this->material->str;
	mat[0] = toupper(mat[0]);

	return rar + " " + mat + " Axe";
}

const float& Axe::getAttackSpeed() const {
	return Axe::attackSpeed;
}

#endif /* ITEM_AXE_HPP_ */
