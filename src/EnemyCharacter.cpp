#include "EnemyCharacter.hpp"
#include "PlayerCharacter.hpp" // it's only in .cpp to avoid circular dependencies
#include "Display.hpp"

using namespace std;

Loot:: Loot(): _dropChance(0), _drop(make_shared<Armor>(Armor("0",0))){}
Loot:: Loot(const int dropChance, const shared_ptr<Equipment>& drop): _dropChance(dropChance), _drop(drop){}
Loot:: ~Loot(){}

Triplet::Triplet(EnemyCharacter * arg_active): active(arg_active){}

EnemyCharacter::EnemyCharacter():  Character(), _rewardGold(0), _rewardExp(0){}

EnemyCharacter::EnemyCharacter(string name): Character(name),  _rewardGold(0), _rewardExp(0) {}

EnemyCharacter::EnemyCharacter(string name, int Lvl, int Con, int Mg, int Atk, int Def, int Ag, const Weapon& Weapon, const Armor& Armor, const int gold, const int exp, const vector <Loot> &lootList): Character(name, Lvl, Con, Mg, Atk, Def, Ag, Weapon, Armor), _rewardGold(gold), _rewardExp(exp), _lootList(lootList) {}

EnemyCharacter::~EnemyCharacter(){}

void EnemyCharacter:: giveRewards(const vector <EnemyCharacter *> &enemyList, const vector <PlayerCharacter *> &playerList, Inventory &inventory){

	int totalExp=0;
	int totalGold=0;

	for (int j=0; j<enemyList.size() ;j++){

		totalExp+=enemyList[j]->getRewardExp();
		totalGold+=+enemyList[j]->getRewardGold();

		for (int i=0; i<enemyList[j]->getLootList().size();i++){
			int dropChance= randomNumberMultiply(0,1)*(enemyList[j]->getLootList()[i].getDropChance());
				if (dropChance>=1){
					inventory.addLoot(*(enemyList[j]->getLootList()[i].getDrop()));
					if (shared_ptr<Weapon> WeaponPtr=dynamic_pointer_cast<Weapon>(enemyList[j]->getLootList()[i].getDrop())){
						Display:: showWeapon(*WeaponPtr);
					}


					else if (shared_ptr<Armor> ArmorPtr=dynamic_pointer_cast<Armor>(enemyList[j]->getLootList()[i].getDrop())){
						Display:: showArmor(*ArmorPtr);
					}
					else {
						 Display:: errorInFunction();
					}
			}
		}
	}

	for (int i=0; i<playerList.size(); i++){
		playerList[i]->setExp(playerList[i]->getExp()+totalExp);
	}

	inventory.setGold(inventory.getGold()+totalGold);
	Display::rewardExp(totalExp);
	Display::rewardGold(totalGold);
}


Spell EnemyCharacter:: mostPowerfullSpell(EnemyCharacter * &enemy, int spellType){

	Spell spell;

	for (int j=0; j<enemy->getSpellList().size();j++){

		// if the spell type matches the one we're looking for, and it's more powerful and the caster has enough MP, the spell is selected
		// if there is no such spell, then the spell returned has a power of 0, can be matched with a regular attack
		if (enemy->getSpellList()[j].getType()==spellType && (enemy->getSpellList())[j].getPower()> spell.getPower()
			&& enemy->getMP()>=(enemy->getSpellList()[j].getMPCost())){

			spell=enemy->getSpellList()[j];
		}

	}

	return spell;

}


// Driver function to sort the vector elements by power of spell element of triplet struct in desc order
bool sortAction(Triplet &a, Triplet &b){

    return (a.spell.getPower() > b.spell.getPower());
}

// Driver function to sort the vector elements by active element of triplet struct in asc order
bool  sortActive(Triplet &a, Triplet &b){

    return (a.active < b.active);
}


void EnemyCharacter:: checkIfDied(const vector <PlayerCharacter *> &targetList, const int choiceTarget, int &nbPlayer) {

	if (targetList[choiceTarget]->isAlive()==false){
		Display:: checkIfDied(targetList[choiceTarget]);
		nbPlayer--;
	}
}

