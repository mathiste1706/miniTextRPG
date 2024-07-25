#ifndef PLAYERCHARACTER_HPP_INCLUDED
#define PLAYERCHARACTER_HPP_INCLUDED

#include <algorithm>

#include "Character.hpp"


class PlayerCharacter: public Character{

private:
	int _exp=0;
	// nb of times the stat was trained, can train up to MAX_TRAINED
	int _trainedCon=0;
	int _trainedMg=0;
	int _trainedAtk=0;
	int _trainedDef=0;
	int _trainedAg=0;
	int const static MAX_TRAINED=5;


public:

	PlayerCharacter();
	PlayerCharacter(std :: string name);
	PlayerCharacter(std :: string name, int Lvl, int Con, int Mg, int Atk, int Def, int Ag, Equipment Weapon, Equipment Armor, int exp);

	virtual ~PlayerCharacter();


	void setExp(int const newExp);
	void setTrainedCon(int const newTrainedCon);
	void setTrainedMg(int const newTrainedMg);
	void setTrainedAtk(int const newTrainedAtk);
	void setTrainedDef(int const newTrainedDef);
	void setTrainedAg(int const newTrainedAg);

	int getExp() const;
	int getTrainedCon() const;
	int getTrainedMg() const;
	int getTrainedAtk() const;
	int getTrainedDef() const;
	int getTrainedAg() const;


	void showStats() const;
	void levelUp();
	void attributePoints(std::vector <PlayerCharacter> &playerList, int gold);
	int selectTargetPlayer(int type);

};

#include "EnemyCharacter.hpp"


void checkIfDied(std::vector <PlayerCharacter *> &targetList, int choiceTarget);
int selectTargetPlayer(std::vector <EnemyCharacter *> &targetList);
int selectTargetPlayer(std::vector <PlayerCharacter *> &targetList);
void playerTurn(PlayerCharacter &active, std::vector <PlayerCharacter *> &playerList, std::vector <EnemyCharacter *> &enemyList);

#endif // PLAYERCHARACTER_HPP_INCLUDED
