#ifndef ENEMYCHARACTER_HPP
#define ENEMYCHARACTER_HPP

#include <algorithm>

#include "Character.hpp"
#include "Inventory.hpp"


class Loot{

private:

	int _dropChance;
	Equipment _drop;

	public:

		Loot();
		Loot(int dropChance, Equipment drop);
		~Loot();

		int getDropChance() const { return _dropChance; }
		void setDropChance(int newDropChance) { _dropChance = newDropChance; }
		Equipment getDrop() const { return _drop; }
		void setDropt(Equipment newDrop) { _drop = newDrop; }


};

class EnemyCharacter : public Character
{
	public:

		EnemyCharacter();
		EnemyCharacter(std::string name);
		EnemyCharacter(std::string name, int Lvl, int Con, int Mg, int Atk, int Def, int Ag, Equipment Weapon, Equipment Armor, int gold, int exp, std::vector <Loot> &lootList);
		virtual ~EnemyCharacter();

		int getRewardGold() const { return _rewardGold; }
		void setRewardGold(int newRewardGold) { _rewardGold = newRewardGold; }
		int getRewardExp() const { return _rewardExp; }
		void setRewardExp(int newRewardExp) { _rewardExp = newRewardExp; }
		std:: vector <Loot> getLootList() { return _lootList; }
		void setLootList(std:: vector <Loot> newLootList) { _lootList = newLootList; }


		//Specific methods


	private:
		int _rewardGold;
		int _rewardExp;
		std:: vector <Loot> _lootList;
};


class Triplet {
	public:

	EnemyCharacter* active;
	Spell spell=Spell();
	int target=0;

	Triplet(EnemyCharacter * arg_active);

};

#include "PlayerCharacter.hpp"

void giveRewards(std:: vector <EnemyCharacter *> &enemyList, std:: vector <PlayerCharacter *> &playerList, Inventory inventory);

Spell mostPowerfullSpell(EnemyCharacter * &enemy, char spellType);
bool sortAction(Triplet &a, Triplet &b);
bool sortActive(Triplet &a, Triplet &b);
void checkIfDied(std::vector <PlayerCharacter *> &targetList, int choiceTarget, int &nbPlayer);
void enemyTurn (std:: vector <EnemyCharacter *> &enemyList, std:: vector <PlayerCharacter *> &playerList);

#endif // ENEMYCHARACTER_HPP
