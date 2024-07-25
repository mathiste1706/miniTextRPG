#include "combat.hpp"

using namespace std;

/*Combat::Combat()
{
	//ctor
}

Combat::~Combat()
{
	//dtor
}


int Character:: selectTargetPlayer(string targetList){


	int choiceTarget=0;

	do {

		cout<< "(type 0 to go back) Select your target: \n";

		for (int i=0; i<targetList.size(); i++){
				cout << " > " << i+1 << ": " << targetList[i]->getName() << endl;
		}

		cin>> choiceTarget;

		if (choiceTarget<0 || choiceTarget>targetList.size()) {
			cout << "!Wrong input!" << endl;
		}

	} while (choiceTarget<0 || choiceTarget>targetList.size());

	return choiceTarget;

}

int Character:: selectTargetPlayer(bool ally_enemy){

int choiceTarget=0;

	do{

		cout<< "(type 0 to go back) Confirm your target: \n1 > All";

		if (ally_enemy){
			cout << "Enemies\n";
		}

		else cout << "Allies\n";

		cin>> choiceTarget;

		if (choiceTarget!=0 || choiceTarget!=1) {
			cout << "!Wrong input!" << endl;
		}


	} while (choiceTarget!=0 || choiceTarget!=1);


	return choiceTarget;
}



void Character:: playerTurn(std::vector <Character *> &playerList, std::vector <Character *> &enemyList){

	int finishedTurn=0;
	int choice=0;
	int MPCost=-1;
	string targetList="";
	int choiceTarget=0;

	while (finishedTurn!=1){
		cout<< "\nWhat do you want to do ?\n > 1: Attack\n > 2: Magic\n" << endl;
		cin >> choice;

		while (choice !=1 && choice !=2){
				cout << "!Wrong input!" << endl;
				cout<< "What do you want to do ?\n > 1: Attack\n > 2: Magic\n" << endl;
				cin >> choice;
		}



		switch (choice){
			case 1: 	//Physical attack



				choiceTarget=selectTargetPlayer(enemyList);

				if (choiceTarget!=0){
					attack(*enemyList[choiceTarget-1]);
					checkIfDied(enemyList, choiceTarget);
					finishedTurn=1;
				}

				break;

			case 2:		//Magic

				int choiceSpell=0;
				do {
					do {
						cout<<"MAGIC:\n";

						cout << "(type 0 to come back) What do you want to cast?\n";
						for (int i=0; i < (_SpellList.size()); i++){
								cout << " > " << i+1 << ": ";
								_SpellList[i].showAtrributes();

						}


						cin>> choiceSpell;

						if ((choiceSpell<0) || (choiceSpell>_SpellList.size())){
							cout << "!Wrong input!" << endl;
						}

						else if (choiceSpell!=0){
								MPCost=_SpellList[choiceSpell-1].getMPCost();
						}



					if (_MP<MPCost && choiceSpell!=0){
							cout << "Not Enough Mana! Choose another action!\n";
						}

					} while((choiceSpell<0 || choiceSpell>_SpellList.size()) || (_MP<MPCost && choiceSpell!=0 && MPCost!=1));

					if (choiceSpell!=0){


						if (_SpellList[choiceSpell-1].getTargetAll()){

								choiceTarget=selectTargetPlayer(_SpellList[choiceSpell-1].getTargetAll());

								if (choiceTarget!=0){
									finishedTurn=1;

									if (_SpellList[choiceSpell-1].getAlly_enemy()){

										for (int i=0; i<enemyList.size();i++){
											castOffensiveSpell(_SpellList[choiceSpell-1], *enemyList[i]);
											checkIfDied(enemyList, choiceTarget);
										}
									}

									else {

										for (int i=0; i<playerList.size();i++){
											castHealingSpell(_SpellList[choiceSpell-1], *playerList[i]);
										}
									}

								}
						}


						else {
							if (_SpellList[choiceSpell-1].getAlly_enemy()){

								choiceTarget=selectTargetPlayer(enemyList);
							}

							else {
								choiceTarget=selectTargetPlayer(playerList);
							}
						}

						if (choiceTarget!=0){
							finishedTurn=1;

							diminishMP(_SpellList[choiceSpell-1].getMPCost());

							if (_SpellList[choiceSpell-1].getAlly_enemy()){


								castOffensiveSpell(_SpellList[choiceSpell-1], *enemyList[choiceTarget-1]);
								checkIfDied(enemyList, choiceTarget);

							}

							else{

								castHealingSpell(_SpellList[choiceSpell-1], *playerList[choiceTarget-1]);


							}



						}

					}

				}while(choiceSpell!=0 && finishedTurn==0);

				break;
			}



		}

}

void Character:: enemyTurn(vector <PlayerCharacter *> &playerList, vector <EnemyCharacter *> &enemyList){}
*/
