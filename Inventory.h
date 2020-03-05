#ifndef INVENTORY
#define INVENTORY
#include "Item.h"
#include <vector>



class Inventory
{
private:
	vector<Item*> backpack;
	Item* head;
	Item* leftArm;
	Item* rightArm;
	Item* legs;
	Item* chest;

public:
	Inventory();
	~Inventory();
	void setBackpack(vector<Item*> &itemList);//this should just be the constructor and any additions should use equip.
	//full loot pool will be implemeted in another class.
	vector<Item*> &getBackpack();
	void printFullInventory();
	//print function for just equiped items
	void printLoadout();
	void equipItem(Item& itemToEquip);
	void unEquipItem(const string slot);
	void addItemToBackpack(Item& itemToAdd);
	Item* removeItemFromBackpack(int index);
	Item* getItemInSlot(const string slot);
};

#endif