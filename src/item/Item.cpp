#ifndef ITEM_ITEM_CPP_
#define ITEM_ITEM_CPP_

#include "../../includes/item/Item.hpp"
//#include "../includes/SVG.hpp"

Item::Item(const string path, const int &x, const int &y, const int &size,
		SVG *pointer) :
		Image("../pics/item/" + path + ".png", x, y, 16, 16, pointer) {

	this->rarity = Rarity::random();
	this->setAttribute("image-rendering", "pixelated");
	this->setSize(size, size);
}

// Konstruktor für bestimmte Items
Item::Item(const string path, const int &x, const int &y, const int &size,
		SVG *pointer, const Rarity *rarity) :
		Image("../pics/item/" + path, x, y, 16, 16, pointer) {

	this->rarity = rarity;
	this->setAttribute("image-rendering", "pixelated");
	this->setSize(size, size);
}

/*
 * Getter & Setter
 */

const int& Item::getSize() const {
	return this->w;
}

const Rarity* Item::getRarity() const {
	return this->rarity;
}

#endif /* ITEM_ITEM_HPP_ */
