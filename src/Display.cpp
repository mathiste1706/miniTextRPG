#include "Display.hpp"

using namespace std;

Display:: Display(){}
Display:: ~Display(){}

void Display:: showStatus(Character* character) const{

	cout << character->getName() << " has " << character->getHP() << " HP and " << character->getMP() << " MP.\n";

}

void Display:: showStatusAll(vector<PlayerCharacter*> &playerList) const{

	for (int i=0; i<playerList.size();i++){
		if (playerList[i]->isAlive()==true){
				showStatus(playerList[i]);
		}
	}
}

void Display:: showStatusAll(vector<EnemyCharacter*> &enemyList) const{

	for (int i=0; i<enemyList.size();i++){
		if (enemyList[i]->isAlive()==true){
				showStatus(enemyList[i]);
		}
	}
}
