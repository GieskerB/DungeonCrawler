#ifndef WORLD_CPP_
#define WORLD_CPP_

#include "../includes/World.hpp"

bool World::isDigit(const char &c) {
	return '0' <= c and c <= '9';
}

void World::moveEnemies() {
  	list<Enemy>::iterator it = enemies.begin(); 
  	while (it != enemies.end()) {
    it->move();
    it++;
	}
}

World::World(const int &width, const int &heigth, const int &gridSize,
		Player *player, const string title = "World") :
		SVG(width, heigth, title) {

	this->gridSize = gridSize;
	this->blockSize = this->width / this->gridSize;
	this->player = player;
}

void World::createWorld(const string &runLengthEncoding) {
	this->blocks.reserve(this->gridSize * this->gridSize);
	bool blockType = true;
	int index = 0, leftIndex = 0, rightIndex = 0;
	int length = runLengthEncoding.size();
	while (index < gridSize * gridSize) {
		while (rightIndex < length
				and this->isDigit(runLengthEncoding[rightIndex])) {
			rightIndex++;
		}
		if (rightIndex != length - 1) {
			int temp = stoi(
					runLengthEncoding.substr(leftIndex,
							rightIndex - leftIndex));
			for (int i = 0; i < temp; i++) {
				string path =
						blockType ?
								"pics/misc/block/grass_block_top.png" :
								"pics/misc/block/bedrock.png";
				this->blocks.push_back(
						Block((index % this->gridSize) * this->blockSize,
								(index / this->gridSize) * this->blockSize,
								blockSize, blockType, path, this));
				index++;
			}
			blockType = not blockType;
			rightIndex++;
			leftIndex = rightIndex;
		}
	}
}

void World::spawnEnemies(const int &number) {
	do {
		int randX = rand() % (this->gridSize - 2) + 1;
		int randY = rand() % (this->gridSize - 2) + 1;

		if (isWalkable(randX, randY)) {
				this->enemies.push_back(Enemy(1, this, 20, 20));
		}

	} while (this->enemies.size() < (unsigned int) number);

}

void World::spawnItems(const int &number, const int &level) {
	do {
		int randX = rand() % (this->gridSize - 2) + 1;
		int randY = rand() % (this->gridSize - 2) + 1;

		if (isWalkable(randX, randY)) {
			this->items.push_back(new Potion("", 1, 1, 1, nullptr));
		}

	} while (this->enemies.size() < (unsigned int) number);

}

int World::update(string direction) {
  	int change = 0; //um die Anzeige zu aendern
	player->move(direction);
    int x = player->getX();
    int y = player->getY();
    
  	if(distanceToFight()){
        auto it = enemies.begin(); 
        while (!(it->getX() + blockSize <= x &&  it->getX() - blockSize >= x &&
               it->getY() + blockSize <= y &&  it->getY() - blockSize >= y)) {
            it++;
        }
      //player->attack(it); //existiert noch nicht
      change += 1;
    }
    
  	if(potionToDrink()){
        int x = player->getX();
        int y = player->getY();

        auto it = items.begin(); 
        /*while (it->getX() != x || it->getY() == y) {
            it++;
        }*/
        //player->drinkPotion(it);
    }
    
  	moveEnemies();
    
  	if(distanceToFight()){
     // *distanceToFight()->attack(player);
      change += 2;
    }
  	return change;
}

bool World::distanceToFight(){
    int x = player->getX();
    int y = player->getY();
    
  	auto it = enemies.begin(); 
  	while (it != enemies.end()) {
        if(it->getX() + blockSize <= x &&  it->getX() - blockSize >= x &&
           it->getY() + blockSize <= y &&  it->getY() - blockSize >= y){
          return true;
        }
        it++;
	}
   
    return false;
}

bool World::potionToDrink(){ //noch nicht in includes
  	int x = player->getX();
  	int y = player->getY();
  
  	auto it = items.begin(); 
  	/*while (it != items.end()) {
    if(it->getX() == x && it->getY() == y){ 
      return true;
    }
    it++;
	}*/
  return false;
}

             
const bool World::isWalkable(const int &row, const int &col) {

	int index = row * this->gridSize + col;

	return this->blocks[index].getIsWalkable();
}

const int& World::getGridSize() const {
	return this->gridSize;
}

const int& World::getBlockSize() const {
	return this->blockSize;
}

const vector<Block>* World::getBlocks() const {
	return &(this->blocks);
}

#endif /* WORLD_HPP_ */
