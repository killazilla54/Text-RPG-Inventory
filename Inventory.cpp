#include "Inventory.h"
#include <iostream>


Inventory::Inventory() : backpack(0), head(nullptr), chest(nullptr), leftArm(nullptr), rightArm(nullptr), legs(nullptr) {
	
}

Inventory::~Inventory() {
	//Clean up pointer data
	delete head;
	delete chest;
	delete leftArm;
	delete rightArm;
	delete legs;
	for(int i = 0; i < backpack.size(); i++){
		Item* ptr = backpack.at(i);
		delete ptr;
	}
	backpack.clear();

}

void Inventory::setBackpack(vector<Item*> &itemList) {
	backpack = itemList;
}

vector<Item*>& Inventory::getBackpack()
{
	return backpack;
}

void Inventory::printFullInventory()
{
	for (int i = 0; i < backpack.size(); i++) {
		string stats = backpack[i]->printItemStats();

	}
}

void Inventory::printLoadout()
{
	int attackRating = 0;
	int defenseRating = 0;

	Item* headSlot = getItemInSlot("head");
	cout << "Head: ";
	if (headSlot != nullptr) {
		cout << headSlot->printItemStats() << endl;
		attackRating += headSlot->getAttack();
		defenseRating += headSlot->getDefense();
	} else {
		cout << "EMPTY" << endl;
	}
	cout << "Chest: " << getItemInSlot("chest")->printItemStats() << endl;
	cout << "Legs: " << getItemInSlot("legs")->printItemStats() << endl;
	cout << "Right Hand: " << getItemInSlot("rightHand")->printItemStats() << endl;
	cout << "Left Hand: " << getItemInSlot("leftHand")->printItemStats() << endl;

	


}

void Inventory::equipItem(Item& itemToEquip) {
	Item** tempSlot = nullptr;
	string slot = itemToEquip.getSlotType();
	if (slot == "head") {
		tempSlot = &head;
	} else if (slot == "leftHand") {
		tempSlot = &leftArm;
	} else if (slot == "rightHand") {
		tempSlot = &rightArm;
	} else if (slot == "legs") {
		tempSlot = &legs;
	} else if (slot == "chest") {
		tempSlot = &chest;
	} else {
		throw ("Invalid slot selection");
	}

	if (*tempSlot != nullptr) {
		addItemToBackpack(**tempSlot);
		cout << "Currently equipped " << (*tempSlot)->getName() << " was moved to the backpack" << endl;
	}
	(*tempSlot) = &itemToEquip;
	cout << itemToEquip.getName() << " equipped." << endl;
	
}

void Inventory::unEquipItem(const string slot)
{
	Item** tempSlot = nullptr;
	if (slot == "head") {
		tempSlot = &head;
	}
	else if (slot == "leftHand") {
		tempSlot = &leftArm;
	}
	else if (slot == "rightHand") {
		tempSlot = &rightArm;
	}
	else if (slot == "legs") {
		tempSlot = &legs;
	}
	else if (slot == "chest") {
		tempSlot = &chest;
	} else {
		throw ("Invalid slot selection");
	}

	if (*tempSlot != nullptr) {
		//message 
		
		cout << (*tempSlot)->getName() << " unequipped from " << slot << " slot and moved to backpack" << endl ;
		addItemToBackpack(**tempSlot);
		*tempSlot = nullptr;
	}
	else {
		cout << "There is no item currently equipped in the " << slot << " slot." << endl;
	}
}

void Inventory::addItemToBackpack(Item& itemToAdd)
{
	backpack.push_back(&itemToAdd);
}

Item* Inventory::removeItemFromBackpack(int index)
{
	Item* item = backpack[index];
	backpack.erase(backpack.begin() + index);
	return item;
}

Item* Inventory::getItemInSlot(const string slot)
{
	if (slot == "head") 
	{
		return head;
	}
	else if (slot == "leftHand") 
	{
		return leftArm;
	}
	else if (slot == "rightHand") 
	{
		return rightArm;
	}
	else if (slot == "legs") 
	{
		return legs;
	}
	else if (slot == "chest") 
	{
		return chest;
	}
	//Invalid value passed.
	return nullptr;
}



