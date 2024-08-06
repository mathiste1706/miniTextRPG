#ifndef ARMOR_HPP
#define ARMOR_HPP
#include "Equipment.hpp"

class Armor: public Equipment
{
	public:
		Armor(std::string name, int attribute);
		~Armor() override;
};

#endif // ARMOR_HPP
