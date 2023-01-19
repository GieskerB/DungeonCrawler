#ifndef ITEM_BOW_HPP_
#define ITEM_BOW_HPP_

#include "Weapon.hpp"

class Bow: public Weapon {

private:

	// Attribute
	static const float attackSpeed; // Speed in CPS

public:

	// Konstrukto für zufälligen Bogen
	Bow(const int &x, const int &y, const int &size, SVG *pointer) ;

	// Konstrukto für bestimmten Bogen
	Bow(const int &x, const int &y, const int &size, SVG *pointer,
			const Material *material, const Rarity *rarity) ;

	// toString
	string toString() const override ;

	const float& getAttackSpeed() const override;

};

#endif /* ITEM_BOW_HPP_ */
