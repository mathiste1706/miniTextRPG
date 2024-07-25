#include "Character.hpp"
#include "PlayerCharacter.hpp"
#include "EnemyCharacter.hpp"

using namespace std;



// Constructors

Character:: Character(): _name("placeholder"), _Lvl(1), _HP(100), _MP(30), _Con(4), _Mg(6), _Atk(10), _Def(5), _Ag(5), _Weapon(Equipment(0, "Rusted sword", 1)), _Armor(Equipment(1, "Rusted armor", 1)) {}

Character:: Character(string name): _name(name), _Lvl(1), _HP(100), _MP(30), _Con(4), _Mg(6), _Atk(10), _Def(5), _Ag(5), _Weapon(Equipment(0, "Rusted sword", 1)), _Armor(Equipment(1, "Rusted armor", 1)) {}		 // Con=4 -> Hp=4*25=100, Mg=6 -> MP=6*5=30

Character:: Character(string name, int Lvl, int Con, int Mg, int Atk, int Def, int Ag, Equipment Weapon, Equipment Armor): _name(name), _Lvl(Lvl), _HP(Con*25), _MP(Mg*5), _Con(Con), _Mg(Mg), _Atk(Atk), _Def(Def), _Ag(Ag), _Weapon(Weapon), _Armor(Armor) {}


// Destroyer

Character:: ~Character(){}


// Specific Methods

void Character:: showStatus() const{

	cout << _name << " has " << _HP << " HP and " << _MP << " MP.\n";

}
void Character:: diminishMP(int MPCost){
int newMP=_MP-MPCost;
	setMP(newMP);
}


void Character:: diminishHP(int damage){

	int HPDamage=round(damage-0.5*(_Def+_Armor.getAttribute()));
	if (HPDamage<0){
		HPDamage=0;
	}
	cout<<" for " << HPDamage << " damage!" << endl;
	int newHP=getHP() - HPDamage;
	if (newHP<0){
		newHP=0;
	}
	setHP(newHP);
}


void Character:: attack(Character  &target) const{


	int damage=_Atk + _Weapon.getAttribute();

	cout<< _name<< " attacks " << target.getName();

	int hitChance=_Ag*randomNumberAdd(1, 100);
	this_thread::sleep_for(chrono::milliseconds(50));		// to be certain the seed is different
	int dodgeChance=target.getAg()*randomNumberAdd();

	if (dodgeChance<hitChance){

		target.diminishHP(damage);
	}

	else {
		cout << ".\n" << target.getName() << " managed to dodge!\n";
	}

}

void Character::castOffensiveSpell(Spell &spell, Character &target){

	int power=_Mg+spell.getPower();

	cout<< _name << " attacks " << target.getName();

	int hitChance=_Ag*randomNumberAdd(1, 100);
	this_thread::sleep_for(chrono::milliseconds(50));		// to be certain the seed is different
	int dodgeChance=target.getAg()*randomNumberAdd();

	if (dodgeChance<hitChance){

		target.diminishHP(power);
	}

	else {
		cout << ".\n" << target.getName() << " managed to dodge!\n";
	}


}

void Character:: castHealingSpell(Spell &spell, Character &target){

	int power=power-6;		//power gotten from _Mg
	if (power<0){
		power=0;
	}

	power+=spell.getPower();
	int newHP=power*12;


	cout<< _name << " heals " << target.getName() << " for " << newHP << " HP!\n";
	newHP+=target.getHP();

	if (newHP>_Con*25){
		newHP=_Con*25;
	}

	target.setHP(newHP);



}

void Character:: castBuffingSpell(Spell &spell, Character &target){}
void Character:: castDebuffingSpell(Spell &spell, Character &target){}


void Character:: checkIfDied(vector <Character *> &targetList, int choiceTarget) const {

	if (targetList[choiceTarget-1]->isAlive()==false){
		cout << targetList[choiceTarget-1]->getName() << " has died!\n";
		targetList.erase(targetList.begin()+(choiceTarget-1));
	}
}


int Character:: selectTargetPlayer(vector <Character *> &targetList){


	int choiceTarget=0;

	do {

		cout<< "(type 0 to go back) Select your target: \n";

		for (int i=0; i<targetList.size(); i++){
				cout << " > " << i+1 << ": " << targetList[i]->getName() << endl;
		}

		cin>> choiceTarget;

		if (choiceTarget<0 || choiceTarget>targetList.size()) {
			cout << "!Wrong input!" << endl;
		}

	} while (choiceTarget<0 || choiceTarget>targetList.size());

	return choiceTarget;

}

