#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>

#include "Equipment.hpp"
#include "SpellDictionnary.hpp"
#include "Random.hpp"

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
	Equipment _Weapon;
	Equipment _Armor;

	// Spells
	std::vector <Spell> _SpellList;


public:

	// Constructors

	Character();

	Character(std :: string name);

	Character(std :: string name, int Lvl, int Con, int Mg, int Atk, int Def, int Ag, Equipment Weapon, Equipment Armor);


	// Destroyer

	virtual ~Character();

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

	std::vector <Spell> getSpellList() const{

	return _SpellList; }

	// Specific Methods

	void showStatus() const;
	int selectTargetPlayer(std::vector <Character *> &targetList);
	int selectTargetPlayer(bool ally_enemy);
	void checkIfDied(std::vector <Character *> &targetList, int choiceTarget) const;
	void diminishHP(int const damage);
	void diminishMP(int const MPCost);
	void attack(Character &target) const;
	void replendishHPAndMP();
	bool isAlive() const;
	void LvlUp();
	void fillSpellListCharCreation();
	void fillSpellListLvlUp(int releventLvl);
	void castOffensiveSpell(Spell &spell, Character &target);
	void castHealingSpell(Spell &spell, Character &target);
	void castBuffingSpell(Spell &spell, Character &target);
	void castDebuffingSpell(Spell &spell, Character &target);




};


#endif // CHARACTER_HPP_INCLUDED
