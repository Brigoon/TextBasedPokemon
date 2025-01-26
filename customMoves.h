#pragma once

#include "moves.h"

Move::Move(std::string name_in, DamageTypes damage_type_in, Categories category_in, int damage_in, int accuracy_in, int flinch_prob_in, Statuses status_in) : name(name_in), damageType(damage_type_in), category(category_in), damage(damage_in), accuracy(accuracy_in), flinchProbability(flinch_prob_in), status(status_in)
{
}
// grass
class VineWhip : public Move
{
public:
    VineWhip() : Move("Vine Whip", DamageTypes::grass, Categories::physical, 45, 100, 0) {};
};

class RazorLeaf : public Move
{
public:
    RazorLeaf() : Move("Razor Leaf", DamageTypes::grass, Categories::physical, 55, 95, 0) {};
};

class SeedBomb : public Move
{
public:
    SeedBomb() : Move("Seed Bomb", DamageTypes::grass, Categories::physical, 80, 100, 0) {};
};

class SolarBeam : public Move
{
public:
    SolarBeam() : Move("Solar Beam", DamageTypes::grass, Categories::special, 120, 100, 0) {};
};

class SleepPowder : public Move
{
public:
    SleepPowder() : Move("Sleep Powder", DamageTypes::grass, Categories::status, 0, 75, 0, Statuses::sleep) {};
};

// fire
class Ember : public Move
{
public:
    Ember() : Move("Ember", DamageTypes::fire, Categories::special, 40, 100, 0) {};
};

class FireFang : public Move
{
public:
    FireFang() : Move("Fire Fang", DamageTypes::fire, Categories::physical, 65, 95, 10) {};
};

// water
class WaterGun : public Move
{
public:
    WaterGun() : Move("Water Gun", DamageTypes::water, Categories::special, 40, 100, 0) {};
};
