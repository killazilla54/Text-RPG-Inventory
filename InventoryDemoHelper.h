#ifndef INVENTORY_HELPER
#define INVENTORY_HELPER
#include "Inventory.h"
#include <string>

class InventoryDemoHelper
{
public:
	void initializeInventory(Inventory* inventory);
	void printFullInventory(Inventory* inventory);
	void handlePrintLoadout(Inventory* inventory);
	void handleEquipSelection(Inventory* inventory);
	void handleUnequipSelection(Inventory* inventory);
private:
	const string NONE = "*EMPTY*";
};

#endif