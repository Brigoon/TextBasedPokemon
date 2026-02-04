#include <iostream>
#include "monster.h"
#include "moves.h"
#include "types.h"

Move::Move(std::string name_in, DamageType damage_type_in, Categories category_in, int damage_in,
           int accuracy_in, int power_pts_in, int secondary_effect_in, BaseStatus status_in = BaseStatus()) :
           name(name_in), damageType(), category(Categories::physical), damage(0), accuracy(0), powerPts(0), secondaryEffect(0), status(status_in)
{
}


void BaseStatus::handleEffect(bool initialApply) {
    if (initialApply) { std::cout << initialMsg; }
    else {std::cout << recurringMsg; }
}
void Sleep::handleEffect(Monster* monster, bool initialApply) {
    BaseStatus::handleEffect(initialApply);
}