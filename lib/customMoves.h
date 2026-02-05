#pragma once

#include "moves.h"
#include "statuses.h"

// grass ------------------------------------------------------------------------------------------
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

class MagicalLeaf : public Move
{
public:
    MagicalLeaf() : Move("Magical Leaf", Types::grassType, Categories::special, 60, 101, 20, 0) {};
};

class SolarBeam : public Move
{
public:
    SolarBeam() : Move("Solar Beam", Types::grassType, Categories::special, 120, 100, 10, 0) {};
};

class SleepPowder : public Move
{
public:
    SleepPowder() : Move("Sleep Powder", Types::grassType, Categories::other, 0, 100, 15, 100, &Statuses::Sleeping) {};
};

// fire -------------------------------------------------------------------------------------------
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

// water ------------------------------------------------------------------------------------------
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

// ice --------------------------------------------------------------------------------------------
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

// normal -----------------------------------------------------------------------------------------
class Tackle : public Move
{
    public:
        Tackle() : Move("Tackle", Types::normalType, Categories::physical, 40, 100, 35, 0) {};
};

class Scratch : public Move
{
    public:
        Scratch() : Move("Scratch", Types::normalType, Categories::physical, 40, 100, 35, 0) {};
};

class QuickAttack : public Move
{
    public:
        QuickAttack() : Move("Quick Attack", Types::normalType, Categories::physical, 40, 100, 30, 0) {};
};

// dark -------------------------------------------------------------------------------------------
class Bite : public Move
{
    public:
        Bite() : Move("Bite", Types::darkType, Categories::physical, 60, 100, 25, 30) {};
};