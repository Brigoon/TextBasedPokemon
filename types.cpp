#include <string>
#include <set>
#include "types.h"

using namespace std;

DamageType::DamageType(string name_in, set<string> strongAgainst_in, set<string> weakAgainst_in, set<string> immuneTo_in) : name(name_in), strongAgainst(strongAgainst_in), weakAgainst(weakAgainst_in), immuneTo(immuneTo_in)
{
}

float DamageType::CalcTypeEffectiveness(DamageType *defender, DamageType *incoming)
{
    float factor;
    string attackType = incoming->GetName();
    set<string> defendingWeaknesses = defender->GetSuperEffectives();
    set<string> defendingStrengths = defender->GetNotEffectives();
    set<string> defendingImmunes = defender->GetImmunes();

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