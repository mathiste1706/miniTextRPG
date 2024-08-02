#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>

#include "Weapon.hpp"
#include "Armor.hpp"
#include "SpellDictionnary.hpp"
#include "Random.hpp"
#include "Display.hpp"

class Character{

protected:
	// stats w/o equipment
	std:: string _name;
	int _Lvl;
	int _HP;
	int _MP;
	int _Con;
	int _Mg;
	int _Atk;
	int _Def;
	int _Ag;

	// objects equipped
	Weapon _Weapon;
	Armor _Armor;

	// Spells
	std::vector <Spell> _SpellList;


public:

	// Constructors

	Character();

	Character(std :: string name);

	Character(std :: string name, int Lvl, int Con, int Mg, int Atk, int Def, int Ag, Weapon Weapon, Armor Armor);


	// Destroyer

	~Character();

	// Getter, Setter

	void setName(std :: string newName){

	_name=newName; }

	void setLvl(int newLvl){

		_Lvl=newLvl; }

	void setHP(int newHP){

		_HP=newHP; }

	void setMP(int newMP){

		_MP=newMP; }

	void setCon(int newCon){

		_Con=newCon; }

	void setMg(int newMg){

		_Mg=newMg; }

	void setAtk(int newAtk){

		_Atk=newAtk; }

	void setDef(int newDef){

		_Def=newDef; }

	void setAg(int newAg){

		_Ag=newAg; }

	void setArmor(const Armor _equipment){
		_Armor.setName(_equipment.getName());
		_Armor.setAttribute(_equipment.getAttribute());
	}

	void setWeapon(const Weapon _equipment){
	_Weapon.setName(_equipment.getName());
	_Weapon.setAttribute(_equipment.getAttribute());
}

	std :: string getName() const{

		return _name; }

	int getLvl() const{

		return _Lvl; }

	int getHP() const{

		return _HP; }

	int getMP() const{

		return _MP; }

	int getCon() const{

		return _Con; }

	int getMg() const{

		return _Mg; }

	int getAtk() const{

		return _Atk; }

	int getDef() const{

		return _Def; }

	int getAg() const{

		return _Ag; }

	Armor getArmor() const{
		return _Armor;
	}

	Weapon getWeapon() const{
		return _Weapon;
	}

	std::vector <Spell> getSpellList() const{

	return _SpellList; }

	// Specific Methods

	void diminishHP(int const damage, Display &display);
	void diminishMP(int const MPCost);
	void attack(Character &target, Display &display) const;
	void replendishHPAndMP();
	bool isAlive() const;
	void LvlUp();
	void fillSpellListCharCreation();
	void fillSpellListLvlUp(int releventLvl);
	void castOffensiveSpell(Spell &spell, Character &target, Display &display);
	void castHealingSpell(Spell &spell, Character &target, Display &display);
	void castBuffingSpell(Spell &spell, Character &target, Display &display);
	void castDebuffingSpell(Spell &spell, Character &target, Display &display);




};


#endif // CHARACTER_HPP_INCLUDED
