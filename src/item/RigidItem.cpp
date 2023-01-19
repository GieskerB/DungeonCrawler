#ifndef ITEM_RigidItem_CPP_
#define ITEM_RigidItem_CPP_

#include "../../includes/item/RigidItem.hpp"

RigidItem::RigidItem(const string type1, const string type2, const int &x,
		const int &y, const int &size, SVG *pointer, const Material *material) : // nicht this->material!
		Item(type1 + material->str + "/" + type2, x, y, size, pointer) {

	this->material = material;
}

// Konstruktor für ein zufällifges RigidItem
RigidItem::RigidItem(const string type, const int &x, const int &y,
		const int &size, SVG *pointer, const Material *material) : // nicht this->material!
		Item(type + material->str, x, y, size, pointer) {

	this->material = material;
}

// Konstruktor für ein bestimmtes RigidItem
RigidItem::RigidItem(const string type1, const string type2, const int &x,
		const int &y, const int &size, SVG *pointer, const Material *material,
		const Rarity *rarity) : // nicht this->material!
		Item(type1 + material->str + "/" + type2, x, y, size, pointer, rarity) {

	this->material = material;
}

// Konstruktor für ein bestimmtes RigidItem
RigidItem::RigidItem(const string type, const int &x, const int &y,
		const int &size, SVG *pointer, const Material *material,
		const Rarity *rarity) : // nicht this->material!
		Item(type + material->str, x, y, size, pointer, rarity) {

	this->material = material;
}

/*
 * Getter
 */

const Material* RigidItem::getMaterial() const {
	return this->material;
}

#endif /* ITEM_INVENTORYITEM_HPP_ */
