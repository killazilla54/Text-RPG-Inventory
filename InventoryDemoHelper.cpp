#include "InventoryDemoHelper.h"
#include "Item.h"
#include <iostream>
#include <string>
using namespace std;


/*
Initialize a beginning state for the character inventory for the purposes of this demo.
*/
void InventoryDemoHelper::initializeInventory(Inventory* inventory) {
	//common items
	Item* basicHelm = new Item("Leather Cap", "common", "head",0,1);
	Item* basicMail = new Item("Leather Vest", "common", "chest", 0, 1);
	Item* basicLegs = new Item("Leather Greaves", "common", "legs", 0, 1);
	Item* basicSword = new Item("Short Sword", "common", "rightHand", 2,0);
	Item* basicDagger = new Item("Dagger", "common", "rightHand", 1, 0);
	Item* basicShield = new Item("Wooden Shield", "common", "leftHand", 0, 1);

	//Equip these as default loadout
	inventory->equipItem(*basicHelm);
	inventory->equipItem(*basicMail);
	inventory->equipItem(*basicLegs);
	inventory->equipItem(*basicDagger);
	inventory->equipItem(*basicShield);

	//Put the rest in the backpack
	inventory->addItemToBackpack(*basicSword);

	//rare items

	Item* rareHelm = new Item("Soldier Helm", "rare", "head", 0, 2);
	Item* rareMail = new Item("Soldier Chainmail", "rare", "chest",0,2);
	Item* rareLegs = new Item("Soldier Greaves", "rare", "legs",0,2);
	Item* longSword = new Item("Long Sword", "rare", "rightHand",3,0);
	Item* mace = new Item("Spiked Mace", "rare", "rightHand",2,1);
	Item* rareShield = new Item("Kite Shield", "rare", "leftHand",0,3);

	inventory->addItemToBackpack(*rareHelm);
	inventory->addItemToBackpack(*rareMail);
	inventory->addItemToBackpack(*rareLegs);
	inventory->addItemToBackpack(*mace);
	inventory->addItemToBackpack(*longSword);
	inventory->addItemToBackpack(*rareShield);

	//legendary items
	Item* legendaryHelm = new Item("Iron Helm", "legendary", "head",0,5);
	Item* legendaryMail = new Item("Iron Platemail", "legendary", "chest",0,5);
	Item* legendaryLegs = new Item("Iron Greaves", "legendary", "legs",0,5);
	Item* legendarySword = new Item("Greatsword", "legendary", "rightHand",5,0);
	Item* legendaryShield = new Item("Tower Shield", "legendary", "leftHand", 0, 8);
	Item* legendaryShield2 = new Item("Spiked Shield", "legendary", "leftHand",2,5);
	
	inventory->addItemToBackpack(*legendaryHelm);
	inventory->addItemToBackpack(*legendaryMail);
	inventory->addItemToBackpack(*legendaryLegs);
	inventory->addItemToBackpack(*legendarySword);
	inventory->addItemToBackpack(*legendaryShield);
	inventory->addItemToBackpack(*legendaryShield2);

	//Mythic items
	Item* mythicHelm = new Item("Helm of the Destroyer", "mythic", "head",3,10);
	Item* mythicLance = new Item("Javalin of Light", "mythic", "rightHand",15,0);
	Item* mythicLegs = new Item("Boots of Hermes", "mythic", "legs",0,6);

	inventory->addItemToBackpack(*mythicHelm);
	inventory->addItemToBackpack(*mythicLance);
	inventory->addItemToBackpack(*mythicLegs);
	
}

void InventoryDemoHelper::printFullInventory(Inventory* inventory) {
	cout << "----------------------------" << endl;
	cout << "----- Equipped Loadout -----" << endl;
	cout << "----------------------------" << endl;
	Item* headItem = inventory->getItemInSlot("head");
	Item* chestItem = inventory->getItemInSlot("chest");
	Item* legsItem = inventory->getItemInSlot("legs");
	Item* rightHandItem = inventory->getItemInSlot("rightHand");
	Item* leftHandItem = inventory->getItemInSlot("leftHand");

	string headStats = NONE;
	string chestStats = NONE;
	string legStats = NONE;
	string rightHandStats = NONE;
	string leftHandStats = NONE;
	if (headItem != nullptr) {
		headStats = headItem->printItemStats();
	}
	cout << "Head: " << headStats << endl;
	if (chestItem != nullptr) {
		chestStats = chestItem->printItemStats();
	}
	cout << "Chest: " << chestStats << endl;
	if (legsItem != nullptr) {
		legStats = legsItem->printItemStats();
	}
	cout << "Legs: " << legStats << endl;
	if (rightHandItem != nullptr) {
		rightHandStats = rightHandItem->printItemStats();
	}
	cout << "Right Hand: " << rightHandStats << endl;
	if (leftHandItem != nullptr) {
		leftHandStats = leftHandItem->printItemStats();
	}
	cout << "Left Hand: " << leftHandStats << endl;

	vector<Item*> copy = inventory->getBackpack();
	cout << "----------------------------" << endl;
	cout << "--------- Backpack ---------" << endl;
	cout << "----------------------------" << endl;
	if (copy.size() == 0) {
		cout << "*Backpack is Empty*" << endl;
	}
	for (int i = 0; i < copy.size(); i++) {
		string stats = copy[i]->printItemStats();
		cout << i + 1 << "." << stats << endl;
	}
}

