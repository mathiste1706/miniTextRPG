#include "Weapon.hpp"
using namespace std;

Weapon::Weapon(string name, int attribute): Equipment(name, attribute){}

Weapon::~Weapon()= default;
