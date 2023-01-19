#ifndef HUD_CPP_
#define HUD_CPP_

#include "../includes/HUD.hpp"

const int HUD::effectSize = 36;
const int HUD::effectSpaceing = 2 + effectSize; // Abstand + Bildbriete
const int HUD::itemSize = 32;
const int HUD::itemSpaceing = 4 + itemSize; // Abstand + Bildbriete

HUD::HUD(World *world, Player *player) {
	this->world = world;
	this->player = player;

	this->effects = list<Image>();
	this->effectsStr = vector<string>();

	this->inventory = Image("../pics/hud/inventory hud melee only.png", 112,
			this->world->getHeight() - 24, 224, 48, this->world);

	this->backGround = Image("../pics/hud/stats hud.png",
			this->world->getWidth() - 30, this->world->getHeight() - 20, 60, 40,
			this->world);
	this->health = Text("", 100, 100, world);
	this->updateHealth();
	this->defense = Text("", 100, 100, world);
	this->updateDefense();

}

void HUD::add(Item *item) const {
	int yMultiplier;
	if (item == nullptr) {
		return;
	} else if (dynamic_cast<Helmet*>(item) != nullptr) {
		yMultiplier = 0;
	} else if (dynamic_cast<Chestplate*>(item) != nullptr) {
		yMultiplier = 1;
	} else if (dynamic_cast<Leggings*>(item) != nullptr) {
		yMultiplier = 2;
	} else if (dynamic_cast<Boots*>(item) != nullptr) {
		yMultiplier = 3;
	} else if (dynamic_cast<Weapon*>(item) != nullptr) {
		yMultiplier = 4;
	} else {
		return;
	}

	item->toFront();
	item->setSize(itemSize, itemSize);
	item->moveTo(this->world->getHeight() - 20,
			4 + HUD::itemSize / 2 + HUD::itemSpaceing * yMultiplier);

}

void HUD::add(const string &effect) {

	for (auto iterator = this->effectsStr.begin();
			iterator != this->effectsStr.end(); iterator++) {
		if (*iterator == effect) {
			return;
		}
	}

	this->effectsStr.push_back(effect);

	Image newEffect = Image("../hud/effect/" + effect + ".png", -36, -36, 18,
			18, this->world);
	newEffect.setAttribute("image-rendering", "pixelated");
	newEffect.setSize(effectSize, effectSize);
	newEffect.moveTo(effectSize / 2,this->world->getWidth() - this->effects.size() * effectSpaceing - (2 + HUD::effectSize / 2));

	this->effects.push_back(newEffect);

}

void HUD::updateDefense() {
	// auf eine Nachkommastelle "runden"
	int def = ((int) (this->player->getDefense() * 1000) / 10.0);
	this->defense.setText(to_string(def) + "%");
}

void HUD::updateHealth() {
	// auf eine Nachkommastelle "runden"
	float hp = ((int) (this->player->getHp() * 10) / 10.0);
	float mhp = ((int) (this->player->getMaxHP() * 10) / 10.0);
	this->health.setText(to_string(hp) + "/" + to_string(mhp));
}

#endif /* HUD_CPP_ */