int Character:: selectTargetPlayer(bool ally_enemy){

int choiceTarget=0;

	do{

		cout<< "(type 0 to go back) Confirm your target: \n1 > All";

		if (ally_enemy){
			cout << "Enemies\n";
		}

		else cout << "Allies\n";

		cin>> choiceTarget;

		if (choiceTarget!=0 || choiceTarget!=1) {
			cout << "!Wrong input!" << endl;
		}


	} while (choiceTarget!=0 || choiceTarget!=1);


	return choiceTarget;
}


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


void Character:: playerTurn(std::vector <Character *> &playerList, std::vector <Character *> &enemyList){

	int finishedTurn=0;
	int choice=0;
	int MPCost=-1;
	int choiceTarget=0;

	while (finishedTurn!=1){
		cout<< "\nWhat do you want to do ?\n > 1: Attack\n > 2: Magic\n" << endl;
		cin >> choice;

		while (choice !=1 && choice !=2){
				cout << "!Wrong input!" << endl;
				cout<< "What do you want to do ?\n > 1: Attack\n > 2: Magic\n" << endl;
				cin >> choice;
		}



		switch (choice){
			case 1: 	//Physical attack

				choiceTarget=selectTargetPlayer(enemyList);

				if (choiceTarget!=0){
					attack(*enemyList[choiceTarget-1]);
					checkIfDied(enemyList, choiceTarget);
					finishedTurn=1;

				}

				break;

			case 2:		//Magic

				int choiceSpell=0;

				do {
					do {
						cout<<"MAGIC:\n";

						cout << "(type 0 to come back) What do you want to cast?\n";
						for (int i=0; i < (getSpellList().size()); i++){
								cout << " > " << i+1 << ": ";
								getSpellList()[i].showAtrributes();

						}


						cin>> choiceSpell;

						if ((choiceSpell<0) || (choiceSpell>getSpellList().size())){
							cout << "!Wrong input!" << endl;
						}

						else if (choiceSpell!=0){
								MPCost=getSpellList()[choiceSpell-1].getMPCost();
						}



					if (getMP()<MPCost && choiceSpell!=0){
							cout << "Not Enough Mana! Choose another action!\n";
						}

					} while((choiceSpell<0 || choiceSpell>getSpellList().size()) || (getMP()<MPCost && choiceSpell!=0 && MPCost!=1));

					if (choiceSpell!=0){


						if ((getSpellList()[choiceSpell-1].getType())%2!=0){

								choiceTarget=selectTargetPlayer(getSpellList()[choiceSpell-1].getType());

								if (choiceTarget!=0){
									finishedTurn=1;
									diminishMP(getSpellList()[choiceSpell-1].getMPCost());

									if (getSpellList()[choiceSpell-1].getType()==1 || getSpellList()[choiceSpell-1].getType()==7){

										for (int i=0; i<enemyList.size();i++){
											castOffensiveSpell(getSpellList()[choiceSpell-1], *enemyList[i]);
											checkIfDied(enemyList, choiceTarget);
										}
									}

									else if (getSpellList()[choiceSpell-1].getType()==3 || getSpellList()[choiceSpell-1].getType()==5){

										for (int i=0; i<playerList.size();i++){
											castHealingSpell(getSpellList()[choiceSpell-1], *playerList[i]);
										}
									}

									else {
										 cout<< "!Wrong function call! The dev is a dimwit\n\tLOCATION playerTurn TargetAll (line 454)\n";
									}

								}
						}


						else {
							if (getSpellList()[choiceSpell-1].getType()==0 || getSpellList()[choiceSpell-1].getType()==6 ){

								choiceTarget=selectTargetPlayer(enemyList);
							}

							else if (getSpellList()[choiceSpell-1].getType()==2 || getSpellList()[choiceSpell-1].getType()==4 ){

								choiceTarget=selectTargetPlayer(playerList);
							}

							else {
								cout<< "!Wrong function call! The dev is a dimwit\n\tLOCATION playerTurn selectTarget Single (line 474)\n";
							}
						}

						if (choiceTarget!=0){
							finishedTurn=1;

							diminishMP(getSpellList()[choiceSpell-1].getMPCost());

							if (getSpellList()[choiceSpell-1].getType()==0 || getSpellList()[choiceSpell-1].getType()==6 ){


								castOffensiveSpell(getSpellList()[choiceSpell-1], *enemyList[choiceTarget-1]);
								checkIfDied(enemyList, choiceTarget);

							}

							else if (getSpellList()[choiceSpell-1].getType()==2 || getSpellList()[choiceSpell-1].getType()==4 ){

								castHealingSpell(getSpellList()[choiceSpell-1], *playerList[choiceTarget-1]);

							}

							else {
								cout<< "!Wrong function call! The dev is a dimwit\n\tLOCATION playerTurn castSpell (line 497)\n";
							}



						}

					}

				}while(finishedTurn==0);

				break;
			}



		}

}

void Character:: enemyTurn(vector <Character *> &playerList, vector <Character *> &enemyList){}


