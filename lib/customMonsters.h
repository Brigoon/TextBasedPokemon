#pragma once

#include "monster.h"
#include "customMoves.h"

// Gen 1 starters
class Bulbasaur : public Monster
{
public:
	Bulbasaur(std::string n = "Bulbasaur") : Monster(45, 49, 49, 65, 65, 45, n)
	{
		Move tackle = Tackle();
		Move vineWhip = VineWhip();
		Move sleepPowder = SleepPowder();
		setMove(tackle, 0);
		setMove(vineWhip, 1);
		setMove(sleepPowder, 2);
	}
};

class Charmander : public Monster
{
public:
	Charmander(std::string n = "Charmander") : Monster(39, 52, 43, 60, 50, 65, n)
	{
		Move scratch = Scratch();
		Move ember = Ember();
		Move fireFang = FireFang();
		setMove(scratch, 0);
		setMove(ember, 1);
		setMove(fireFang, 2);
	}
};

class Squirtle : public Monster
{
public:
	Squirtle(std::string n = "Squirtle") : Monster(44, 48, 65, 50, 64, 43, n)
	{
		Move tackle = Tackle();
		Move waterGun = WaterGun();
		Move waterPulse = WaterPulse();
		setMove(tackle, 0);
		setMove(waterGun, 1);
		setMove(waterPulse, 2);
	}
};

// Misc Gen 1 -------------------------------------------------------------------------------------
class Seel : public Monster
{
public:
	Seel(std::string n = "Seel") : Monster(65, 45, 55, 45, 70, 45, n)
	{
		Move icyWind = IcyWind();
		Move iceShard = IceShard();
		setMove(icyWind, 0);
		setMove(iceShard, 1);
	}
};

// Gen 2 starters ---------------------------------------------------------------------------------
class Chikorita : public Monster
{
public:
	Chikorita(std::string n = "Chikorita") : Monster(45, 49, 65, 49, 65, 45, n)
	{
		Move tackle = Tackle();
		Move razorLeaf = RazorLeaf();
		Move magicLeaf = MagicalLeaf();
		setMove(tackle, 0);
		setMove(razorLeaf, 1);
		setMove(magicLeaf, 2);
	}
};

class Cyndaquil : public Monster
{
public:
	Cyndaquil(std::string n = "Cyndaquil") : Monster(39, 52, 43, 60, 50, 65, n)
	{
		Move tackle = Tackle();
		Move ember = Ember();
		Move quickAttack = QuickAttack();
		setMove(tackle, 0);
		setMove(ember, 1);
		setMove(quickAttack, 2);
	}
};

class Totodile : public Monster
{
public:
	Totodile(std::string n = "Totodile") : Monster(50, 65, 64, 44, 48, 43, n)
	{
		Move scratch = Scratch();
		Move waterGun = WaterGun();
		Move bite = Bite();
		setMove(scratch, 0);
		setMove(waterGun, 1);
		setMove(bite, 2);
	}
};