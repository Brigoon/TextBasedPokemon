#pragma once

#include "monster.h"
#include "customMoves.h"

Move::Move(std::string name_in, DamageType damage_type_in, Categories category_in, int damage_in, int accuracy_in, int power_pts_in, int flinch_prob_in, Statuses status_in) : name(name_in), damageType(damage_type_in), category(category_in), damage(damage_in), accuracy(accuracy_in), powerPts(power_pts_in), flinchProbability(flinch_prob_in), status(status_in)
{
}

class Bulbasaur : public Monster
{
public:
	Bulbasaur(std::string n = "Bulbasaur") : Monster(45, 49, 49, 65, 65, 45, n)
	{
		Move vineWhip = VineWhip();
		setMove(vineWhip);
	}
};

class Charmander : public Monster
{
public:
	Charmander(std::string n = "Charmander") : Monster(39, 52, 43, 60, 50, 65, n)
	{
		Move ember = Ember();
		setMove(ember);
	}
};

class Squirtle : public Monster
{
public:
	Squirtle(std::string n = "Squirtle") : Monster(44, 48, 65, 50, 64, 43, n)
	{
		Move waterGun = WaterGun();
		setMove(waterGun);
	}
};

class Seel : public Monster
{
public:
	Seel(std::string n = "Seel") : Monster(65, 45, 55, 45, 70, 45, n)
	{
		Move icyWind = IcyWind();
		setMove(icyWind);
	}
};