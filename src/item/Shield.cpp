#ifndef ITEM_SHIELD_CPP_
#define ITEM_SHIELD_CPP_

#include "../../includes/item/Shield.hpp"

// Konstruktor für ein zufälliges Schild
Shield::Shield(const int &x, const int &y, const int &size, SVG *pointer) :
		RigidItem("shield/", x, y, size, pointer, Material::randomWeapon()) {

	this->dodgeChance = baseDodgeChance * this->material->baseDamage
			* this->rarity->multiplier;
}

// Konstruktor für ein bestimmtes Schild
Shield::Shield(const int &x, const int &y, const int &size, SVG *pointer,
		const Material *material, const Rarity *rarity) :
		RigidItem("shield/", x, y, size, pointer,
				Material::checkWeapon(material), rarity) {

	this->dodgeChance = baseDodgeChance * this->material->baseDamage
			* this->rarity->multiplier;
}

/*
 * Getter
 */

const float& Shield::getDodgeChance() const {
	return this->dodgeChance;
}

// toString
 string Shield::toString() const {
	string rar = this->rarity->str;
	rar[0] = toupper(rar[0]);
	string mat = this->material->str;
	mat[0] = toupper(mat[0]);

	return rar + " " + mat + " Shield";
}

#endif /* ITEM_SHIELD_HPP_ */
