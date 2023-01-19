#ifndef WORLDBLUEPRINT_CPP_
#define WORLDBLUEPRINT_CPP_

#include "../includes/WorldBlueprint.hpp"

// Hilfskonstanten.
const int WorldBlueprint::numWorlds = 5;
const int WorldBlueprint::worldSizes[] = { 21, 25, 23, 15, 35 };
const int WorldBlueprint::variations[] = { 3, 2, 2, 2, 1 };

// Lauflängenkodierung der Weltern
const string WorldBlueprint::runLengthEncoding[5] =
{
		"010,21,020,31,012,117,04,117,04,12,52,12,45,12,52,12,04,12,51,111,51,12,04,117,04,117,04,12,41,15,41,15,12,04,12,41,15,41,15,41,12,02,21,31,12,41,13,45,13,41,12,31,21,02,12,41,15,41,15,12,04,12,41,15,41,15,41,12,04,117,04,117,04,12,51,111,51,12,04,12,52,12,45,12,52,12,04,117,04,117,012,31,020,21,010",
		"012,21,024,31,014,121,04,121,04,12,42,52,19,52,42,12,04,12,41,115,41,12,04,12,51,115,51,12,04,12,51,12,71,12,51,13,51,12,61,12,51,12,04,18,51,13,51,18,04,18,41,13,41,18,04,15,52,42,13,42,52,15,04,121,02,21,31,121,31,21,02,121,04,15,52,42,13,42,52,15,04,18,41,13,41,18,04,18,51,13,51,18,04,12,51,12,61,12,51,13,51,12,71,12,51,12,04,12,51,115,51,12,04,12,41,115,41,12,04,12,42,52,19,52,42,12,04,121,04,121,014,31,024,21,012",
		"",
		"",
		""
};

// Tabellarische Verlinkung von den [World][Variation][Block-ID]
const string WorldBlueprint::blockNames[5][3][8] =
{
		{
				{"stone_bricks","grass_block","oak_door_top","oak_door_bottom","oak_log","oak_planks","air","air"},
				{"cracked_stone_bricks","podzol","spruce_door_top","spruce_door_bottom","spruce_log","spruce_planks","air","air"},
				{"mossy_stone_bricks","mud","mangrove_door_top","mangrove_door_bottom","mangrove_log","mangrove_planks","air","air"}
		},
		{
				{"bedrock","deepslate","iron_door_top","iron_door_bootom","deepslate_bricks","polished_deepslate","deepslate_diamond_ore","deepslate_emerald_ore"},
				{"bedrock","stone","iron_door_top","iron_door_bootom","stone_bricks","chiseled_stone_bricks","diamond_ore","emerald_ore"},
				{"air","air","air","air","air","air","air","air"}
		},
		{
				{"crimson_nylium","nether_bricks","crimson_door_top","crimson_door_bottom","crimson_stem","crimson_planks","nether_quartz_ore","lava"},
				{"warped_nylium","nether_bricks","warped_door_top","warped_door_bottom","warped_stem","warped_planks","nether_quartz_ore","lava"},
				{"air","air","air","air","air","air","air","air"}
		},
		{
				{"end_stone_bricks","end_stone","iron_door_top","iron_door_bootom","obsidian","end_portal_frame_top","air","air"},
				{"dark_prismarine","prismarine","iron_door_top","iron_door_bootom","water","prismarine_bricks","air","air"},
				{"air","air","air","air","air","air","air","air"}
		},
		{
				{"mossy_stone_bricks","cobblestone","dark_oak_door_top","dark_oak_door_bottom","mossy_cobblestone","air","air","air"},
				{"air","air","air","air","air","air","air","air"},
				{"air","air","air","air","air","air","air","air"}
		}
};

