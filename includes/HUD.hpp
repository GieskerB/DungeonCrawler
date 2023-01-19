#ifndef HUD_HPP_
#define HUD_HPP_

//#include <alogviz/SVG.hpp>
#include "SVG.hpp"
#include "items.hpp"
#include "World.hpp"
#include "Player.hpp"
#include <list>
#include <vector>

class HUD {

private:

	// Upper Right Corner:
	list<Image> effects;
	vector<string> effectsStr;
	const static int effectSize, effectSpaceing;
	// Bottom Left Corner:
	Image inventory;
	const static int itemSize, itemSpaceing;
	// Bottom Right Corner:
	Image backGround;
	Text health, defense;

	// World/Player pointer
	World* world;
	Player* player;

public:

	HUD(World * world, Player* player);

	void add(Item *item) const;

	void add(const string &effect) ;

	void updateDefense();

	void updateHealth();

};

#endif /* HUD_HPP_ */
