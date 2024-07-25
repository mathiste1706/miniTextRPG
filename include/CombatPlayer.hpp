#ifndef COMBATPLAYER_HPP
#define COMBATPLAYER_HPP

#include <Combat.hpp>


class CombatPlayer : public Combat
{
	public:
		CombatPlayer(std::vector <PlayerCharacter *> &playerList, std::vector <PlayerCharacter *> &enemyList);
		virtual ~CombatPlayer();

		static void fight(std::vector <PlayerCharacter *> &playerList, std::vector <PlayerCharacter *> &enemyList);
		static void characterTurn(std::vector <PlayerCharacter *> &playerList, std::vector <EnemyCharacter *> &enemyList);
};

#endif // COMBATPLAYER_HPP