// Konstruktor für zufällige Worldgeneration
WorldBlueprint::WorldBlueprint() {
	this->worldIndex = rand() % WorldBlueprint::numWorlds;
	this->worldIndex--;
	this->variationIndex = rand()
			% WorldBlueprint::variations[this->worldIndex];
	this->variationIndex--;
	this->gridSize = WorldBlueprint::worldSizes[this->worldIndex];
}
// Konstruktor für zufällige Variation einer bestimmten Welt
WorldBlueprint::WorldBlueprint(const int &worldIndex) {

	this->worldIndex =
			(worldIndex > 5 or worldIndex < 1) ?
					(rand() % WorldBlueprint::numWorlds) : worldIndex;
	this->worldIndex--;
	this->variationIndex = rand()
			% WorldBlueprint::variations[this->worldIndex];
	this->variationIndex--;
	this->gridSize = WorldBlueprint::worldSizes[this->worldIndex];
}

// Konstruktor für bestimmte Variation einer bestimmten Welt
WorldBlueprint::WorldBlueprint(const int &worldIndex,
		const int &variationIndex) {

	this->worldIndex =
			(worldIndex > 5 or worldIndex < 1) ?
					(rand() % WorldBlueprint::numWorlds) : worldIndex;
	this->worldIndex--;
	this->variationIndex =
			(variationIndex > WorldBlueprint::variations[this->worldIndex]
					or worldIndex < 1) ?
					(rand() % WorldBlueprint::variations[this->worldIndex]) :
					variationIndex;
	this->variationIndex--;
	this->gridSize = WorldBlueprint::worldSizes[this->worldIndex];
}

// Generiert die Welt und gibt sie als Block-Vector zurück.
vector<Block> WorldBlueprint::buildWorld(World *world) const {
	AlgoViz::collectMessages();

	vector<Block> grid;

	const string blueprint = WorldBlueprint::runLengthEncoding[this->worldIndex];
	string path;

	const int length = blueprint.length();
	const int blockSize = WorldBlueprint::worldSizes[this->worldIndex];
	int amount, index = 0, leftIndex = 1, rightIndex = 1;
	int id = blueprint[0] - '0';

	/*
	 * Prinzip der LLC:
	 * Kommata separieren die einzelnen Abschnitte.
	 * Direkt nach dem Komma steht die Id des Blocks
	 * Die Zahl von dort, bis zum nächsten Komma ist die Anzahl
	 * der Blöcke, die in die Welt hinzugefügt werden.
	 */
	for (int i = 1; i < length; i++) {

		// Marker des nächsten Elemetns:
		if (blueprint[i] == ',') {
			// Bestimme die Menge an Blöcken
			rightIndex = i;
			amount = stoi(blueprint.substr(leftIndex, leftIndex - rightIndex));

			// Fügt die richtige Menge an Blöcken in den
			// vector<Block> hinzu.
			for (int j = 0; j < amount; j++) {
				// Erstellt den path zum Block-Image
				path =
						"../pics/blocks/"
								+ WorldBlueprint::blockNames[this->worldIndex][this->variationIndex][id]
								+ ".png";
				grid.push_back(
						Block((index / this->gridSize) * blockSize,
								(index & this->gridSize) * blockSize, blockSize,
								id == 1, path, world));
				index++;
			}
			// Speicher IDund Left Index für den nächsten Durchlauf.
			i++;
			id = blueprint[i] - '0';
			leftIndex = i + 1;
		}
	}

	/*
	 * Bestimmt die letze Sequenz an Blöcke, da der LLC-String nicht
	 * in einem Komma endet.
	 */
	rightIndex = length;
	amount = stoi(blueprint.substr(leftIndex, leftIndex - rightIndex));

	for (int j = 0; j < amount; j++) {
		path =
				"../pics/blocks/"
						+ WorldBlueprint::blockNames[this->worldIndex][this->variationIndex][id]
						+ ".png";
		grid.push_back(
				Block((index / this->gridSize) * blockSize,
						(index & this->gridSize) * blockSize, blockSize,
						id == 1, path, world));
		index++;
	}

	AlgoViz::flushMessages();
	return grid;
}

/*
 * Getter
 */

const int& WorldBlueprint::getGridSize() const {
	return this->gridSize;
}

#endif /* WORLD_CPP: */

