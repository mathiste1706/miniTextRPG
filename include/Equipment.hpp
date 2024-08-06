#ifndef EQUIPMENT_HPP_INCLUDED
#define EQUIPMENT_HPP_INCLUDED

#include <iostream>
class Equipment{

private:

	std::string _name;
	int _attribute;

public:
	// Constructors

	Equipment(std:: string name, int attribute);


	// Destroyer

	// To force the class to be abstract
	 virtual ~Equipment()=default;

	// Getter, Setter
	void setName(std :: string newName);
	void setAttribute(int newAttribute);

	std :: string getName() const;
	int getAttribute() const;
};


#endif // EQUIPMENT_HPP_INCLUDED
