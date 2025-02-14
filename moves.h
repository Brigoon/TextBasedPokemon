#pragma once

#include <string>

enum class Categories
{
    physical,
    special,
    status
};
enum class DamageTypes
{
    normal,
    grass,
    fire,
    water
};
enum class Statuses
{
    normal,
    sleep,
    burn
};

class Move
{
public:
    Move() {}
    Move(std::string name_in, DamageTypes damage_type_in, Categories category_in, int damage_in, int accuracy_in, int flinch_prob_in, Statuses status_in = Statuses::normal);
    ~Move() {}

    Statuses status = Statuses::normal;

    std::string GetName() { return name; }
    DamageTypes GetDamageType() { return damageType; }
    Categories GetCategory() { return category; }
    int GetDamage() { return damage; }
    int GetAccuracy() { return accuracy; }
    int GetflinchProbability() { return flinchProbability; }

private:
    std::string name = "";
    DamageTypes damageType = DamageTypes::normal;
    Categories category = Categories::physical;
    int damage = 0;
    int accuracy = 0;
    int flinchProbability = 0;
};