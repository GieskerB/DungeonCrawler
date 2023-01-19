#ifndef ITEM_WEAPON_CPP_
#define ITEM_WEAPON_CPP_

#include "../../includes/item/Weapon.hpp"

// Konstruktor für zufällige Waffe
Weapon::Weapon(const string type, const int &x, const int &y, const int &size,
		SVG *pointer) :
		RigidItem("weapon/", type, x, y, size, pointer,
				Material::randomWeapon()) {

}

// Konstruktor für bestimmte Waffe
Weapon::Weapon(const string type, const int &x, const int &y, const int &size,
		SVG *pointer, const Material *material, const Rarity *rarity) :
		RigidItem("weapon/", type, x, y, size, pointer,
				Material::checkWeapon(material), rarity) {

}

/*
 * Getter
 */

float Weapon::getDamage() const {
	return this->material->baseDamage * this->rarity->multiplier;
}

#endif /* ITEM_WEAPON_HPP_ */
