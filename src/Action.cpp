#include <string>
#include "Action.hpp"
#include "Display.hpp"

using namespace std;

int Action::getInput(int lower, int upper){
    string input;
    int number;
    size_t pos;
	getline(cin, input); // Read input as a string

	 try {
		// Convert the input string to an integer
		number = stoi(input, &pos);

		// Check if the entire string was converted, if there's remaining text after the number, it's invalid
		if (pos != input.length()) {
			Display::wrongInputType();
			return -1;
		}

		 // Check if the number is in range
		else if (number < lower || number>upper) {
			Display::wrongInputBounds(lower, upper);
			return -1;
		}
	}

	catch (const std::invalid_argument&) {
		Display::wrongInputType();
		return -1;
	}
	catch (const std::out_of_range&) {
		Display::wrongInputBounds(lower, upper);
		return -1;
	}

	return number;
}

void Action:: moveLocation(){
}


void Action:: combat(vector <PlayerCharacter *> &playerList, vector <EnemyCharacter *> &enemyList, Inventory &inventory){

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
