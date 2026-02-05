#include <iostream>
#include <string>
#include "monster.h"
#include "statuses.h"

namespace Statuses {
    void BaseStatus::handleEffect(Monster* monster, bool firstMsg) const {
        std::string msg = monster->getName();
        msg += firstMsg ? initialMsg : recurringMsg;
        std::cout << msg;
    }
    void Sleep::handleEffect(Monster* monster, bool firstMsg) {
        BaseStatus::handleEffect(monster, firstMsg);
    }
    
    NoStatus None;
    Sleep Sleeping;
    Burn Burnt;
    Freeze Frozen;
    Paralyze Paralyzed;
    Flinch Flinched;
}