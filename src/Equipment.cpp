#include "Equipment.hpp"


Equipment:: Equipment(): _type(0), _name("PLACE_HOLDER"), _attribute(1){}

Equipment:: Equipment(bool type, std :: string name, int attribute): _type(type), _name(name), _attribute(attribute){}


// Destroyer

Equipment:: ~Equipment(){}

// Getter, Setter

void Equipment::setType(bool newType){

	_type=newType;
}

void Equipment:: setName(std :: string newName){

	_name=newName;
}
void Equipment::setAttribute(int newAttribute){

	_attribute=newAttribute;
}

bool Equipment:: getType() const{

	return _type;
}

std :: string Equipment:: getName() const{

	return _name;
}

int Equipment:: getAttribute() const{

	return _attribute;
}

// Specific Methods
void Equipment:: showDesc(){

	std :: cout << _name << " grants you " << _attribute;

	if (_type==1){
		std :: cout << " Def" << std:: endl;
	}

	else{
		std :: cout << " Atk" << std:: endl;
	}
}
