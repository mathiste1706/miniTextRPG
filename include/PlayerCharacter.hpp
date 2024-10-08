#ifndef PLAYERCHARACTER_HPP_INCLUDED
#define PLAYERCHARACTER_HPP_INCLUDED

#include <algorithm>

#include "Character.hpp"
#include "EnemyCharacter.hpp"

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
	PlayerCharacter(std :: string name, int Lvl, int Con, int Mg, int Atk, int Def, int Ag, Weapon Weapon, Armor Armor, int exp);

	~PlayerCharacter();


	void setExp(int newExp);
	void setTrainedCon(int newTrainedCon);
	void setTrainedMg(int newTrainedMg);
	void setTrainedAtk(int newTrainedAtk);
	void setTrainedDef(int newTrainedDef);
	void setTrainedAg(int newTrainedAg);

	int getExp() const;
	int getTrainedCon() const;
	int getTrainedMg() const;
	int getTrainedAtk() const;
	int getTrainedDef() const;
	int getTrainedAg() const;


	void levelUp();
	void attributePoints(const std::vector <PlayerCharacter *> &playerList, int gold) const;

	static void checkIfDied(const std::vector <EnemyCharacter *> &targetList, int choiceTarget);
	static int selectTargetPlayer(int spellType);
	static int selectTargetPlayer( std::vector <PlayerCharacter *> &targetList);
	static int selectTargetPlayer( std::vector <EnemyCharacter *> &targetList);
	void playerTurn(std::vector <PlayerCharacter *> &playerList, std::vector <EnemyCharacter *> &enemyList);

};

#endif // PLAYERCHARACTER_HPP_INCLUDED
