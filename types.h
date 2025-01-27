#pragma once

#include <string>
#include <set>

using namespace std;

class DamageType
{
public:
    DamageType() {}
    DamageType(string name_in, set<string> strongAgainst_in, set<string> weakAgainst_in, set<string> immuneTo_in = {});
    ~DamageType() {}

    string GetName() { return name; }
    set<string> GetNotEffectives() { return strongAgainst; }
    set<string> GetSuperEffectives() { return weakAgainst; }
    set<string> GetImmunes() { return immuneTo; }

    float CalcTypeEffectiveness(DamageType *, DamageType *);

private:
    string name;
    set<string> strongAgainst;
    set<string> weakAgainst;
    set<string> immuneTo;
};

class Grass : public DamageType
{
public:
    Grass() : DamageType("grass", {"water", "electric", "grass", "ground"}, {"fire", "ice", "poison", "flying", "bug"}) {};
};

class Fire : public DamageType
{
public:
    Fire() : DamageType("fire", {"fire", "grass", "ice", "bug", "steel", "fairy"}, {"water", "ground", "rock"}) {};
};

class Water : public DamageType
{
public:
    Water() : DamageType("water", {"fire", "water", "ice", "steel"}, {"electric", "grass"}) {};
};