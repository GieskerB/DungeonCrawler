#ifndef WORLDBLUEPRINT_HPP_
#define WORLDBLUEPRINT_HPP_

//#include <algoviz/SVG.hpp>
#include "SVG.hpp"
#include "Block.hpp"
#include <string>
#include "World.hpp"

using namespace std;

class World;

class WorldBlueprint {

private:

	// Hilfskonstanten.
	static const int numWorlds;
	static const int worldSizes[], variations[];

	// Lauflängenkodierung der Weltern
	static const string runLengthEncoding[];

	// Tabellarische Verlinkung von den [World][Variation][Block-ID]
	static const string blockNames[5][3][8];

	// Attribute
	int worldIndex, variationIndex, gridSize;

public:

	// Konstruktor für zufällige Worldgeneration
	WorldBlueprint();

	// Konstruktor für zufällige Variation einer bestimmten Welt
	WorldBlueprint(const int &worldIndex);

	// Konstruktor für bestimmte Variation einer bestimmten Welt
	WorldBlueprint(const int &worldIndex, const int &variationIndex);

	// Generiert die Welt und gibt sie als Block-Vector zurück.
	vector<Block> buildWorld(World *world) const;

	/*
	 * Getter
	 */

	const int& getGridSize() const;

};

#endif /* WORLD_HPP_ */
