#include "Spell.hpp"

Spell:: Spell(): _name("PLACE_HOLDER"), _desc("PLACE_HOLDER"), _type(-1), _power(0), _MPCost(1000), _turnDuration(0), _affectedStat(0){}

Spell:: Spell(std :: string name, std :: string desc, int type, int power, int MPCost): _name(name), _desc(desc), _type(type), _power(power), _MPCost(MPCost), _turnDuration(0), _affectedStat(0){}

Spell:: Spell(std :: string name, std :: string desc, int type, int power, int MPCost, int turnDuration, int affectedStat): _name(name), _desc(desc), _type(type), _power(power), _turnDuration(turnDuration), _affectedStat(affectedStat){}


// Destroyer

Spell:: ~Spell(){}

// Specific Methods
void Spell:: showAtrributes() const{

	std :: cout << _name << "\t" << _desc << "\t" << _MPCost << " MP \n";

}
