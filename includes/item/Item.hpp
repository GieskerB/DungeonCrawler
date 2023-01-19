#ifndef ITEM_ITEM_HPP_
#define ITEM_ITEM_HPP_

//#include <algoviz/SVG.hpp>
#include "../SVG.hpp"
#include "Rarity.hpp"

#include <iostream>

class Item: public Image {

protected:

	// Attribute
	const Rarity *rarity;

public:

	// Konstruktor für zufällige Items
	Item(const string path, const int &x, const int &y, const int &size,
			SVG *pointer);

	// Konstruktor für bestimmte Items
	Item(const string path, const int &x, const int &y, const int &size,
			SVG *pointer, const Rarity *rarity);

	/*
	 * Getter & Setter
	 */

	const int& getSize() const;

	const Rarity* getRarity() const;

	virtual string toString() const = 0;
};

#endif /* ITEM_ITEM_HPP_ */
