#include "PlayerCharacter.hpp"

using namespace std;

 // Con=4 is Hp=4*25=100, Mg=6 is MP=6*5=30

PlayerCharacter:: PlayerCharacter(): Character(), _exp(0) {}

PlayerCharacter:: PlayerCharacter(string name): Character(name), _exp(0) {}

PlayerCharacter:: PlayerCharacter(string name, int Lvl, int Con, int Mg, int Atk, int Def, int Ag, Weapon Weapon, Armor Armor, int exp): Character(name, Lvl, Con, Mg, Atk, Def, Ag, Weapon, Armor), _exp(exp) {}


PlayerCharacter:: ~PlayerCharacter(){}


void PlayerCharacter:: setExp(int const newExp){
	_exp=newExp;
}

int PlayerCharacter:: getExp() const{
return _exp;
}


void PlayerCharacter:: setTrainedCon(int const newTrainedCon){
	_trainedCon=newTrainedCon;
}

int PlayerCharacter:: getTrainedCon() const{
return _trainedCon;
}

void PlayerCharacter:: setTrainedMg(int const newTrainedMg){
	_trainedMg=newTrainedMg;
}

int PlayerCharacter:: getTrainedMg() const{
return _trainedMg;
}

void PlayerCharacter:: setTrainedAtk(int const newTrainedAtk){
	_trainedAtk=newTrainedAtk;
}

int PlayerCharacter:: getTrainedAtk() const{
return _trainedAtk;
}

void PlayerCharacter:: setTrainedDef(int const newTrainedDef){
	_trainedDef=newTrainedDef;
}

int PlayerCharacter:: getTrainedDef() const{
return _trainedDef;
}

void PlayerCharacter:: setTrainedAg(int const newTrainedAg){
	_trainedAg=newTrainedAg;
}

int PlayerCharacter:: getTrainedAg() const{
return _trainedAg;
}


void PlayerCharacter:: levelUp(){

	int Lvl=getLvl();

	switch(Lvl){

		case 1:
				if (_exp==50){

					LvlUp();
					setCon(getCon()+2);
					setMg(getMg()+2);
					setAtk(getAtk()+1);
					setDef(getDef()+1);
					setAg(getAg()+1);
					setExp(0);
					fillSpellListLvlUp(_Lvl);
				}
				break;
		case 2:
			if (_exp==75){

					LvlUp();
					setCon(getCon()+2);
					setMg(getMg()+4);
					setAtk(getAtk()+1);
					setDef(getDef()+2);
					setAg(getAg()+1);
					setExp(0);
					fillSpellListLvlUp(_Lvl);
			}
				break;
		case 3:
			if (_exp==100){

					LvlUp();
					setCon(getCon()+3);
					setMg(getMg()+5);
					setAtk(getAtk()+3);
					setDef(getDef()+3);
					setAg(getAg()+2);
					setExp(0);
					fillSpellListLvlUp(_Lvl);
			}
				break;

	}

}

void PlayerCharacter:: attributePoints(std::vector <PlayerCharacter> &playerList, int gold){

	int choiceCharacter=0;
	int choiceStat=0;
	int goldCost=0;
	bool selectedStat=false;

	do{
		cout << "(type 0 to go back) Who do you want to train?\n";

		for (int i=0; i<playerList.size(); i++){
				cout << " > " << i+1 << " : " << playerList[(choiceCharacter-1)].getName();
		}
		cin >> choiceCharacter;

		if(choiceCharacter<0 && choiceCharacter>playerList.size()){
			cout << "!Wrong input!\n";
		}

	}while(choiceCharacter<0 && choiceCharacter>playerList.size());

	if (choiceCharacter>0){
		cout <<"This is the current Status of ";

		 playerList[(choiceCharacter-1)].showStats();


		do{
		cout << "(type 0 to go back) What stat do you want to increase?\n > 1 Con\n 2 > Mg\n 3 > Atk\n 4 > Def\n 5 > Ag";

		cin >> choiceStat;

		if(choiceStat<0 && choiceStat>playerList.size()){
			cout << "!Wrong input!\n";
		}



		switch (choiceStat){


			case 1:
				goldCost=_trainedCon*50;

				if (_trainedCon==MAX_TRAINED){
					cout <<  playerList[(choiceCharacter-1)].getName() << "has already trained this stat to the maximum!\n";
				}

				else if (gold<goldCost){
					cout << "You do not have enough gold!\n";
				}

				else {
					int newCon= (playerList[(choiceCharacter-1)].getCon())+1;
					 playerList[(choiceCharacter-1)].setCon(newCon);
					selectedStat=true;
				}
				break;

				case 2:
				goldCost=_trainedMg*50;

				if (_trainedMg==MAX_TRAINED){
					cout <<  playerList[(choiceCharacter-1)].getName() << "has already trained this stat to the maximum!\n";
				}

				else if (gold<goldCost){
					cout << "You do not have enough gold!\n";
				}

				else {
					int newMg= ( playerList[(choiceCharacter-1)].getMg())+1;
					 playerList[(choiceCharacter-1)].setMg(newMg);
					selectedStat=true;
				}
				break;

				case 3:
				goldCost=_trainedAtk*50;

				if (_trainedAtk==MAX_TRAINED){
					cout <<  playerList[(choiceCharacter-1)].getName() << "has already trained this stat to the maximum!\n";
				}

				else if (gold<goldCost){
					cout << "You do not have enough gold!\n";
				}

				else {
					int newAtk= ( playerList[(choiceCharacter-1)].getAtk())+1;
					 playerList[(choiceCharacter-1)].setAtk(newAtk);
					selectedStat=true;
				}
				break;

				case 4:
				goldCost=_trainedDef*50;

				if (_trainedDef==MAX_TRAINED){
					cout <<  playerList[(choiceCharacter-1)].getName() << "has already trained this stat to the maximum!\n";
				}

				else if (gold<goldCost){
					cout << "You do not have enough gold!\n";
				}

				else {
					int newDef= ( playerList[(choiceCharacter-1)].getDef())+1;
					 playerList[(choiceCharacter-1)].setDef(newDef);
					selectedStat=true;
				}
				break;

				case 5:
				goldCost=_trainedAg*50;

				if (_trainedAg==MAX_TRAINED){
					cout <<  playerList[(choiceCharacter-1)].getName() << "has already trained this stat to the maximum!\n";
				}

				else if (gold<goldCost){
					cout << "You do not have enough gold!\n";
				}

				else {
					int newAg= ( playerList[(choiceCharacter-1)].getAg())+1;
					 playerList[(choiceCharacter-1)].setAg(newAg);
					selectedStat=true;
				}
				break;
		}

			}while(choiceStat<0 && choiceStat>playerList.size() && selectedStat==false);

	}

	else {
		cout << "Goodbye, come back later!\n";
	}


}

