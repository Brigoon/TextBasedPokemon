#include <set>
#include "types.h"

using namespace std;

TypeString TSFromString(string str)
{
    if (str == "normal") { return TypeString::normal; }
    if (str == "grass") { return TypeString::grass; }
    if (str == "fire") { return TypeString::fire; }
    if (str == "water") { return TypeString::water; }
    if (str == "electric") { return TypeString::electric; }
    if (str == "ice") { return TypeString::ice; }
    if (str == "fighting") { return TypeString::fighting; }
    if (str == "poison") { return TypeString::poison; }
    if (str == "ground") { return TypeString::ground; }
    if (str == "flying") { return TypeString::flying; }
    if (str == "bug") { return TypeString::bug; }
    if (str == "rock") { return TypeString::rock; }
    if (str == "ghost") { return TypeString::ghost; }
    if (str == "dragon") { return TypeString::dragon; }
    if (str == "dark") { return TypeString::dark; }
    if (str == "steel") { return TypeString::steel; }
    if (str == "fairy") { return TypeString::fairy; }
    throw invalid_argument("invalid type " + str);
}

// for completeness, function to go the other way
// likely only for visibility purposes to user, should these be capitalized?
string StringFromTS(TypeString type)
{
    switch (type)
    {
        case TypeString::normal: return "normal";
        case TypeString::grass: return "grass";
        case TypeString::fire: return "fire";
        case TypeString::water: return "water";
        case TypeString::electric: return "electric";
        case TypeString::ice: return "ice";
        case TypeString::fighting: return "fighting";
        case TypeString::poison: return "poison";
        case TypeString::ground: return "ground";
        case TypeString::flying: return "flying";
        case TypeString::bug: return "bug";
        case TypeString::rock: return "rock";
        case TypeString::ghost: return "ghost";
        case TypeString::dragon: return "dragon";
        case TypeString::dark: return "dark";
        case TypeString::steel: return "steel";
        case TypeString::fairy: return "fairy";
    }
}

DamageType::DamageType(TypeString name_in, set<TypeString> strongAgainst_in, set<TypeString> weakAgainst_in, set<TypeString> immuneTo_in) : name(name_in), strongAgainst(strongAgainst_in), weakAgainst(weakAgainst_in), immuneTo(immuneTo_in)
{
}

float CalcTypeEffectiveness(DamageType *defender, DamageType *incoming)
{
    float factor;
    TypeString attackType = incoming->GetTypeName();
    set<TypeString> defendingWeaknesses = defender->GetSuperEffectives();
    set<TypeString> defendingStrengths = defender->GetNotEffectives();
    set<TypeString> defendingImmunes = defender->GetImmunes();

    if (defendingWeaknesses.find(attackType) != defendingWeaknesses.end())
    {
        factor = 2;
    }
    else if (defendingStrengths.find(attackType) != defendingStrengths.end())
    {
        factor = 1.0F / 2;
    }
    else if (defendingImmunes.find(attackType) != defendingImmunes.end())
    {
        factor = 0;
    }
    else
    {
        factor = 1;
    }
    return factor;
}