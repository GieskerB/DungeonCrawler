#ifndef ITEM_RARITY_HPP_
#define ITEM_RARITY_HPP_

#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 * Java-like Enum-Class für konstatne Objekte
 */
class Rarity {

public:

	// Konstante Objekte
	static const Rarity COMMON;
	static const Rarity UNCOMMON;
	static const Rarity RARE;
	static const Rarity EPIC;
	static const Rarity LEGENDARY;
	static const Rarity MYTHIC;

	// Attribute
	const string str;
	const float multiplier;
	const short r, g, b;

	Rarity(const Rarity &rar) = delete;

private:

	// Konstruktor
	Rarity(const string tag, const float mult, const int red, const int green,
			const int blue);

public:

	// Methoden

	/*
	 * Gibt eine zufällige Seltenheit zurück.
	 * Wertvollere Seltenheit kommt seltener vor
	 */
	static const Rarity* random();

	/*
	 * Muss aus unerklärlichen Gründen selbst geschrieben werden
	 */
	bool operator==(const Rarity &rar) const;

};

#endif /* ITEM_RARITY_HPP_ */
