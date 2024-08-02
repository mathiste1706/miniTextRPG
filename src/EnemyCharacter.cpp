#include "EnemyCharacter.hpp"
#include "PlayerCharacter.hpp" // it's only in .cpp to avoid circular dependencies
#include "Display.hpp"

using namespace std;

Loot:: Loot(int dropChance, Equipment drop): _dropChance(dropChance), _drop(drop){}
Loot:: ~Loot(){}

Triplet::Triplet(EnemyCharacter * arg_active): active(arg_active){}

EnemyCharacter::EnemyCharacter():  Character(), _rewardGold(0), _rewardExp(0){}

EnemyCharacter::EnemyCharacter(string name): Character(name),  _rewardGold(0), _rewardExp(0) {}

EnemyCharacter::EnemyCharacter(string name, int Lvl, int Con, int Mg, int Atk, int Def, int Ag, Weapon Weapon, Armor Armor, int gold, int exp, vector <Loot> &lootList): Character(name, Lvl, Con, Mg, Atk, Def, Ag, Weapon, Armor), _rewardGold(gold), _rewardExp(exp), _lootList(lootList) {}

EnemyCharacter::~EnemyCharacter(){}

void EnemyCharacter:: giveRewards(vector <EnemyCharacter *> &enemyList, vector <PlayerCharacter *> &playerList, Inventory &inventory, Display &display){

	int totalExp=0;
	int totalGold=0;

	for (int j=0; j<enemyList.size() ;j++){

		totalExp+=enemyList[j]->getRewardExp();
		totalGold+=+enemyList[j]->getRewardGold();

		for (int i=0; i<playerList.size(); i++){
			playerList[i]->setExp(playerList[i]->getExp()+enemyList[j]->getRewardExp());
		}

		inventory.setGold(inventory.getGold()+enemyList[j]->getRewardGold());

		for (int i=0; i<enemyList[j]->getLootList().size();i++){
			int dropChance= randomNumberMultiply(0,1)*(enemyList[j]->getLootList()[i].getDropChance());
				if (dropChance>=1){
					inventory.addLoot(enemyList[j]->getLootList()[i].getDrop());
					if ((enemyList[j]->getLootList()[i].getDrop()).type()){
						display.showArmor(Armor(enemyList[j]->getLootList()[i].getDrop()));
					}
					else {
						display.showWeapon(Weapon(enemyList[j]->getLootList()[i].getDrop()));
					}
			}
		}
	}

	cout<< "You gained " << totalExp << " Exp!\n";
	cout<< "You gained " << totalGold << " Gold!\n";
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
bool EnemyCharacter:: sortAction(Triplet &a, Triplet &b){

    return (a.spell.getPower() > b.spell.getPower());
}

// Driver function to sort the vector elements by active element of triplet struct in asc order
bool EnemyCharacter:: sortActive(Triplet &a, Triplet &b){

    return (a.active < b.active);
}


void EnemyCharacter:: checkIfDied(vector <PlayerCharacter *> &targetList, int choiceTarget, int &nbPlayer, Display &display) {

	if (targetList[choiceTarget]->isAlive()==false){
		cout << targetList[choiceTarget]->getName() << " has died!\n";
		nbPlayer--;
	}
}

void EnemyCharacter:: enemyTurn(std:: vector <EnemyCharacter *> &enemyList, std:: vector <PlayerCharacter *> &playerList, Display &display){

// Select action

	vector <pair<int, int>> needHealing;
	//vector <EnemyCharacter*> subList;
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
						healAllFound=1;
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
			cout<<endl;

		switch(action[i].spell.getType()){

			case 0:
				action[i].active->diminishMP(action[i].spell.getMPCost());
				action[i].active->castOffensiveSpell(action[i].spell, *playerList[action[i].target], display);
				checkIfDied(playerList, action[i].target, nbPlayer, display);
			break;

			case 1:
				action[i].active->diminishMP(action[i].spell.getMPCost());
				for (int j=0; j<playerList.size();j++){
					if (playerList[j]->isAlive()==true){
						action[i].active->castOffensiveSpell(action[i].spell, *playerList[j], display);
						checkIfDied(playerList, j, nbPlayer, display);
						}
				}
			break;

			case 2:
				action[i].active->diminishMP(action[i].spell.getMPCost());
				action[i].active->castHealingSpell(action[i].spell, *enemyList[action[i].target], display);
				needHealing.erase(needHealing.begin()+action[i].target);
			break;

			case 3:
				action[i].active->diminishMP(action[i].spell.getMPCost());
				for (int j=0; j<enemyList.size();j++){
					if (enemyList[j]->isAlive()==true){
						action[i].active->castHealingSpell(action[i].spell, *enemyList[j], display);
					}
					needHealing.clear();
				}
				break;

			case -1:
				action[i].active->attack(*playerList[action[i].target], display);
				checkIfDied(playerList, action[i].target, nbPlayer, display);

				break;

			default:
				cout<< "!Wrong function call! The dev is a dimwit\n\tLOCATION enemyTurn (line 280)\n";
				break;

		}

	}
}