void PlayerCharacter:: checkIfDied(vector <EnemyCharacter *> &targetList, int choiceTarget, Display display) {

	if (targetList[choiceTarget-1]->isAlive()==false){
		cout << targetList[choiceTarget-1]->getName() << " has died!\n";
	}
}

int PlayerCharacter:: selectTargetPlayer(vector <PlayerCharacter *> &targetList, Display display){


	int choiceTarget=0;
	int nbTarget=0;
	vector <PlayerCharacter *> subList;

	do {
		nbTarget=0;

		cout<< "(type 0 to go back) Select your target: \n";

		for (int i=0; i<targetList.size(); i++){

				if (targetList[i]->isAlive()==true){

					nbTarget++;
					cout << " > " << nbTarget << ": " << targetList[i]->getName() << endl;
					subList.push_back(targetList[i]);
				}
		}

		cin>> choiceTarget;

		if (choiceTarget<0 || choiceTarget>nbTarget) {
			cout << "!Wrong input!" << endl;
		}

	} while (choiceTarget<0 || choiceTarget>nbTarget);

	if (choiceTarget!=0){
		vector<PlayerCharacter*>::iterator target=find(targetList.begin(), targetList.end(), subList[choiceTarget-1]);
		choiceTarget=target-targetList.begin()+1;
	}

	return choiceTarget;

}


int PlayerCharacter:: selectTargetPlayer(vector <EnemyCharacter *> &targetList, Display display){

	int choiceTarget=0;
	int nbTarget=0;
	vector <EnemyCharacter *> subList;

	do {
		nbTarget=0;
		subList.clear();

		cout<< "(type 0 to go back) Select your target: \n";

		for (int i=0; i<targetList.size(); i++){


				if (targetList[i]->isAlive()==true){

					nbTarget++;
					cout << " > " << nbTarget << ": " << targetList[i]->getName() << endl;
					subList.push_back(targetList[i]);
				}
		}

		cin>> choiceTarget;

		if (choiceTarget<0 || choiceTarget>nbTarget) {
			cout << "!Wrong input!" << endl;
		}

	} while (choiceTarget<0 || choiceTarget>nbTarget);


	if (choiceTarget!=0){
		vector<EnemyCharacter*>::iterator target=find(targetList.begin(), targetList.end(), subList[choiceTarget-1]);
		choiceTarget=target-targetList.begin()+1;
	}

	return choiceTarget;

}


int PlayerCharacter:: PlayerCharacter:: selectTargetPlayer(int const type){

int choiceTarget=0;

	do{

		cout<< "(type 0 to go back) Confirm your target: \n1 > All";

		if (type==1 || type==7){
			cout << "Enemies\n";
		}

		else if (type==3|| type==5){
			cout << "Allies\n";
		}

		else{
			cout<< "!Wrong function call! The dev is a dimwit\n\tLOCATION selectTargetPlayer (for all) (line 373)\n";
		}

		cin>> choiceTarget;

		if (choiceTarget!=0 || choiceTarget!=1) {
			cout << "!Wrong input!" << endl;
		}


	} while (choiceTarget!=0 || choiceTarget!=1);


	return choiceTarget;
}



