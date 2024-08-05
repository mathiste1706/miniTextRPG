#include "Character.hpp"
#include "PlayerCharacter.hpp"
#include "EnemyCharacter.hpp"

using namespace std;



// Constructors

Character:: Character(): _name("placeholder"), _Lvl(1), _HP(100), _MP(30), _Con(4), _Mg(6), _Atk(10), _Def(5), _Ag(5), _Weapon(Weapon("Rusted sword", 1)), _Armor(Armor("Rusted armor", 1)) {}

Character:: Character(string name): _name(name), _Lvl(1), _HP(100), _MP(30), _Con(4), _Mg(6), _Atk(10), _Def(5), _Ag(5), _Weapon(Weapon("Rusted sword", 1)), _Armor(Armor("Rusted armor", 1)) {}		 // Con=4 -> Hp=4*25=100, Mg=6 -> MP=6*5=30

Character:: Character(string name, int Lvl, int Con, int Mg, int Atk, int Def, int Ag, const Weapon& Weapon, const Armor& Armor): _name(name), _Lvl(Lvl), _HP(Con*25), _MP(Mg*5), _Con(Con), _Mg(Mg), _Atk(Atk), _Def(Def), _Ag(Ag), _Weapon(Weapon), _Armor(Armor) {}

Character:: Character(const PlayerCharacter * pPlayerChara): _name(pPlayerChara->getName()), _Lvl(pPlayerChara->getLvl()), _HP(pPlayerChara->getHP()), _MP(pPlayerChara->getMP()), _Con(pPlayerChara->getCon()), _Mg(pPlayerChara->getMg()), _Atk(pPlayerChara->getAtk()), _Def(pPlayerChara->getDef()), _Ag(pPlayerChara->getAg()), _Weapon(pPlayerChara->getWeapon()), _Armor(pPlayerChara->getArmor()){}

Character:: Character(const EnemyCharacter * pEnemyhCara): _name(pEnemyhCara->getName()), _Lvl(pEnemyhCara->getLvl()), _HP(pEnemyhCara->getHP()), _MP(pEnemyhCara->getMP()), _Con(pEnemyhCara->getCon()), _Mg(pEnemyhCara->getMg()), _Atk(pEnemyhCara->getAtk()), _Def(pEnemyhCara->getDef()), _Ag(pEnemyhCara->getAg()), _Weapon(pEnemyhCara->getWeapon()), _Armor(pEnemyhCara->getArmor()){}


// Destroyer

Character:: ~Character(){}


// Specific Methods


void Character:: diminishMP(int MPCost){
int newMP=_MP-MPCost;
	setMP(newMP);
}


void Character:: diminishHP(int damage){

	int HPDamage=round(damage-0.5*(_Def+_Armor.getAttribute()));
	if (HPDamage<0){
		HPDamage=0;
	}

	Display:: diminishHP(HPDamage);
	int newHP=getHP() - HPDamage;
	if (newHP<0){
		newHP=0;
	}
	setHP(newHP);
}


void Character:: attack(Character  &target) const{


	int damage=_Atk + _Weapon.getAttribute();

	Display:: attack(*this, target);

	int hitChance=_Ag*randomNumberAdd(1, 100);
	this_thread::sleep_for(chrono::milliseconds(50));		// to be certain the seed is different
	int dodgeChance=target.getAg()*randomNumberAdd();

	if (dodgeChance<hitChance){

		target.diminishHP(damage);
	}

	else {
		Display:: dodge(target);
	}

}

void Character::castOffensiveSpell(Spell &spell, Character &target) const{

	int power=_Mg+spell.getPower();

	Display::castOffensiveSpell(*this, spell, target);

	int hitChance=_Ag*randomNumberAdd(1, 100);
	this_thread::sleep_for(chrono::milliseconds(50));		// to be certain the seed is different
	int dodgeChance=target.getAg()*randomNumberAdd();

	if (dodgeChance<hitChance){

		target.diminishHP(power);
	}

	else {
		Display:: dodge(target);
	}


}

void Character:: castHealingSpell(Spell &spell, Character &target){

	int power=this->getMg()+spell.getPower()-6;		//power gotten from _Mg
	if (power<1){
		power=1;
	}

	power+=spell.getPower();
	int newHP=power*12;


	Display:: castHealingSpell(*this, spell, target, newHP);
	newHP+=target.getHP();

	if (newHP>_Con*25){
		newHP=_Con*25;
	}

	target.setHP(newHP);



}

void Character:: castBuffingSpell(Spell &spell, Character &target){}
void Character:: castDebuffingSpell(Spell &spell, Character &target){}


void Character:: replendishHPAndMP(){

	setHP(_Con*25);
	setMP(_Mg*5);
}

bool Character:: isAlive() const{

	bool boolIsAlive=1;
	if (_HP<=0){
		boolIsAlive=0;
	}
	return boolIsAlive;
}

void Character:: LvlUp(){
	_Lvl++;
}

void Character:: fillSpellListCharCreation(){
	for (int i=1; i<=_Lvl; i++){
		fillSpellListLvlUp(i);
	}
}

void Character:: fillSpellListLvlUp(int releventLvl){




	switch(releventLvl){

	case 1:

		_SpellList.push_back(spellDictionnary.find("fire_bout") ->second);
		_SpellList.push_back(spellDictionnary.find("heal")->second);
		break;

	case 2:
		_SpellList.push_back(spellDictionnary.find("fireball")->second);
		_SpellList.push_back(spellDictionnary.find("mass_heal")->second);


	}

}



