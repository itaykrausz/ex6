cmake_minimum_required(VERSION 3.20)
project(ex6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4
        Cards/Barfight.cpp
        Cards/Barfight.h
        Cards/Card.cpp
        Cards/Card.h
        Cards/Dragon.cpp
        Cards/Dragon.h
        Cards/Fairy.cpp
        Cards/Fairy.h
        Cards/Goblin.cpp
        Cards/Goblin.h
        Cards/Merchant.cpp
        Cards/Merchant.h
        Cards/MonsterCard.cpp
        Cards/MonsterCard.h
        Cards/Pitfall.cpp
        Cards/Pitfall.h
        Cards/SpecificCards.cpp
        Cards/SpecificCards.h
        Cards/Treasure.cpp
        Cards/Treasure.h
        Cards/Vampire.cpp
        Cards/Vampire.h
        Players/Fighter.cpp
        Players/Fighter.h
        Players/Player.cpp
        Players/Player.h
        Players/Rogue.cpp
        Players/Rogue.h
        Players/Wizard.cpp
        Players/Wizard.h
        #tool/main.cpp
        #test.cpp
        utilities.cpp
        utilities.h
        Mtmchkin.h
        Mtmchkin.cpp
        Exception.h
        Cards/Gang.cpp
        Cards/Gang.h)
