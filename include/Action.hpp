#ifndef ACTION_HPP
#define ACTION_HPP

#include <vector>
#include "PlayerCharacter.hpp"
#include "EnemyCharacter.hpp"
#include "Inventory.hpp"

class Action
{
	public:

	static int getInput(int lower, int upper);
	static void moveLocation();
	static void combat (std::vector <PlayerCharacter *> &playerList, std::vector <EnemyCharacter *> &enemyList, Inventory &inventory);

};

#endif // ACTION_HPP