void InventoryDemoHelper::handlePrintLoadout(Inventory* inventory)
{
	cout << "----------------------------" << endl;
	cout << "----- Equipped Loadout -----" << endl;
	cout << "----------------------------" << endl;
	int attackRating = 0;
	int defenseRating = 0;

	Item* headSlot = inventory->getItemInSlot("head");
	cout << "Head: ";
	if (headSlot != nullptr) {
		cout << headSlot->printItemStats() << endl;
		attackRating += headSlot->getAttack();
		defenseRating += headSlot->getDefense();
	} else {
		cout << NONE << endl;
	}
	Item* chestSlot = inventory->getItemInSlot("chest");
	cout << "Chest: ";
	if (chestSlot != nullptr) {
		cout << chestSlot->printItemStats() << endl;
		attackRating += chestSlot->getAttack();
		defenseRating += chestSlot->getDefense();
	} else {
		cout << NONE << endl;
	} 
	Item* legsSlot = inventory->getItemInSlot("legs");
	cout << "Legs: ";
	if (legsSlot != nullptr) {
		cout << legsSlot->printItemStats() << endl;
		attackRating += legsSlot->getAttack();
		defenseRating += legsSlot->getDefense();
	} else {
		cout << NONE << endl;
	}
	Item* rightHandSlot = inventory->getItemInSlot("rightHand");
	cout << "Right Hand: ";
	if (rightHandSlot != nullptr) {
		cout << rightHandSlot->printItemStats() << endl;
		attackRating += rightHandSlot->getAttack();
		defenseRating += rightHandSlot->getDefense();
	} else {
		cout << NONE << endl;
	}
	Item* leftHandSlot = inventory->getItemInSlot("leftHand");
	cout << "Legs: ";
	if (leftHandSlot != nullptr) {
		cout << leftHandSlot->printItemStats() << endl;
		attackRating += leftHandSlot->getAttack();
		defenseRating += leftHandSlot->getDefense();
	} else {
		cout << NONE << endl;
	}
	/*cout << "Chest: " << getItemInSlot("chest")->printItemStats() << endl;
	cout << "Legs: " << getItemInSlot("legs")->printItemStats() << endl;
	cout << "Right Hand: " << getItemInSlot("rightHand")->printItemStats() << endl;
	cout << "Left Hand: " << getItemInSlot("leftHand")->printItemStats() << endl;*/
	cout << "----------------------------" << endl;
	cout << "---------- Stats -----------" << endl;
	cout << "----------------------------" << endl;
	cout << "Total Attack: " << to_string(attackRating) << endl;
	cout << "Total Defense: " << to_string(defenseRating) << endl;

}

void InventoryDemoHelper::handleEquipSelection(Inventory* inventory)
{
	cout << "----------------------------" << endl;
	cout << "--------- Backpack ---------" << endl;
	cout << "----------------------------" << endl;
	//Print list of backpack items with a number
	vector<Item*> copy = inventory->getBackpack();
	for (int i = 0; i < (int)copy.size(); i++) {
		string stats = copy[i]->printItemStats();
		cout << i + 1 << ". " << stats << endl;
	}
	
	bool valid = false;
	int x{};
	while (!valid) {
		cout << "Enter the number of the item you want to equip:" << endl;
		cout << ">";
		cin >> x;
		if (x <= 0 || x > (int)copy.size()) {
			cout<< "***Invalid item number***" << endl;
		}
		else {
			valid = true;
		}
		cin.ignore();
	}
	
	Item* itemToEquip = inventory->removeItemFromBackpack(x-1);
	inventory->equipItem(*itemToEquip);
}

void InventoryDemoHelper::handleUnequipSelection(Inventory* inventory)
{
	string input;
	bool valid = false;
	while (!valid) {
		cout << "----------------------------" << endl;
		cout << "Enter the slot you want to unequip:" << endl;
		cout << "Options are: head, chest, legs, rightHand, leftHand" << endl;
		cout << "> ";
		getline(cin, input);
		if (input == "head" || input == "chest" || input == "legs" || input == "leftHand" || input == "rightHand") {
			valid = true;
		}
		else {
			cout << "***Invalid slot***" << endl;
		}
	}
	inventory->unEquipItem(input);
}

