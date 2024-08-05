#include <iostream>
#include "PlayerCharacter.hpp"
#include "EnemyCharacter.hpp"
#include "Display.hpp"

using namespace std;

void combat(vector <PlayerCharacter *> &playerList, vector <EnemyCharacter *> &enemyList, Inventory &inventory, Display &display){

bool partyIsAlive=true;
bool enemiesAreAlive=true;


	while(partyIsAlive==true && enemiesAreAlive==true){

		partyIsAlive=false;
		enemiesAreAlive=false;


		// show status at every player turn
		for (int i=0; i<playerList.size() ;i++){
			if (playerList[i]->isAlive()==true){

				Display:: showStatusAll(playerList);
				cout<<endl;


				Display:: showStatusAll(enemyList);



				playerList[i]->playerTurn(playerList, enemyList);
			}

		}


		for (int i=0; i<enemyList.size(); i++){		// all enemies are dead

			if (enemyList[i]->isAlive()== true){
				enemiesAreAlive=1;
				break;
			}
	}

		EnemyCharacter::enemyTurn(enemyList, playerList);



		for (int i=0; i<playerList.size(); i++){		// all party is dead

			if (playerList[i]->isAlive()== true){
				partyIsAlive=1;
				break;
			}
	}



		cout<< endl;

	}
	if (partyIsAlive==true){
			cout << "\nEnemies defeated! You Won !\n";
			EnemyCharacter:: giveRewards(enemyList, playerList, inventory);
		}
	else if (enemiesAreAlive==true){
			cout << "\nYou Have Perished!\nGAME OVER...\n";
		}

}


int main(){

	Inventory inventory;
	Display display;


	PlayerCharacter player("player");
	player.fillSpellListCharCreation();
	PlayerCharacter player2("player2");
	player2.fillSpellListCharCreation();
	PlayerCharacter player3("player3");
	player3.fillSpellListCharCreation();


	vector <Loot> lootList1={Loot()};
	vector <Loot> lootList2={Loot(100, Weapon("Excalibur", 100)), Loot(100, Armor("Shiniest Armor", 100))};

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


	combat(playerList, enemyList, inventory, display);




    return 0;
}
