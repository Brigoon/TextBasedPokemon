#pragma once

#include "moves.h"

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

// grass
class VineWhip : public Move
{
public:
    VineWhip() : Move("Vine Whip", grassType, Categories::physical, 45, 100, 0) {};
};

class RazorLeaf : public Move
{
public:
    RazorLeaf() : Move("Razor Leaf", grassType, Categories::physical, 55, 95, 0) {};
};

class SeedBomb : public Move
{
public:
    SeedBomb() : Move("Seed Bomb", grassType, Categories::physical, 80, 100, 0) {};
};

class SolarBeam : public Move
{
public:
    SolarBeam() : Move("Solar Beam", grassType, Categories::special, 120, 100, 0) {};
};

class SleepPowder : public Move
{
public:
    SleepPowder() : Move("Sleep Powder", grassType, Categories::status, 0, 75, 0, Statuses::sleep) {};
};

// fire
class Ember : public Move
{
public:
    Ember() : Move("Ember", fireType, Categories::special, 40, 100, 0) {};
};

class FireFang : public Move
{
public:
    FireFang() : Move("Fire Fang", fireType, Categories::physical, 65, 95, 10) {};
};

// water
class WaterGun : public Move
{
public:
    WaterGun() : Move("Water Gun", waterType, Categories::special, 40, 100, 0) {};
};

// ice
class IcyWind : public Move
{
public:
    IcyWind() : Move("Icy Wind", waterType, Categories::special, 55, 95, 0) {};
};
