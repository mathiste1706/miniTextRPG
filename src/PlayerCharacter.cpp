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

void PlayerCharacter:: attributePoints(const vector <PlayerCharacter *> &playerList, const int gold) const{

	int choiceCharacter=0;
	int choiceStat=0;
	int goldCost=0;
	bool selectedStat=false;

	do{
		Display::whoTrain();

		Display::showPlayerListAll(playerList);
		cin >> choiceCharacter;

		if(choiceCharacter<0 && choiceCharacter>playerList.size()){
			Display::wrongInput();
		}

	}while(choiceCharacter<0 && choiceCharacter>playerList.size());

	if (choiceCharacter>0){
		Display::showStatsOf();

		Display::showStats(Character(playerList[(choiceCharacter-1)]));


		do{
		Display::increaseWhichStats();

		cin >> choiceStat;

		if(choiceStat<0 && choiceStat>playerList.size()){
			Display::wrongInput();
		}



		switch (choiceStat){


			case 1:
				goldCost=(1+_trainedCon)*50;

				if (_trainedCon==MAX_TRAINED){
					Display::alreadyMaxTrained(playerList[(choiceCharacter-1)], "Con");
				}

				else if (gold<goldCost){
					Display::notEnoughGold();
				}

				else {
					int newCon= (playerList[(choiceCharacter-1)]->getCon())+1;
					playerList[(choiceCharacter-1)]->setCon(newCon);
					Display::showStatup(newCon, 1, "Con");
					selectedStat=true;
				}
				break;

				case 2:
				goldCost=(1+_trainedMg)*50;

				if (_trainedMg==MAX_TRAINED){
					Display::alreadyMaxTrained(playerList[(choiceCharacter-1)], "Mg");
				}

				else if (gold<goldCost){
					Display::notEnoughGold();
				}

				else {
					int newMg= ( playerList[(choiceCharacter-1)]->getMg())+1;
					 playerList[(choiceCharacter-1)]->setMg(newMg);
					Display::showStatup(newMg, 1, "Mg");
					selectedStat=true;
				}
				break;

				case 3:
				goldCost=(1+_trainedAtk)*50;

				if (_trainedAtk==MAX_TRAINED){
					Display::alreadyMaxTrained(playerList[(choiceCharacter-1)], "Atk");
				}

				else if (gold<goldCost){
					Display::notEnoughGold();
				}

				else {
					int newAtk= ( playerList[(choiceCharacter-1)]->getAtk())+1;
					 playerList[(choiceCharacter-1)]->setAtk(newAtk);
					Display::showStatup(newAtk, 1, "Atk");
					selectedStat=true;
				}
				break;

				case 4:
				goldCost=(1+_trainedDef)*50;

				if (_trainedDef==MAX_TRAINED){
					Display::alreadyMaxTrained(playerList[(choiceCharacter-1)], "Def");
				}

				else if (gold<goldCost){
					Display::notEnoughGold();
				}

				else {
					int newDef= ( playerList[(choiceCharacter-1)]->getDef())+1;
					playerList[(choiceCharacter-1)]->setDef(newDef);
					Display::showStatup(newDef, 1, "Def");
					selectedStat=true;
				}
				break;

				case 5:
				goldCost=(1+_trainedAg)*50;

				if (_trainedAg==MAX_TRAINED){
					Display::alreadyMaxTrained(playerList[(choiceCharacter-1)], "Con");
				}

				else if (gold<goldCost){
					Display::notEnoughGold();
				}

				else {
					int newAg= ( playerList[(choiceCharacter-1)]->getAg())+1;
					playerList[(choiceCharacter-1)]->setAg(newAg);
					Display::showStatup(newAg, 1, "Ag");
					selectedStat=true;
				}
				break;
		}

			}while(choiceStat<0 && choiceStat>playerList.size() && selectedStat==false);

	}

	else {
		Display::showGoodBye();
	}


}

void PlayerCharacter:: checkIfDied(const vector <EnemyCharacter *> &targetList, const int choiceTarget) {

	Display::checkIfDied(targetList[choiceTarget-1]);

}

int PlayerCharacter::selectTargetPlayer(const int spellType){
	int choiceTarget=-1;
	Display:: selectTarget();

	do {

		if (spellType==1 or spellType==7) {
			Display:: selectAllEnemies();
			cin >>choiceTarget;
		}

		else if (spellType==3 or spellType==5) {
			Display::selectAllAllies();
			cin >>choiceTarget;

		}
		else {
			cout << "Something went wrong in playerTurn when select all";
		}

	}while(choiceTarget!=1 and choiceTarget!=0);

	return choiceTarget;
}


int PlayerCharacter:: selectTargetPlayer( vector <PlayerCharacter *> &targetList){

	int choiceTarget=0;
	int nbTarget;
	vector<PlayerCharacter*> subList;

	do {

		Display::selectTarget();

		nbTarget=Display:: showPlayerListAlive(targetList);

		cin>> choiceTarget;

		for (int i=0; i<targetList.size(); i++) {
			if (targetList[i]->isAlive()){
				subList.push_back(targetList[i]);
			}
		}

		if (choiceTarget<0 || choiceTarget>nbTarget) {
			Display:: wrongInput();
		}


	} while (choiceTarget<0 || choiceTarget>nbTarget);

	if (choiceTarget!=0){
		vector<PlayerCharacter*>::iterator target=find(targetList.begin(), targetList.end(), subList[choiceTarget-1]);
		choiceTarget=target-targetList.begin()+1;
	}

	return choiceTarget;

}


