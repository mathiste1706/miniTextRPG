#include <limits>
#include "Display.hpp"
#include "Character.hpp"  // it's only in .cpp to avoid circular dependencies
#include "PlayerCharacter.hpp" // it's only in .cpp to avoid circular dependencies
#include "EnemyCharacter.hpp" // it's only in .cpp to avoid circular dependencies

using namespace std;


void Display::wrongInput() {
	cout << "!Wrong input!" << endl;
}

void Display::notEnoughGold() {
	cout << "You do not have enough gold!\n";
}

void Display::showSpellAttributes(const Spell &spell) {
	cout << spell.getName() << "\t" << spell.getDesc() << "\t" << spell.getMPCost() << " MP \n";
}


void Display::showPlayerListAll(const vector<PlayerCharacter *>& playerList) {
	for (int i=0; i<playerList.size(); i++){
		cout << " > " << i+1 << " : " << playerList[i]->getName() <<endl;
	}
}

int Display::showPlayerListAlive(const vector<PlayerCharacter *>& playerList) {
	int nbPlayer=0;
	for (int i=0; i<playerList.size(); i++) {
		if (playerList[i]->isAlive()){
			cout << " > " << i+1 << " : " << playerList[i]->getName() <<endl;
			nbPlayer++;
		}
	}
	return nbPlayer;
}

int Display::showPlayerListDead(const vector<PlayerCharacter *>& playerList) {
	int nbPlayer=0;
	for (int i=0; i<playerList.size(); i++) {
		if (!playerList[i]->isAlive()){
			nbPlayer++;
			cout << " > " << nbPlayer << " : " << playerList[i]->getName() << endl;
		}
	}
	return nbPlayer;
}

int Display::showEnemyList(const std::vector<EnemyCharacter *> &enemyList) {
	int nbEnemy=0;
	for (int i=0; i<enemyList.size(); i++) {
		if (enemyList[i]->isAlive()){
			nbEnemy++;
			cout << " > " << nbEnemy << " : " << enemyList[i]->getName() << endl;
		}
	}
	return nbEnemy;
}


void Display:: showStatus(const Character* character) {

	cout << character->getName() << " has " << character->getHP() << " HP and " << character->getMP() << " MP.\n";

}

void Display:: showStatusAll(const vector<PlayerCharacter*> &playerList) {

	for (int i=0; i<playerList.size();i++){
		if (playerList[i]->isAlive()==true){
				showStatus(playerList[i]);
		}
	}
}

void Display:: showStatusAll(const vector<EnemyCharacter*> &enemyList) {

	for (int i=0; i<enemyList.size();i++){
		if (enemyList[i]->isAlive()==true){
				showStatus(enemyList[i]);
		}
	}
}

void Display::showStatusAll(const std::vector<PlayerCharacter *> &playerList, const std::vector<EnemyCharacter *> &enemyList) {
	showStatusAll(playerList);
	cout<<endl;
	showStatusAll(enemyList);

}


void Display:: attack(const Character &attacker, const Character  &target) {
	cout<< attacker.getName()<< " attacks " << target.getName();
}

void Display:: diminishHP(int HPDamage) {
	cout<<" for " << HPDamage << " damage!" << endl;
}

void Display:: dodge(const Character  &target) {
	cout << ".\n" << target.getName() << " managed to dodge!\n";
}

void Display::castOffensiveSpell(const Character &caster, const Spell &spell, const Character &target) {
	cout<<caster.getName()<<" cast "<<spell.getName()<< " on " << target.getName();
}

void Display::castHealingSpell(const Character &caster, const Spell &spell, const Character &target, int newHP) {
	cout<< caster.getName() <<" cast " << spell.getName()<< " and heals " << target.getName() << " for " << newHP << " HP!\n";
}

void Display:: showStats(const Character &character) {
	cout << character.getName() << " is level " << character.getLvl() << " and has " << character.getCon()
 << " Constitution that grants " << character.getCon()*25 << " HP, " << character.getMg() << " Magic that gives " << character.getMg()*5 << " MP, " << character.getAtk() << " Attack, " << character.getDef() << " Defense, " << character.getAg() << " Agility.\n";
}

void Display:: showWeapon(const Weapon &weapon) {
	cout << weapon.getName() << " grants you " << weapon.getAttribute() << " Atk\n";

}

void Display:: showArmor(const Armor &armor) {
	cout << armor.getName() << " grants you " << armor.getAttribute() << " Def\n";

}

void Display:: showStatsAndEquipment(const Character &character) {
	showStats(character);
	showWeapon(character.getWeapon());
	showArmor(character.getArmor());
}

void Display::whoTrain() {
	cout << "(type 0 to go back) Who do you want to train?\n";
}

void Display::showStatsOf() {
	cout <<"This is the current Stats of ";
}

void Display::increaseWhichStats() {
	cout << "(type 0 to go back) What stat do you want to increase?\n > 1 Con\n 2 > Mg\n 3 > Atk\n 4 > Def\n 5 > Ag\n > ";
}
void Display::alreadyMaxTrained( const PlayerCharacter * playerChara, const string& statName) {
	cout <<  playerChara->getName() << "has already trained " << statName << " to the maximum!\n";
}

void Display::showStatup(int const newStatValue, int const increase, const std::string& statName) {
	cout << statName << " increased by " << increase << " and is now at " << newStatValue <<"!";
}

void Display::showGoodBye() {
	cout << "Goodbye, come back later!\n";
}

void Display:: checkIfDied(const Character &target) {
	if (target.isAlive()==false){
		cout << target.getName() << " has died!\n";
	}
}

void Display::selectTarget() {
	cout<< "(type 0 to go back) Select your target: \n";
}
void Display::selectAction() {
	cout<< "\nWhat do you want to do ?\n > 1: Attack\n > 2: Magic\n";
}
void Display::magicMenu(const PlayerCharacter &playerCharacter) {
	cout<<"MAGIC:\n";

	cout << "(type 0 to go back) What do you want to cast?\n";
	for (int i=0; i < (playerCharacter.getSpellList().size()); i++){
		cout << " > " << i+1 << ": ";
		showSpellAttributes(playerCharacter.getSpellList()[i]);
	}
}
void Display::notEnoughMana() {
	cout << "Not Enough Mana! Choose another action!\n";
}

void Display::selectAllEnemies() {

	cout<< "> 1: All Enemies\n";

}

void Display::selectAllAllies() {
	cout<< "> 1: All Allies\n";
}

void Display::pressEnter() {
	cout << "Press <ENTER> to continue: \n";

	cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
}

void Display::pressEnterPlayer() {
	cin.ignore();
	pressEnter();
}


void Display::rewardExp(int exp) {
	cout<< "You gained " << exp << " Exp!\n";
}

void Display::rewardGold(int gold) {
	cout<< "You gained " << gold << " Gold!\n";
}

void Display::nextTurn() {
	cout<< endl;
}

void Display::win() {
	cout << "\nEnemies defeated! You Won !\n";
}

void Display::lose() {
	cout << "\nYou Have Perished!\nGAME OVER...\n";
}











