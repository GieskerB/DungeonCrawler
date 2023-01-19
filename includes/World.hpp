#ifndef WORLD_HPP_
#define WORLD_HPP_

//#include <algoviz/SVG.hpp>
#include "SVG.hpp"
#include "Block.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <vector>
#include <list>
#include <memory>
#include "items.hpp"

class Entity;
class Player;
class Enemy;

class World: public SVG {

private:

	int gridSize, blockSize;
	Player *player;
	list<Enemy> enemies;
	vector<Block> blocks;
	list<Item*> items;

	bool isDigit(const char &c);

	void moveEnemies();

public:

	World(const int &width, const int &heigth, const int &gridSize,
			Player *player, const string title);

	void createWorld(const string &runLengthEncoding);

	void spawnEnemies(const int &number);

	void spawnItems(const int &number, const int &level);

	int update(string direction);

	void movePlayer(const string &key);

	bool distanceToFight();
	
	bool potionToDrink();

	const bool isWalkable(const int &row, const int &col);

	const int& getGridSize() const;

	const int& getBlockSize() const;

	const vector<Block>* getBlocks() const;

};

#endif /* WORLD_HPP_ */
