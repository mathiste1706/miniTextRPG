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

		static void wrongInputType();
		static void wrongInputBounds(const int lower, const int upper);
		inline static void getErrorInFunction(const char* file, const char* func, int line){
		 std::cout<< "!Wrong function call! The dev is a dimwit\n\tLOCATION " <<file<<" in " <<func <<" line " <<line<< std::endl;
		}

		static void notEnoughGold();

		static void showSpellAttributes(const Spell &spell);

		static void showPlayerListAll(const std::vector<PlayerCharacter *>& playerList);
		static int showPlayerListAlive(const std::vector<PlayerCharacter *>& playerList);
		static int showPlayerListDead(const std::vector<PlayerCharacter *>& playerList);
		static int showEnemyList(const std::vector<EnemyCharacter *>& enemyList);

		static void showStatus(const Character* character);
		static void showStatusAll(const std::vector<PlayerCharacter*> &playerList) ;
		static void showStatusAll(const std::vector<EnemyCharacter*> &enemyList) ;
		static void showStatusAll(const std::vector<PlayerCharacter*> &playerList, const std::vector<EnemyCharacter*> &enemyList);

		static void attack(const Character &attacker, const Character  &target) ;
		static void diminishHP(int damage) ;
		static void dodge(const Character  &target) ;
		static void castOffensiveSpell(const Character &caster, const Spell &spell, const Character &target) ;
		static void castHealingSpell(const Character &caster, const Spell &spell, const Character &target, int newHP) ;

		static void showStats(const Character &character) ;
		static void showWeapon(const Weapon &Weapon) ;
		static void showArmor(const Armor &Armor) ;
		static void showStatsAndEquipment(const Character &character) ;

		static void whoTrain() ;
		static void showStatsOf() ;
		static void increaseWhichStats() ;
		static void alreadyMaxTrained(const PlayerCharacter * playerChara, const std::string& statName) ;
		static void showStatup(int newStatValue, int increase, const std::string& statName) ;
		static void showGoodBye() ;

		static void checkIfDied(const Character &target);
		static void selectTarget();
		static void selectAction();
		static  void magicMenu(const PlayerCharacter &playerCharacter);
		static  void notEnoughMana();
		static void selectAllEnemies();
		static void selectAllAllies();
		static void pressEnter();
		static void pressEnterPlayer();

		static void rewardExp(int exp);
		static void rewardGold(int gold);

		static void nextTurn();

		static void win();
		static void lose();

		#define errorInFunction() Display:: getErrorInFunction(__FILE__, __FUNCTION__, __LINE__)
};


#endif // DISPLAY_HPP
