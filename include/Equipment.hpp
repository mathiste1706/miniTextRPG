#ifndef EQUIPMENT_HPP_INCLUDED
#define EQUIPMENT_HPP_INCLUDED

#include <iostream>
class Equipment{

private:
	bool _type; 		// 0=Weapon and 1=Armor
	std::string _name;
	int _attribute;

public:
	// Constructors

	Equipment();

	Equipment(bool type, std :: string name, int attribute);


	// Destroyer

	~Equipment();

	// Getter, Setter
	void setType(bool newType);
	void setName(std :: string newName);
	void setAttribute(int newAttribute);

	bool getType() const;
	std :: string getName() const;
	int getAttribute() const;

	// Specific Methods
	void showDesc();


};


#endif // EQUIPMENT_HPP_INCLUDED