int PlayerCharacter:: selectTargetPlayer(vector <EnemyCharacter *> &targetList){

	int choiceTarget=0;
	int nbTarget;
	vector<EnemyCharacter*> subList;

	do {

		Display:: selectTarget();

		nbTarget=Display:: showEnemyList(targetList);

		cin>> choiceTarget;

		for (int i=0; i<targetList.size(); i++) {
			if (targetList[i]->isAlive()){
				subList.push_back(targetList[i]);
			}
		}

		if (choiceTarget<0 || choiceTarget>nbTarget) {
			Display:: wrongInput();
		}

	} while (choiceTarget<0 or choiceTarget>nbTarget);

	if (choiceTarget!=0){
		vector<EnemyCharacter*>::iterator target=find(targetList.begin(), targetList.end(), subList[choiceTarget-1]);
		choiceTarget=target-targetList.begin()+1;
	}

	return choiceTarget;

}




void PlayerCharacter:: playerTurn(vector <PlayerCharacter *> &playerList, vector <EnemyCharacter *> &enemyList){


	int finishedTurn=0;
	int choice=0;
	int MPCost=-1;
	int choiceTarget=0;
	bool allEnemiesDied=true;

	for (int i=0; i<enemyList.size(); i++){

		if (enemyList[i]->isAlive()== true){
			allEnemiesDied=false;
			break;
		}
	}

	while (finishedTurn!=1 && allEnemiesDied==0){
		Display::selectAction();
		cin >> choice;

		while (choice !=1 && choice !=2){
				Display:: wrongInput();
				Display:: selectAction();
				cin >> choice;
		}



		switch (choice){
			case 1: 	//Physical attack

				choiceTarget=selectTargetPlayer(enemyList);

				if (choiceTarget!=0){
					finishedTurn=1;
					this->attack(*enemyList[choiceTarget-1]);
					checkIfDied(enemyList, choiceTarget);

				}

				break;

			case 2:		//Magic

				int choiceSpell=0;

				do {
					do {
						Display::magicMenu(*this);


						cin>> choiceSpell;

						if ((choiceSpell<0) || (choiceSpell>this->getSpellList().size())){
							Display::wrongInput();
						}

						else if (choiceSpell!=0){
								MPCost=this->getSpellList()[choiceSpell-1].getMPCost();
						}

					if (this->getMP()<MPCost && choiceSpell!=0){
						Display:: notEnoughMana();
					}

					} while((choiceSpell<0 || choiceSpell>this->getSpellList().size()) || (this->getMP()<MPCost && choiceSpell!=0 && MPCost!=1));

					if (choiceSpell!=0){


						// Target All
						if ((this->getSpellList()[choiceSpell-1].getType())%2!=0) {
							choiceTarget=selectTargetPlayer(this->getSpellList()[choiceSpell-1].getType());
						}


								if (choiceTarget==1){
									finishedTurn=1;
									this->diminishMP(this->getSpellList()[choiceSpell-1].getMPCost());


									//Spell on All Enemies
									if (this->getSpellList()[choiceSpell-1].getType()==1 || this->getSpellList()[choiceSpell-1].getType()==7){

										for (int i=0; i<enemyList.size();i++){
											if (enemyList[i]->isAlive()==true){
												this->castOffensiveSpell(this->getSpellList()[choiceSpell-1], *enemyList[i]);
												checkIfDied(enemyList, choiceTarget);
											}
										}
									}

									//Spell on All Party
									else if (this->getSpellList()[choiceSpell-1].getType()==3 || this->getSpellList()[choiceSpell-1].getType()==5){
										for (int i=0; i<playerList.size();i++){
											if (playerList[i]->isAlive()==true){
												this->castHealingSpell(this->getSpellList()[choiceSpell-1], *playerList[i]);
											}
										}
									}

									else {
										 cout<< "!Wrong function call! The dev is a dimwit\n\tLOCATION playerTurn TargetAll (line 502)\n";
									}

								}


						//Target Single
						else {
							//Enemy
							if (this->getSpellList()[choiceSpell-1].getType()==0 || this->getSpellList()[choiceSpell-1].getType()==6 ){

								choiceTarget=selectTargetPlayer(enemyList);
							}

							//Ally
							else if (this->getSpellList()[choiceSpell-1].getType()==2 || this->getSpellList()[choiceSpell-1].getType()==4 ){

								choiceTarget=selectTargetPlayer(playerList);
							}

							else {
								cout<< "!Wrong function call! The dev is a dimwit\n\tLOCATION playerTurn selectTarget Single (line 522)\n";
							}


							if (choiceTarget!=0){
								finishedTurn=1;

								this->diminishMP(this->getSpellList()[choiceSpell-1].getMPCost());

								if (this->getSpellList()[choiceSpell-1].getType()==0 || this->getSpellList()[choiceSpell-1].getType()==6 ){


									this->castOffensiveSpell(this->getSpellList()[choiceSpell-1], *enemyList[choiceTarget-1]);
									checkIfDied(enemyList, choiceTarget);

								}

								else if (this->getSpellList()[choiceSpell-1].getType()==2 || this->getSpellList()[choiceSpell-1].getType()==4 ){

									this->castHealingSpell(this->getSpellList()[choiceSpell-1], *playerList[choiceTarget-1]);

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
		if (finishedTurn) {
			Display::pressEnterPlayer();
		}
	}
}

