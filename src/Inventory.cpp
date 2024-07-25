#include "Inventory.hpp"

Inventory::Inventory()
{
	//ctor
}

Inventory::~Inventory()
{
	//dtor
}

void Inventory:: addLoot(Equipment newLoot){

	_objectList.push_back(newLoot);

}
