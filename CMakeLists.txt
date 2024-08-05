cmake_minimum_required(VERSION 3.28)
project(miniTextRPG)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(miniTextRPG main.cpp
        include/Armor.hpp
        include/Character.hpp
        include/Display.hpp
        include/EnemyCharacter.hpp
        include/Equipment.hpp
        include/Inventory.hpp
        include/PlayerCharacter.hpp
        include/Random.hpp
        include/Spell.hpp
        include/SpellDictionnary.hpp
        include/Weapon.hpp
        src/PlayerCharacter.cpp
        src/Armor.cpp
        src/Character.cpp
        src/EnemyCharacter.cpp
        src/Display.cpp
        src/Equipment.cpp
        src/Random.cpp
        src/Spell.cpp
        src/Weapon.cpp
        src/Inventory.cpp)
