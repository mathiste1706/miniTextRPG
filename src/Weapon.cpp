#include "Weapon.hpp"
using namespace std;

Weapon::Weapon(string name, int attribute): Equipment(name, attribute){}
Weapon::Weapon(Equipment equipment): Equipment(equipment.getName(), equipment.getAttribute()){}

Weapon::~Weapon(){}
