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
// A: prob need to change flinchProbability to secondaryEffectProbability
// and associate effect with flinch/stat lower/confusion/etc
enum class Statuses
{
    normal,
    sleep,
    burn,
    freeze,
    paralyze,
    poison,
    confuse
};

class Move
{
public:
    Move() {}
    Move(std::string name_in, DamageType damage_type_in, Categories category_in, int damage_in, 
        int accuracy_in, int power_pts_in, int flinch_prob_in, Statuses status_in = Statuses::normal) : 
        name(name_in), damageType(damage_type_in), category(category_in), damage(damage_in), accuracy(accuracy_in), powerPts(power_pts_in), flinchProbability(flinch_prob_in), status(status_in)
    {
        if (appliesStatus() && flinchProbability != 0) {
            throw std::invalid_argument("Cannot have a non-zero flinch probability and a Move that also applies a status.");
        }
    }
    ~Move() {}

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
    Statuses status;
    Categories category = Categories::physical;
    int damage = 0;
    int accuracy = 0;
    int flinchProbability = 0;
    int powerPts = 0;
};