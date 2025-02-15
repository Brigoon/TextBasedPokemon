#pragma once

#include <string>
#include "types.h"

enum class Categories
{
    physical,
    special,
    status
};

enum class Statuses
{
    normal,
    sleep,
    burn,
    freeze,
    paralyze,
    poison
};

class Move
{
public:
    Move() {}
    Move(std::string name_in, DamageType damage_type_in, Categories category_in, int damage_in, int accuracy_in, int flinch_prob_in, Statuses status_in = Statuses::normal);
    ~Move() {}

    Statuses status = Statuses::normal;

    std::string GetName() { return name; }
    DamageType GetDamageType() { return damageType; }
    Categories GetCategory() { return category; }
    int GetDamage() { return damage; }
    int GetAccuracy() { return accuracy; }
    int GetflinchProbability() { return flinchProbability; }

    bool appliesStatus();

private:
    std::string name = "";
    DamageType damageType = Normal();
    Categories category = Categories::physical;
    int damage = 0;
    int accuracy = 0;
    int flinchProbability = 0;
};