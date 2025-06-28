#pragma once

#include <string>
#include <set>

enum class TypeString
{
    normal,
    fire,
    water,
    electric,
    grass,
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



// subclasses
class Normal : public DamageType
{
public:
    Normal() : DamageType(TypeString::normal, {}, {TypeString::fighting}, {TypeString::ghost}) {};
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

class Electric : public DamageType
{
public:
    Electric() : DamageType(TypeString::electric, {TypeString::electric, TypeString::flying, TypeString::steel}, {TypeString::ground}) {};
};

class Grass : public DamageType
{
public:
    Grass() : DamageType(TypeString::grass, {TypeString::water, TypeString::electric, TypeString::grass, TypeString::ground}, {TypeString::fire, TypeString::ice, TypeString::poison, TypeString::flying, TypeString::bug}) {};
};

class Ice : public DamageType
{
public:
    Ice() : DamageType(TypeString::ice, {TypeString::ice}, {TypeString::fire, TypeString::fighting, TypeString::rock, TypeString::steel}) {};
};

class Fighting : public DamageType
{
public:
    Fighting() : DamageType(TypeString::fighting, {TypeString::bug, TypeString::rock, TypeString::dark}, {TypeString::flying, TypeString::psychic, TypeString::fairy}) {};
};

class Poison : public DamageType
{
public:
    Poison() : DamageType(TypeString::poison, {TypeString::grass, TypeString::fighting, TypeString::poison, TypeString::bug, TypeString::fairy}, {TypeString::ground, TypeString::psychic}) {};
};

class Ground : public DamageType
{
public:
    Ground() : DamageType(TypeString::ground, {TypeString::poison, TypeString::rock}, {TypeString::water, TypeString::grass, TypeString::ice}, {TypeString::electric}) {};
};

class Flying : public DamageType
{
public:
    Flying() : DamageType(TypeString::flying, {TypeString::grass, TypeString::fighting, TypeString::bug}, {TypeString::electric, TypeString::ice, TypeString::rock}, {TypeString::ground}) {};
};

class Psychic : public DamageType
{
public:
    Psychic() : DamageType(TypeString::psychic, {TypeString::fighting, TypeString::psychic}, {TypeString::bug, TypeString::ghost, TypeString::dark}) {};
};

class Bug : public DamageType
{
public:
    Bug() : DamageType(TypeString::bug, {TypeString::grass, TypeString::fighting, TypeString::ground}, {TypeString::fire, TypeString::flying, TypeString::rock}) {};
};

class Rock : public DamageType
{
public:
    Rock() : DamageType(TypeString::rock, {TypeString::normal, TypeString::fire, TypeString::poison, TypeString::flying}, {TypeString::water, TypeString::grass, TypeString::fighting, TypeString::ground, TypeString::steel}) {};
};

class Ghost : public DamageType
{
public:
    Ghost() : DamageType(TypeString::ghost, {TypeString::poison, TypeString::bug}, {TypeString::ghost, TypeString::dark}, {TypeString::normal, TypeString::fighting}) {};
};

class Dragon : public DamageType
{
public:
    Dragon() : DamageType(TypeString::dragon, {TypeString::fire, TypeString::water, TypeString::electric, TypeString::grass}, {TypeString::ice, TypeString::dragon, TypeString::fairy}) {};
};

class Dark : public DamageType
{
public:
    Dark() : DamageType(TypeString::dark, {TypeString::ghost, TypeString::dark}, {TypeString::fighting, TypeString::bug, TypeString::fairy}, {TypeString::psychic}) {};
};

class Steel : public DamageType
{
public:
    Steel() : DamageType(TypeString::steel, {TypeString::normal, TypeString::grass, TypeString::ice, TypeString::flying, TypeString::psychic, TypeString::bug, TypeString::rock, TypeString::dragon, TypeString::steel, TypeString::fairy}, {TypeString::fire, TypeString::fighting, TypeString::ground}, {TypeString::poison}) {};
};

class Fairy : public DamageType
{
public:
    Fairy() : DamageType(TypeString::fairy, {TypeString::fighting, TypeString::bug, TypeString::dark}, {TypeString::bug, TypeString::steel}, {TypeString::dragon}) {};
};