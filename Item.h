#ifndef ITEM
#define ITEM
#include <string>
#include <map>
using namespace std;
class Item
{

public:
	
	Item();
	~Item();
	Item(string name, string rarity, string slotType, int attack, int defense);

	string getName();
	string getRarity();
	string getSlotType();
	int getAttack();
	int getDefense();
	virtual string printItemStats();
private:
	string name;
	string rarity;
	string slotType;
	int attack;
	int defense;
};

#endif

