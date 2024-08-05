#ifndef ARMOR_HPP
#define ARMOR_HPP
#include "Equipment.hpp"

class Armor: public Equipment
{
	public:
		Armor(std::string name, int attribute);
		Armor(const Equipment& equipment);
		~Armor();

	bool type() const{
	return 0;
	}
};

#endif // ARMOR_HPP
