#include "moves.h"

Move::Move(std::string name_in, DamageType damage_type_in, Categories category_in, int damage_in, int accuracy_in, int power_pts_in, int flinch_prob_in, Statuses status_in) : name(name_in), damageType(damage_type_in), category(category_in), damage(damage_in), accuracy(accuracy_in), powerPts(power_pts_in), flinchProbability(flinch_prob_in), status(status_in)
{
}

bool Move::appliesStatus()
{
    if (status != Statuses::normal)  { return true; }
    else { return false; }
}