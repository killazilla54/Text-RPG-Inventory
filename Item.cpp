#include "Item.h"

Item::Item() {}
Item::~Item() {}

Item::Item(string name, string rarity, string slotType, int attack, int defense) {
	this->name = name;
	this->rarity = rarity;
	this->slotType = slotType;
	this->attack = attack;
	this->defense = defense;
}

//name
string Item::getName() {
	return name;
}
//rarity
string Item::getRarity() {
	return rarity;
}
//Slot
string Item::getSlotType() {
	return slotType;
}

int Item::getAttack() {
	return attack;
}

int Item::getDefense() {
	return defense;
}

string Item::printItemStats() {
	return name + " | " + rarity + " | " + slotType + " | ATK:"+ to_string(attack)+" | DEF:"+ to_string(defense) ;
}