void EnemyCharacter:: enemyTurn(vector <EnemyCharacter *> &enemyList, const vector <PlayerCharacter *> &playerList){

// Select action

	vector <pair<int, int>> needHealing;

	int nbHealAllowed=0;
	bool healAllFound=0; // was never found for any enemy in the list
	int nbPlayer=0;
	vector<EnemyCharacter *>::iterator targetHeal;
	int targetIndex=0;
	vector <Triplet> action;


	for (int i=0; i<playerList.size();i++){
		if (playerList[i]->isAlive()==true){
			nbPlayer++;
		}
	}

	for (int i=0; i<enemyList.size();i++){
		if (enemyList[i]->isAlive()==true){
			action.push_back(Triplet(enemyList[i]));

		}
	}


	for (int i=0; i<action.size(); i++){

		if (action[i].active->getHP()<0.25*(action[i].active->getCon()*25)){		//check if need Healing
			targetHeal=find(enemyList.begin(), enemyList.end(), action[i].active);
			targetIndex=targetHeal-enemyList.begin();
			needHealing.push_back (make_pair((action[i].active->getCon()*25)-action[i].active->getHP(), targetIndex));
		}

	}

	sort(needHealing.begin(), needHealing.end(), greater <pair<int, int>>());


	//healer

	if (needHealing.empty()==false){

			nbHealAllowed=action.size()/2;
			if (nbHealAllowed>needHealing.size()){
				nbHealAllowed=needHealing.size();
			}


		for (int i=0; i<action.size(); i++){

			if (needHealing.size()>action.size()/2){

					action[i].spell=mostPowerfullSpell(action[i].active, 3);

					if (action[i].spell.getPower()!=0){
						nbHealAllowed=1;
						healAllFound=true;
					}

				}


			else {

				action[i].spell=mostPowerfullSpell(action[i].active, 2);
			}
		}



		if (healAllFound==0){
			for (int i=0; i<action.size(); i++){

				action[i].spell=mostPowerfullSpell(action[i].active, 2);

			}
		}



		sort(action.begin(), action.end(), sortAction);

		if (healAllFound==0){

			for(int i=((action.size()/2)-1); i>=0; i--){

				if (action[i].spell.getPower()==0){

					nbHealAllowed--;
				}
			}
		}

		for (int i=0; i<nbHealAllowed;i++){
			action[i].target=needHealing[i].second;
		}

	sort(action.begin(), action.end(), sortActive);
	}



	//offense

	for (int i=nbHealAllowed; i<action.size(); i++){

		if (nbPlayer>1){

			action[i].spell=mostPowerfullSpell(action[i].active, 1);

			if (action[i].spell.getPower()==0){

				action[i].spell=mostPowerfullSpell(action[i].active, 0);
				this_thread::sleep_for(chrono::milliseconds(50));		// to be certain the seed is different
				action[i].target=randomNumberAdd(0, nbPlayer);

				while (playerList[action[i].target]->isAlive()==false){		// to target a player who is alive
					action[i].target=(action[i].target+1)%nbPlayer;
				}

			}
		}

		else {

			action[i].spell=mostPowerfullSpell(action[i].active, 0);
			this_thread::sleep_for(chrono::milliseconds(50));		// to be certain the seed is different
			action[i].target=randomNumberAdd(0, nbPlayer);

			while (playerList[action[i].target]->isAlive()==false){		// to target a player who is alive
					action[i].target=(action[i].target+1)%nbPlayer;
			}
		}

	}


	// Do action
	cout.flush();

	for (int i=0; i<action.size();i++){

		switch(action[i].spell.getType()){

			case 0:
				action[i].active->diminishMP(action[i].spell.getMPCost());
				action[i].active->castOffensiveSpell(action[i].spell, *playerList[action[i].target]);
				checkIfDied(playerList, action[i].target, nbPlayer);
			break;

			case 1:
				action[i].active->diminishMP(action[i].spell.getMPCost());
				for (int j=0; j<playerList.size();j++){
					if (playerList[j]->isAlive()==true){
						action[i].active->castOffensiveSpell(action[i].spell, *playerList[j]);
						checkIfDied(playerList, j, nbPlayer);
						}
				}
			break;

			case 2:
				action[i].active->diminishMP(action[i].spell.getMPCost());
				action[i].active->castHealingSpell(action[i].spell, *enemyList[action[i].target]);
				needHealing.erase(needHealing.begin()+action[i].target);
			break;

			case 3:
				action[i].active->diminishMP(action[i].spell.getMPCost());
				for (int j=0; j<enemyList.size();j++){
					if (enemyList[j]->isAlive()==true){
						action[i].active->castHealingSpell(action[i].spell, *enemyList[j]);
					}
					needHealing.clear();
				}
				break;

			case -1:
				action[i].active->attack(*playerList[action[i].target]);
				checkIfDied(playerList, action[i].target, nbPlayer);

				break;

			default:
				 Display:: errorInFunction();
				break;

		}
		Display::pressEnter();

	}
}
