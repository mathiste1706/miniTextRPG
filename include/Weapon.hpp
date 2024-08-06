#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Equipment.hpp"


class Weapon : public Equipment
{
	public:
		Weapon(std::string name, int attribute);
		~Weapon() override;
};

#endif // WEAPON_HPP
