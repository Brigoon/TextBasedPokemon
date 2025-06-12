#pragma once

#include <string>
#include <set>

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
    psychic,
    bug,
    rock,
    ghost,
    dragon,
    dark,
    steel,
    fairy
};

TypeString TSFromString(std::string);
std::string StringFromTS(TypeString);

class DamageType
{
public:
    DamageType() {}
    DamageType(TypeString name_in, std::set<TypeString> strongAgainst_in, std::set<TypeString> weakAgainst_in, std::set<TypeString> immuneTo_in = {});
    ~DamageType() {}

    TypeString getTypeName() { return name; }
    std::string getStringName() { return StringFromTS(name); }
    std::set<TypeString> getNotEffectives() { return strongAgainst; }
    std::set<TypeString> getSuperEffectives() { return weakAgainst; }
    std::set<TypeString> getImmunes() { return immuneTo; }

private:
    TypeString name;
    std::set<TypeString> strongAgainst;
    std::set<TypeString> weakAgainst;
    std::set<TypeString> immuneTo;
};
float calcTypeEffectiveness(DamageType *, DamageType *);

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