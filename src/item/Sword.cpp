#ifndef ITEM_SWORD_CPP_
#define ITEM_SWORD_CPP_

#include "../../includes/item/Sword.hpp"

const float Sword::attackSpeed = 1.6f; // Speed in CPS

// Konstrukto für zufälligen Bogen
Sword::Sword(const int &x, const int &y, const int &size, SVG *pointer) :
		Weapon("sword", x, y, size, pointer) {

}

// Konstrukto für bestimmten Bogen
Sword::Sword(const int &x, const int &y, const int &size, SVG *pointer,
		const Material *material, const Rarity *rarity) :
		Weapon("sword", x, y, size, pointer, material, rarity) {

}

// toString
 string Sword::toString() const {
	string rar = this->rarity->str;
	rar[0] = toupper(rar[0]);
	string mat = this->material->str;
	mat[0] = toupper(mat[0]);

	return rar + " " + mat + " Sword";
}

const float& Sword::getAttackSpeed() const {
	return Sword::attackSpeed;
}

#endif /* ITEM_SWORD_HPP_ */
