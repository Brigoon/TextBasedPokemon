#include <iostream>
#include <string>
#include "monster.h"
#include "statuses.h"

namespace Statuses
{
    Random randomizer;
    NoStatus None;
    Sleep Sleeping;
    Burn Burnt;
    Freeze Frozen;
    Paralyze Paralyzed;
    Poison Poisoned;
    Flinch Flinched;

    bool Freeze::willAttack() const
    {
        return randomizer.binaryEvent(1/4.0F) ? true : false;
    }

    bool Paralyze::willAttack() const
    {
        return randomizer.binaryEvent(1/5.0F) ? true : false;
    }

    bool Sleep::willAttack() const
    {
        return randomizer.binaryEvent(1/3.0F) ? true : false;
    }

    void BaseStatus::reduceHealth(Monster* monster, bool firstMsg, bool hasStatus) const
    {
        BaseStatus::handleEffect(monster, firstMsg, hasStatus);
        int dmg = monster->getMaxHealth() / 8;
        monster->takeDamage(dmg);
    }
    void BaseStatus::handleEffect(Monster* monster, bool firstMsg, bool hasStatus) const
    {
        const std::string msg = firstMsg ? (hasStatus ? repeatMsg : initialMsg) : recurringMsg;
        std::cout << monster->getName() << msg << std::endl;
    }

    void Burn::handleEffect(Monster* monster, bool firstMsg, bool hasStatus) const
    {
        BaseStatus::reduceHealth(monster,  firstMsg, hasStatus);
    }

    void Poison::handleEffect(Monster* monster, bool firstMsg, bool hasStatus) const
    {
        BaseStatus::reduceHealth(monster,  firstMsg, hasStatus);
    }
}