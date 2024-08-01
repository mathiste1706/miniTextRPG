#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <iostream>
#include "PlayerCharacter.hpp"
#include "EnemyCharacter.hpp"

class Display
{
	public:
		Display();
		~Display();

		void showStatus(Character* character)const;
		void showStatusAll(std::vector<PlayerCharacter*> &playerList) const;
		void showStatusAll(std::vector<EnemyCharacter*> &enemyList) const;
		void attack(Character &attacker, Character  &target) const;
		void diminishHP(int damage) const;
		void dodge(Character  &target) const;
		void castOffensiveSpell(Character &caster, Spell &spell, Character &target) const;
};

#endif // DISPLAY_HPP
