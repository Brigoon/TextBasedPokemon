#pragma once

#include <string>
#include <set>

using namespace std;

enum class TypeString
{
    normal,
    grass,
    fire,
    water,
    electric,
    ice,
    fighting,
    poison,
    ground,
    flying,
    bug,
    rock,
    ghost,
    dragon,
    dark,
    steel,
    fairy
};

TypeString TSFromString(string);
string StringFromTS(TypeString);

class DamageType
{
public:
    DamageType() {}
    DamageType(TypeString name_in, set<TypeString> strongAgainst_in, set<TypeString> weakAgainst_in, set<TypeString> immuneTo_in = {});
    ~DamageType() {}

    TypeString GetTypeName() { return name; }
    string GetStringName() { return StringFromTS(name); }
    set<TypeString> GetNotEffectives() { return strongAgainst; }
    set<TypeString> GetSuperEffectives() { return weakAgainst; }
    set<TypeString> GetImmunes() { return immuneTo; }

private:
    TypeString name;
    set<TypeString> strongAgainst;
    set<TypeString> weakAgainst;
    set<TypeString> immuneTo;
};
float CalcTypeEffectiveness(DamageType *, DamageType *);

class Normal : public DamageType
{
public:
    Normal() : DamageType(TypeString::normal, {}, {TypeString::fighting}, {TypeString::ghost}) {};
};

class Grass : public DamageType
{
public:
    Grass() : DamageType(TypeString::grass, {TypeString::water, TypeString::electric, TypeString::grass, TypeString::ground}, {TypeString::fire, TypeString::ice, TypeString::poison, TypeString::flying, TypeString::bug}) {};
};

class Fire : public DamageType
{
public:
    Fire() : DamageType(TypeString::fire, {TypeString::fire, TypeString::grass, TypeString::ice, TypeString::bug, TypeString::steel, TypeString::fairy}, {TypeString::water, TypeString::ground, TypeString::rock}) {};
};

class Water : public DamageType
{
public:
    Water() : DamageType(TypeString::water, {TypeString::fire, TypeString::water, TypeString::ice, TypeString::steel}, {TypeString::electric, TypeString::grass}) {};
};

class Ghost : public DamageType
{
public:
    Ghost() : DamageType(TypeString::ghost, {TypeString::ghost, TypeString::dark}, {TypeString::poison, TypeString::bug}, {TypeString::normal, TypeString::fighting}) {};
};