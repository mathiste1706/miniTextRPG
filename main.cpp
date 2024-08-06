#include <iostream>
#include "PlayerCharacter.hpp"
#include "EnemyCharacter.hpp"
#include "Display.hpp"

using namespace std;

void combat(vector <PlayerCharacter *> &playerList, vector <EnemyCharacter *> &enemyList, Inventory &inventory){

bool partyIsAlive=true;
bool enemiesAreAlive=true;

	while(partyIsAlive==true && enemiesAreAlive==true){

		partyIsAlive=false;
		enemiesAreAlive=false;

		// show status at every player turn
		for (int i=0; i<playerList.size() ;i++){
			if (playerList[i]->isAlive()==true){

				Display::showStatusAll(playerList, enemyList);

				playerList[i]->playerTurn(playerList, enemyList);
			}
		}


		for (int i=0; i<enemyList.size(); i++){		// all enemies are dead

			if (enemyList[i]->isAlive()== true){
				enemiesAreAlive=true;
				break;
			}
	}

		EnemyCharacter::enemyTurn(enemyList, playerList);



		for (int i=0; i<playerList.size(); i++){		// all party is dead

			if (playerList[i]->isAlive()== true){
				partyIsAlive=true;
				break;
			}
	}
		Display::nextTurn();

	}
	if (partyIsAlive==true){
			Display::win();
			EnemyCharacter:: giveRewards(enemyList, playerList, inventory);
		}
	else if (enemiesAreAlive==true){

		}

}


int main(){

	Inventory inventory;

	PlayerCharacter player("player", 2, 6, 6, 10, 6, 100, Weapon("r", 1), Armor("ff", 1), 0);
	player.fillSpellListCharCreation();
	PlayerCharacter player2("player2");
	player2.fillSpellListCharCreation();
	PlayerCharacter player3("player3");
	player3.fillSpellListCharCreation();



	vector <Loot> lootList1={Loot()};
	vector <Loot> lootList2={Loot(100, make_shared<Weapon>(Weapon("Excalibur", 100))), Loot(100, make_shared<Armor>(Armor("Shiniest Armor", 100)))};

	EnemyCharacter  monster1("monster 1", 1, 2,3, 5,2,0, Weapon("Rusted sword", 1), Armor("Rusted armor", 1), 10, 25, lootList1);
	EnemyCharacter  monster2("monster 2", 1, 2,3, 5,2,0, Weapon("Rusted sword", 1), Armor("Rusted armor", 1), 10, 25, lootList1);
	EnemyCharacter  monster3("monster 3", 1, 2,3, 5,2,0, Weapon("Rusted sword", 1), Armor("Rusted armor", 1), 10, 25, lootList1);
	EnemyCharacter  superMonster("Super monster", 2, 1,3, 10,2,5, Weapon("Rusted sword", 1), Armor("Rusted armor", 1), 100, 250, lootList2);
	monster2.fillSpellListCharCreation();
	superMonster.fillSpellListCharCreation();


	vector <PlayerCharacter *> playerList;
	playerList.push_back(&player);
	playerList.push_back(&player2);
	playerList.push_back(&player3);



	vector <EnemyCharacter *> enemyList;
	enemyList.push_back(&superMonster);
	enemyList.push_back(&monster1);
	enemyList.push_back(&monster2);
	enemyList.push_back(&monster3);


	combat(playerList, enemyList, inventory);




    return 0;
}
