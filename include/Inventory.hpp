#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <vector>
#include "Equipment.hpp"


class Inventory
{
	public:
		Inventory();
		~Inventory();

		int getGold() { return _gold; }
		void setGold(int newGolg) { _gold = newGolg; }
		std::vector <Equipment> getObjectList() { return _objectList; }
		void setObjectList(std::vector <Equipment> newObjectList) { _objectList = newObjectList; }

		void addLoot(Equipment newLoot);

	protected:

	private:
		int _gold;
		std::vector <Equipment> _objectList;
};

#endif // INVENTORY_HPP
