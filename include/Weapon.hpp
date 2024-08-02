#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Equipment.hpp"


class Weapon : public Equipment
{
	public:
		Weapon(std::string name, int attribute);
		Weapon(Equipment equipment);
		~Weapon();

	bool type() const{
	return 1;
	}
};

#endif // WEAPON_HPP
