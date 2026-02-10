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
		Move razorLeaf = RazorLeaf();
		Move sleepPowder = SleepPowder();
		setMove(tackle, 0);
		setMove(vineWhip, 1);
		setMove(razorLeaf, 2);
		setMove(sleepPowder, 3);
	}
};

class Charmander : public Monster
{
public:
	Charmander(std::string n = "Charmander") : Monster(39, 52, 43, 60, 50, 65, n)
	{
		Move scratch = Scratch();
		Move ember = Ember();
		Move dragBreath = DragonBreath();
		Move fireFang = FireFang();
		setMove(scratch, 0);
		setMove(ember, 1);
		setMove(dragBreath, 2);
		setMove(fireFang, 3);
	}
};

class Squirtle : public Monster
{
public:
	Squirtle(std::string n = "Squirtle") : Monster(44, 48, 65, 50, 64, 43, n)
	{
		Move tackle = Tackle();
		Move waterGun = WaterGun();
		Move bite = Bite();
		Move waterPulse = WaterPulse();
		setMove(tackle, 0);
		setMove(waterGun, 1);
		setMove(bite, 2);
		setMove(waterPulse, 3);
	}
};

// Misc Gen 1 -------------------------------------------------------------------------------------
class Seel : public Monster
{
public:
	Seel(std::string n = "Seel") : Monster(65, 45, 55, 45, 70, 45, n)
	{
		Move headbutt = Headbutt();
		Move icyWind = IcyWind();
		Move iceShard = IceShard();
		setMove(headbutt, 0);
		setMove(icyWind, 1);
		setMove(iceShard, 2);
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
		Move poisonPowder = PoisonPowder();
		Move magicLeaf = MagicalLeaf();
		setMove(tackle, 0);
		setMove(razorLeaf, 1);
		setMove(poisonPowder, 2);
		setMove(magicLeaf, 3);
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
		Move flameWheel = FlameWheel();
		setMove(tackle, 0);
		setMove(ember, 1);
		setMove(quickAttack, 2);
		setMove(flameWheel, 3);
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
		Move iceFang = IceFang();
		setMove(scratch, 0);
		setMove(waterGun, 1);
		setMove(bite, 2);
		setMove(iceFang, 3);
	}
};