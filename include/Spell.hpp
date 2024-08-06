#ifndef SPELL_HPP_INCLUDED
#define SPELL_HPP_INCLUDED

#include <iostream>

class Spell{

// type
// 0: Offensive
// 2: Heal
// 4: Buff
// 6: Debuff

// 0: Single Target
// 1: All

// affectedStat
// 1: Atk
// 2: Mg
// 3: Def
// 4: Ag


protected:
	std :: string _name;
	std :: string _desc;
	int _type;
	int _power;
	int _MPCost;
	int _turnDuration;
	int _affectedStat;

public:

	// Constructors

	Spell();

	Spell(std :: string name, std:: string desc, int type, int power, int MPCost);

	Spell(std :: string name, std :: string desc, int type, int power, int MPCost, int turnDuration, int affectedStat);


	// Destroyer

	 ~Spell();

	// Getter, Setter

	void setName(std :: string newName){

		_name=newName;
	}

	void setDesc(std :: string newDesc){

		_desc=newDesc;
	}


	void setType(int newType){

		_type=newType;
	}

	void setPower(int newPower){

		_power=newPower;
	}




	std :: string getName() const{

		return _name;
	}


	std :: string getDesc() const{

		return _desc;
	}

	int getType() const{

		return _type;
	}

	int getPower() const{

		return _power;
	}

	int getMPCost() const{

		return _MPCost;
	}

	int getTurnDuration() const{
	return _turnDuration;}
	int getAffectedStat() const{
	return _affectedStat;}

	void setTurnDuration(int const newTurnDuration){
	_turnDuration=newTurnDuration;}
	void setAffectedStat(int const newAffectedStat){
	_affectedStat=newAffectedStat;}
};


#endif // SPELL_HPP_INCLUDED
