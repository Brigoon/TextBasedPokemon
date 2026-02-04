#pragma once

#include <string>
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
        int accuracy_in, int power_pts_in, int secondary_effect_in, BaseStatus status_in = BaseStatus()) : 
        name(name_in), damageType(damage_type_in), category(category_in), damage(damage_in), accuracy(accuracy_in), powerPts(power_pts_in), secondaryEffect(secondary_effect_in), status(status_in)
    {
    }
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

    //bool appliesStatus() { return (status != Statuses::normal); }
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

class BaseStatus
{
    public:
        virtual void handleEffect(bool);
    private:
        const std::string initialMsg = "";
        const std::string recurringMsg = "";
};

class Sleep : public BaseStatus
{
    public:
        void handleEffect(Monster*, bool);
    private:
        const std::string initialMsg = " has fallen sleep!";
        const std::string recurringMsg = " is sound asleep!";
};

class Burn : public BaseStatus
{
    private:
        const std::string initialMsg = " has become burned!";
        const std::string recurringMsg = " is hurt by its burn!";
};

class Freeze : public BaseStatus
{
    private:
        const std::string initialMsg = " has become frozen solid!";
        const std::string recurringMsg = " is frozen solid!";
};

class Paralyze : public BaseStatus
{
    private:
        const std::string initialMsg = " has become paralyzed! It may be unable to move!";
        const std::string recurringMsg = " is frozen solid!";
};