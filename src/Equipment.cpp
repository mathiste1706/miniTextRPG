#include "Equipment.hpp"


Equipment:: Equipment(std :: string name, int attribute): _name(name), _attribute(attribute){}


// Destroyer

Equipment:: ~Equipment(){}

// Getter, Setter


void Equipment:: setName(std :: string newName){

	_name=newName;
}
void Equipment::setAttribute(int newAttribute){

	_attribute=newAttribute;
}


std :: string Equipment:: getName() const{

	return _name;
}

int Equipment:: getAttribute() const{

	return _attribute;
}
