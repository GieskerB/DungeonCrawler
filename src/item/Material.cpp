#ifndef ITEM_MATERIAL_CPP_
#define ITEM_MATERIAL_CPP_

#include "../../includes/item/Material.hpp"

/*
 * Java-like Enum-Class für konstatne Objekte
 */
//Material::Material(const Material &mat) = delete;
Material::Material(const string tag, const int baseDmg, const int baseDef) :
		str(tag), baseDamage(baseDmg), baseDefense(baseDef) {

}

// Methods

/*
 * Gibt ein zufälliges Material für ein Rüstungsstück zurück.
 * Seltenheit basiert auf dem Wert des Materials
 */
const Material* Material::randomArmor() {
	switch ((rand() % 100) + 1) {
	case 1 ... 29:
		return &LEATHER;
	case 30 ... 57:
		return &CHAIN;
	case 58 ... 78:
		return &IRON;
	case 79 ... 92:
		return &GOLD;
	case 93 ... 99:
		return &DIAMOND;
	default:
		return &NETHERITE;
	}
}

/*
 * Gibt ein zufälliges Material für eine Waffe zurück.
 * Seltenheit basiert auf dem Wert des Materials
 */
const Material* Material::randomWeapon() {
	switch ((rand() % 100) + 1) {
	case 1 ... 29:
		return &WOOD;
	case 30 ... 57:
		return &STONE;
	case 58 ... 78:
		return &IRON;
	case 79 ... 92:
		return &GOLD;
	case 93 ... 99:
		return &DIAMOND;
	default:
		return &NETHERITE;
	}
}

/*
 * Muss aus unerklärlichen Gründen selbst geschrieben werden
 */
bool Material::operator==(const Material &mat) const{
	return this->str == mat.str;
}
/*
 * Muss aus unerklärlichen Gründen selbst geschrieben werden
 */
//	const Material* operator=(const Material *mat) const {
//		cout << "=" << endl;
//		return mat;
//	}
/*
 * Überprüft, ob das gegebene Material valide für ein Rüstungsteil ist.
 * Und gibt ansosnten ein valides Material zurück
 */
const Material* Material::checkArmor(const Material *mat) {
	if (not (mat->str == WOOD.str or mat->str == STONE.str)) {
		return mat;
	}
	return randomArmor();
}

/*
 * Überprüft, ob das gegebene Material valide für eine Waffe ist.
 *  Und gibt ansosnten ein valides Material zurück
 */
const Material* Material::checkWeapon(const Material *mat) {
	if (*(mat) == WOOD || *(mat) == STONE || *(mat) == IRON || *(mat) == GOLD
			|| *(mat) == DIAMOND || *(mat) == NETHERITE) {
		return mat;
	}
	return randomWeapon();
}

const Material Material::LEATHER { "leather", 0, 15 };
const Material Material::WOOD { "wood", 3, 0 };
const Material Material::STONE { "stone", 4, 0 };
const Material Material::CHAIN { "chain", 0, 22 };
const Material Material::GOLD { "gold", 5, 30 };
const Material Material::IRON { "iron", 6, 45 };
const Material Material::DIAMOND { "diamond", 7, 60 };
const Material Material::NETHERITE { "netherite", 8, 75 };

#endif /* ITEM_MATERIAL_HPP_ */
