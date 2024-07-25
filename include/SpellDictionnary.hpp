#ifndef SPELLDICTIONNARY_HPP_INCLUDED
#define SPELLDICTIONNARY_HPP_INCLUDED

#include <map>
#include "Spell.hpp"


inline std:: map <std :: string, Spell> spellDictionnary={
	{"fire_bout",Spell("Fire Bout", "Small jet of flame targeting one enemy", 0, 40, 5)}, {"fireball", Spell("Fireball", "Fireball targeting all enemies", 1, 12, 15)},

	{"heal", Spell("Heal", "Heal one ally", 2, 1, 10)}, {"mass_heal", Spell("Mass Heal", "Heal all allies", 3, 1, 15)},

	{"hone_weapon", Spell("Hone Weapon", "Raise the attack of one ally for 3 turn", 4, 2, 5, 3, 1)}, {"focus", Spell("Focus", "Raise the magic of one ally for 3 turn", 4, 2, 5, 3, 2)},
	{"parry_stance", Spell("Parry Stance", "Raise the defense of one ally for 3 turn", 4, 2, 5, 3, 3)}, {"evade", Spell("Evade", "Raise the agility of one ally for 3 turn", 4, 2, 5, 3, 4)},

	{"war_cry", Spell("War Cry", "Raise the attack of all allies for 3 turn", 5, 2, 15, 3, 1)}, {"chant", Spell("Chant", "Raise the magic of all allies for 3 turn", 5, 2, 15, 3, 2)},
	{"shield_wall", Spell("Shield Wall", "Raise the defense of all allies for 3 turn", 5, 2, 15, 3, 3)}, {"diversion", Spell("Diversion", "Raise the agility of all allies for 3 turn", 5, 2, 15, 3, 4)},

	{"deBuffAtk1", Spell("Lower Attack", "Lower the attack of one enemy for 3 turn", 6, 2, 5, 3, 1)}, {"deBuffMg1", Spell("Lower Magic", "Lower the magic of one enemy for 3 turn", 6, 2, 5, 3, 2)},
	{"deBuffDef1", Spell("Lower Defense", "Lower the defense of one enemy for 3 turn", 6, 2, 5, 3, 3)}, {"deBuffAg1", Spell("Lower Agility", "Lower the agility of one enemy for 3 turn", 6, 2, 5, 3, 4)},

	{"intimidation", Spell("Intimidation", "Lower the attack of all enemies for 3 turn", 7, 2, 15, 3, 1)}, {"interference", Spell("Interference", "Lower the magic of all enemies for 3 turn", 7, 2, 15, 3, 2)},
	{"taunt", Spell("Taunt", "Lower the defense of all enemies for 3 turn", 7, 2, 15, 3, 3)}, {"smoke_bomb", Spell("Smoke Bomb", "Lower the agility of all enemies for 3 turn", 7, 2, 15, 3, 4)},

	};


#endif // SPELLDICTIONNARY_HPP_INCLUDED
