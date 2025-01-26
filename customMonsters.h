#pragma once

#include "monster.h"
#include "customMoves.h"

class Bulbasaur : public Monster
{
public:
	Bulbasaur(std::string n = "Bulbasaur") : Monster(45, 49, 49, 65, 65, 45, n)
	{
		setMove(VineWhip());
	}
	//{
	//	move.name = "Razor Leaf";
	//	move.damage = 40;
	//	move.accuracy = 95;
	//}
};

class Charmander : public Monster
{
public:
	Charmander(std::string n = "Charmander") : Monster(39, 52, 43, 60, 50, 65, n)
	{
		setMove(Ember());
	}
	//{
	//	move.name = "Ember";
	//	move.damage = 30;
	//	move.accuracy = 100;
	//}
};

class Squirtle : public Monster
{
public:
	Squirtle(std::string n = "Squirtle") : Monster(44, 48, 65, 50, 64, 43, n)
	{
		setMove(WaterGun());
	}
	//{
	//	move.name = "Water Gun";
	//	move.damage = 40;
	//	move.accuracy = 100;
	//}
};