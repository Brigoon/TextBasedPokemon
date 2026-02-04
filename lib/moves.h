#pragma once

#include <string>
#include "statuses.h"
#include "types.h"

enum class Categories
{
    physical,
    special,
    other
};

class Move
{
public:
    Move() {}
    Move(std::string name_in, DamageType damage_type_in, Categories category_in, int damage_in,
         int accuracy_in, int power_pts_in, int secondary_effect_in, BaseStatus status_in = BaseStatus());
    ~Move() {}

    std::string getName() { return name; }
    DamageType getDamageType() { return damageType; }
    Categories getCategory() { return category; }
    BaseStatus getStatus() { return status; }
    int getDamage() { return damage; }
    int getAccuracy() { return accuracy; }
    int getSecondaryEffectProbability() { return secondaryEffect; }
    int getPP() { return powerPts; }
    void setPP(int n) { powerPts = n; }

    // bool appliesStatus() { return (status != Statuses::normal); }
    bool isValid() { return (name != ""); }

private:
    std::string name = "";
    DamageType damageType = Normal();
    Categories category = Categories::physical;
    int damage = 0;
    int accuracy = 0;
    int powerPts = 0;
    int secondaryEffect = 0;
    BaseStatus status;
};
