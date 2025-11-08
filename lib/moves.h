#pragma once

#include <string>
#include "types.h"

enum class Categories
{
    physical,
    special,
    other
};

<<<<<<< HEAD
=======
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

>>>>>>> origin/main
class Move
{
public:
    Move() {}
    Move(std::string name_in, DamageType damage_type_in, Categories category_in, int damage_in, 
<<<<<<< HEAD
        int accuracy_in, int power_pts_in, int secondary_effect_in, BaseStatus status_in = BaseStatus()) : 
        name(name_in), damageType(damage_type_in), category(category_in), damage(damage_in), accuracy(accuracy_in), powerPts(power_pts_in), secondaryEffect(secondary_effect_in), status(status_in)
    {
=======
        int accuracy_in, int power_pts_in, int flinch_prob_in, Statuses status_in = Statuses::normal) : 
        name(name_in), damageType(damage_type_in), category(category_in), damage(damage_in), accuracy(accuracy_in), powerPts(power_pts_in), flinchProbability(flinch_prob_in), status(status_in)
    {
        if (appliesStatus() && flinchProbability != 0) {
            throw std::invalid_argument("Cannot have a non-zero flinch probability and a Move that also applies a status.");
        }
>>>>>>> origin/main
    }
    ~Move() {}

    std::string getName() { return name; }
    DamageType getDamageType() { return damageType; }
    Categories getCategory() { return category; }
<<<<<<< HEAD
    BaseStatus getStatus() { return status; }
    int getDamage() { return damage; }
    int getAccuracy() { return accuracy; }
    int getSecondaryEffectProbability() { return secondaryEffect; }
    int getPP() { return powerPts; }
    void setPP(int n) { powerPts = n; }

    //bool appliesStatus() { return (status != Statuses::normal); }
=======
    int getDamage() { return damage; }
    int getAccuracy() { return accuracy; }
    int getflinchProbability() { return flinchProbability; }
    int getPP() { return powerPts; }
    void setPP(int n) { powerPts = n; }

    bool appliesStatus() { return (status != Statuses::normal); }
>>>>>>> origin/main
    bool isValid() { return (name != ""); }

private:
    std::string name = "";
    DamageType damageType = Normal();
<<<<<<< HEAD
    Categories category = Categories::physical;
    BaseStatus status;
    int damage = 0;
    int accuracy = 0;
    int secondaryEffect = 0;
    int powerPts = 0;
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
=======
    Statuses status;
    Categories category = Categories::physical;
    int damage = 0;
    int accuracy = 0;
    int flinchProbability = 0;
    int powerPts = 0;
>>>>>>> origin/main
};