void PlayerCharacter:: playerTurn(vector <PlayerCharacter *> &playerList, vector <EnemyCharacter *> &enemyList, Display display){


	int finishedTurn=0;
	int choice=0;
	int MPCost=-1;
	int choiceTarget=0;
	bool allEnemiesDied=1;

	for (int i=0; i<enemyList.size(); i++){

		if (enemyList[i]->isAlive()== true){
			allEnemiesDied=0;
			break;
		}
	}

	while (finishedTurn!=1 && allEnemiesDied==0){
		cout<< "\nWhat do you want to do ?\n > 1: Attack\n > 2: Magic\n" << endl;
		cin >> choice;

		while (choice !=1 && choice !=2){
				cout << "!Wrong input!" << endl;
				cout<< "What do you want to do ?\n > 1: Attack\n > 2: Magic\n" << endl;
				cin >> choice;
		}



		switch (choice){
			case 1: 	//Physical attack

				choiceTarget=selectTargetPlayer(enemyList, display);

				if (choiceTarget!=0){
					finishedTurn=1;
					this->attack(*enemyList[choiceTarget-1], display);
					checkIfDied(enemyList, choiceTarget, display);

				}

				break;

			case 2:		//Magic

				int choiceSpell=0;

				do {
					do {
						cout<<"MAGIC:\n";

						cout << "(type 0 to come back) What do you want to cast?\n";
						for (int i=0; i < (this->getSpellList().size()); i++){
								cout << " > " << i+1 << ": ";
								this->getSpellList()[i].showAtrributes();

						}


						cin>> choiceSpell;

						if ((choiceSpell<0) || (choiceSpell>this->getSpellList().size())){
							cout << "!Wrong input!" << endl;
						}

						else if (choiceSpell!=0){
								MPCost=this->getSpellList()[choiceSpell-1].getMPCost();
						}



					if (this->getMP()<MPCost && choiceSpell!=0){
							cout << "Not Enough Mana! Choose another action!\n";
						}

					} while((choiceSpell<0 || choiceSpell>this->getSpellList().size()) || (this->getMP()<MPCost && choiceSpell!=0 && MPCost!=1));

					if (choiceSpell!=0){


						// Target All
						if ((this->getSpellList()[choiceSpell-1].getType())%2!=0){

								choiceTarget=this->selectTargetPlayer(this->getSpellList()[choiceSpell-1].getType());

								if (choiceTarget!=0){
									finishedTurn=1;
									this->diminishMP(this->getSpellList()[choiceSpell-1].getMPCost());


									//Spell on All Enemies
									if (this->getSpellList()[choiceSpell-1].getType()==1 || this->getSpellList()[choiceSpell-1].getType()==7){

										for (int i=0; i<enemyList.size();i++){
											if (enemyList[i]->isAlive()==true){
												this->castOffensiveSpell(this->getSpellList()[choiceSpell-1], *enemyList[i], display);
												checkIfDied(enemyList, choiceTarget, display);
											}
										}
									}

									//Spell on All Party
									else if (this->getSpellList()[choiceSpell-1].getType()==3 || this->getSpellList()[choiceSpell-1].getType()==5){
										for (int i=0; i<playerList.size();i++){
											if (playerList[i]->isAlive()==true){
												this->castHealingSpell(this->getSpellList()[choiceSpell-1], *playerList[i], display);
											}
										}
									}

									else {
										 cout<< "!Wrong function call! The dev is a dimwit\n\tLOCATION playerTurn TargetAll (line 502)\n";
									}

								}
						}

						//Target Single
						else {
							//Enemy
							if (this->getSpellList()[choiceSpell-1].getType()==0 || this->getSpellList()[choiceSpell-1].getType()==6 ){

								choiceTarget=selectTargetPlayer(enemyList, display);
							}

							//Ally
							else if (this->getSpellList()[choiceSpell-1].getType()==2 || this->getSpellList()[choiceSpell-1].getType()==4 ){

								choiceTarget=selectTargetPlayer(playerList, display);
							}

							else {
								cout<< "!Wrong function call! The dev is a dimwit\n\tLOCATION playerTurn selectTarget Single (line 522)\n";
							}


							if (choiceTarget!=0){
								finishedTurn=1;

								this->diminishMP(this->getSpellList()[choiceSpell-1].getMPCost());

								if (this->getSpellList()[choiceSpell-1].getType()==0 || this->getSpellList()[choiceSpell-1].getType()==6 ){


									this->castOffensiveSpell(this->getSpellList()[choiceSpell-1], *enemyList[choiceTarget-1], display);
									checkIfDied(enemyList, choiceTarget, display);

								}

								else if (this->getSpellList()[choiceSpell-1].getType()==2 || this->getSpellList()[choiceSpell-1].getType()==4 ){

									this->castHealingSpell(this->getSpellList()[choiceSpell-1], *playerList[choiceTarget-1], display);

								}

								else {
									cout<< "!Wrong function call! The dev is a dimwit\n\tLOCATION playerTurn castSpell (line 547)\n";
								}

							}
						}

					}

				}while(choiceSpell!=0 && finishedTurn==0);

				break;
			}



		}

}

