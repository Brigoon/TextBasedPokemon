#pragma once

#include <iostream>
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
    Move(std::string name_in, Types::DamageType damage_type_in, Categories category_in, int damage_in,
         int accuracy_in, int power_pts_in, int secondary_effect_in, const Statuses::BaseStatus* status_in = nullptr) :
         name(name_in), damageType(damage_type_in), category(category_in), damage(damage_in),
         accuracy(accuracy_in), powerPts(power_pts_in), secondaryEffect(secondary_effect_in), 
         status(status_in ? status_in : &Statuses::None)
         {}
    ~Move() {}

    std::string getName() { return name; }
    Types::DamageType getDamageType() { return damageType; }
    Categories getCategory() { return category; }
    const Statuses::BaseStatus* getStatus() { return status; }
    int getDamage() { return damage; }
    int getAccuracy() { return accuracy; }
    int getSecondaryEffectProbability() { return secondaryEffect; }
    int getPP() { return powerPts; }
    void setPP(int n) { powerPts = n; }

    bool isValid() { return (name != ""); }

private:
    std::string name = "";
    Types::DamageType damageType = Types::normalType;
    Categories category = Categories::physical;
    int damage = 0;
    int accuracy = 0;
    int powerPts = 0;
    int secondaryEffect = 0;
    const Statuses::BaseStatus* status;
};
