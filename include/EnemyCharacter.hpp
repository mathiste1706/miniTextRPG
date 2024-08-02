#ifndef ENEMYCHARACTER_HPP
#define ENEMYCHARACTER_HPP

#include <algorithm>

#include "Character.hpp"
#include "Equipment.hpp"
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
	void setDrop(Equipment newDrop) { _drop = newDrop; }


};
class EnemyCharacter;
class Triplet {
	public:

	EnemyCharacter* active;
	Spell spell=Spell();
	int target=0;

	Triplet(EnemyCharacter * arg_active);

};


class EnemyCharacter : public Character{

	public:

		EnemyCharacter();
		EnemyCharacter(std::string name);
		EnemyCharacter(std::string name, int Lvl, int Con, int Mg, int Atk, int Def, int Ag, Weapon Weapon,
						Armor Armor, int gold, int exp, std::vector <Loot> &lootList);
		~EnemyCharacter();

		int getRewardGold() const { return _rewardGold; }
		void setRewardGold(int newRewardGold) { _rewardGold = newRewardGold; }
		int getRewardExp() const { return _rewardExp; }
		void setRewardExp(int newRewardExp) { _rewardExp = newRewardExp; }
		std:: vector <Loot> getLootList() { return _lootList; }
		void setLootList(std:: vector <Loot> newLootList) { _lootList = newLootList; }

		//Specific methods

		void giveRewards(std:: vector <EnemyCharacter *> &enemyList, std:: vector <PlayerCharacter *> &playerList, Inventory &inventory, Display &display);

		Spell mostPowerfullSpell(EnemyCharacter * &enemy, int spellType);
		bool sortAction(Triplet &a, Triplet &b);
		bool sortActive(Triplet &a, Triplet &b);
		void checkIfDied(std::vector <PlayerCharacter *> &targetList, int choiceTarget, int &nbPlayer, Display &display);
		void enemyTurn (std:: vector <EnemyCharacter *> &enemyList, std:: vector <PlayerCharacter *> &playerList, Display &display);



	private:
		int _rewardGold;
		int _rewardExp;
		std:: vector <Loot> _lootList;
};





#endif // ENEMYCHARACTER_HPP
