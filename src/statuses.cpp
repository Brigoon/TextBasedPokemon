#include <iostream>
#include <string>
#include "monster.h"
#include "statuses.h"

namespace Statuses
{
    void BaseStatus::handleEffect(Monster* monster, bool firstMsg, bool hasStatus) const
    {
        const std::string msg = firstMsg ? (hasStatus ? repeatMsg : initialMsg) : recurringMsg;
        std::cout << monster->getName() << msg << std::endl;
    }

    NoStatus None;
    Sleep Sleeping;
    Burn Burnt;
    Freeze Frozen;
    Paralyze Paralyzed;
    Poison Poisoned;
    Flinch Flinched;
}