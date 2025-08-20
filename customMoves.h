#pragma once

#include "moves.h"

Move::Move(std::string name_in, DamageType damage_type_in, Categories category_in, int damage_in, int accuracy_in, int power_pts_in, int flinch_prob_in, Statuses status_in) : name(name_in), damageType(damage_type_in), category(category_in), damage(damage_in), accuracy(accuracy_in), powerPts(power_pts_in), flinchProbability(flinch_prob_in), status(status_in)
{
}

namespace Types
{
    DamageType normalType = Normal();
    DamageType fireType = Fire();
    DamageType waterType = Water();
    DamageType electricType = Electric();
    DamageType grassType = Grass();
    DamageType iceType = Ice();
    DamageType fightingType = Fighting();
    DamageType poisonType = Poison();
    DamageType groundType = Ground();
    DamageType flyingType = Flying();
    DamageType psychicType = Psychic();
    DamageType bugType = Bug();
    DamageType rockType = Rock();
    DamageType ghostType = Ghost();
    DamageType dragonType = Dragon();
    DamageType darkType = Dark();
    DamageType steelType = Steel();
    DamageType fairyType = Fairy();
}

// grass
class VineWhip : public Move
{
public:
    VineWhip() : Move("Vine Whip", Types::grassType, Categories::physical, 45, 100, 25, 0) {};
};

class RazorLeaf : public Move
{
public:
    RazorLeaf() : Move("Razor Leaf", Types::grassType, Categories::physical, 55, 95, 25, 0) {};
};

class SeedBomb : public Move
{
public:
    SeedBomb() : Move("Seed Bomb", Types::grassType, Categories::physical, 80, 100, 15, 0) {};
};

class SolarBeam : public Move
{
public:
    SolarBeam() : Move("Solar Beam", Types::grassType, Categories::special, 120, 100, 10, 0) {};
};

class SleepPowder : public Move
{
public:
    SleepPowder() : Move("Sleep Powder", Types::grassType, Categories::other, 0, 75, 15, 0, Statuses::sleep) {};
};

// fire
class Ember : public Move
{
public:
    Ember() : Move("Ember", Types::fireType, Categories::special, 40, 100, 25, 0) {};
};

class FireFang : public Move
{
public:
    FireFang() : Move("Fire Fang", Types::fireType, Categories::physical, 65, 95, 15, 10) {};
};

// water
class WaterGun : public Move
{
public:
    WaterGun() : Move("Water Gun", Types::waterType, Categories::special, 40, 100, 25, 0) {};
};

class WaterPulse : public Move
{
public:
    WaterPulse() : Move("Water Pulse", Types::waterType, Categories::special, 60, 100, 20, 0) {};
};

// ice
class IcyWind : public Move
{
public:
    IcyWind() : Move("Icy Wind", Types::waterType, Categories::special, 55, 95, 15, 0) {};
};

class IceShard : public Move
{
public:
    IceShard() : Move("Ice Shard", Types::waterType, Categories::physical, 40, 100, 30, 0) {};
};
