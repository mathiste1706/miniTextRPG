#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <iostream>
#include <vector>
#include "Spell.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"


class Character;
class EnemyCharacter;
class PlayerCharacter;
class Display
{
	public:
		Display();
		~Display();

		void showStatus(const Character* character)const;
		void showStatusAll(const std::vector<PlayerCharacter*> &playerList) const;
		void showStatusAll(const std::vector<EnemyCharacter*> &enemyList) const;

		void attack(const Character &attacker, const Character  &target) const;
		void diminishHP(int damage) const;
		void dodge(const Character  &target) const;
		void castOffensiveSpell(const Character &caster, const Spell &spell, const Character &target) const;
		void castHealingSpell(const Character &caster, const Spell &spell, const Character &target, int newHP) const;

		void showStats(const Character &character) const;
		void showWeapon(const Weapon &Weapon) const;
		void showArmor(const Armor &Armor) const;
		void showStatsAndEquipment(const Character &character) const;

};

#endif // DISPLAY_HPP
