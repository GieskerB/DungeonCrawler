#ifndef ITEM_RigidItem_HPP_
#define ITEM_RigidItem_HPP_

#include "Item.hpp"
#include "Material.hpp"

class RigidItem: public Item {

protected:

	// Attribute
	const Material *material;

public:

	// Konstruktor für ein zufällifges RigidItem
	RigidItem(const string type1, const string type2, const int &x,
			const int &y, const int &size, SVG *pointer,
			const Material *material);

	// Konstruktor für ein zufällifges RigidItem
	RigidItem(const string type, const int &x, const int &y, const int &size,
			SVG *pointer, const Material *material);

	// Konstruktor für ein bestimmtes RigidItem
	RigidItem(const string type1, const string type2, const int &x,
			const int &y, const int &size, SVG *pointer,
			const Material *material, const Rarity *rarity);

	// Konstruktor für ein bestimmtes RigidItem
	RigidItem(const string type, const int &x, const int &y, const int &size,
			SVG *pointer, const Material *material, const Rarity *rarity);

	/*
	 * Getter
	 */

	const Material* getMaterial() const;

};

#endif /* ITEM_INVENTORYITEM_HPP_ */
