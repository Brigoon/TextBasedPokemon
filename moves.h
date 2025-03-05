#pragma once

#include <string>
#include "types.h"

enum class Categories
{
    physical,
    special,
    other
};

// how to handle attacks like icy wind that lower a stat (eg speed)?
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
    Move(std::string name_in, DamageType damage_type_in, Categories category_in, int damage_in, int accuracy_in, int power_pts_in, int flinch_prob_in, Statuses status_in = Statuses::normal);
    ~Move() {}

    Statuses status = Statuses::normal;

    std::string getName() { return name; }
    DamageType getDamageType() { return damageType; }
    Categories getCategory() { return category; }
    int getDamage() { return damage; }
    int getAccuracy() { return accuracy; }
    int getflinchProbability() { return flinchProbability; }
    int getPP() { return powerPts; }
    void setPP(int n) { powerPts = n; }

    bool appliesStatus() { return (status != Statuses::normal); }
    bool isValid() { return (name != ""); }

private:
    std::string name = "";
    DamageType damageType = Normal();
    Categories category = Categories::physical;
    int damage = 0;
    int accuracy = 0;
    int flinchProbability = 0;
    int powerPts = 0;
};