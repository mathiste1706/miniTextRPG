#include "Armor.hpp"
using namespace std;

Armor::Armor(string name, int attribute): Equipment(name, attribute){}
Armor::Armor(Equipment equipment): Equipment(equipment.getName(), equipment.getAttribute()){}

Armor::~Armor(){}
