#include "Display.hpp"
#include "Character.hpp"  // it's only in .cpp to avoid circular dependencies
#include "PlayerCharacter.hpp" // it's only in .cpp to avoid circular dependencies
#include "EnemyCharacter.hpp" // it's only in .cpp to avoid circular dependencies




using namespace std;

Display:: Display(){}
Display:: ~Display(){}

void Display:: showStatus(const Character* character) const{

	cout << character->getName() << " has " << character->getHP() << " HP and " << character->getMP() << " MP.\n";

}

void Display:: showStatusAll(const vector<PlayerCharacter*> &playerList) const{

	for (int i=0; i<playerList.size();i++){
		if (playerList[i]->isAlive()==true){
				showStatus(playerList[i]);
		}
	}
}

void Display:: showStatusAll(const vector<EnemyCharacter*> &enemyList) const{

	for (int i=0; i<enemyList.size();i++){
		if (enemyList[i]->isAlive()==true){
				showStatus(enemyList[i]);
		}
	}
}

void Display:: attack(const Character &attacker, const Character  &target) const{
	cout<< attacker.getName()<< " attacks " << target.getName();
}

void Display:: diminishHP(int HPDamage)const {
	cout<<" for " << HPDamage << " damage!" << endl;
}

void Display:: dodge(const Character  &target) const{
	cout << ".\n" << target.getName() << " managed to dodge!\n";
}

void Display::castOffensiveSpell(const Character &caster, const Spell &spell, const Character &target) const{
	cout<<caster.getName()<<" cast "<<spell.getName()<< " on " << target.getName();
}

void Display::castHealingSpell(const Character &caster, const Spell &spell, const Character &target, int newHP) const{
	cout<< caster.getName() <<" cast " << spell.getName()<< " and heals " << target.getName() << " for " << newHP << " HP!\n";
}

void Display:: showStats(const Character &character) const{
	cout << character.getName() << " is level " << character.getLvl() << " and has " << character.getCon()
 << " Constitution that grants " << character.getCon()*25 << " HP, " << character.getMg() << " Magic that gives " << character.getMg()*5 << " MP, " << character.getAtk() << " Attack, " << character.getDef() << " Defense, " << character.getAg() << " Agility.\n";
}

void Display:: showWeapon(const Weapon &weapon) const{
	cout << weapon.getName() << " grants you " << weapon.getAttribute() << " Atk\n";

}

void Display:: showArmor(const Armor &armor) const{
	cout << armor.getName() << " grants you " << armor.getAttribute() << " Def\n";

}

void Display:: showStatsAndEquipment(const Character &character) const{
	showStats(character);
	showWeapon(character.getWeapon());
	showArmor(character.getArmor());
}

