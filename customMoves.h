#include "moves.h"

Move::Move(std::string name_in, DamageTypes damage_type_in, Categories category_in, int damage_in, int accuracy_in, int flinch_prob_in) : name(name_in), damageType(damage_type_in), category(category_in), damage(damage_in), accuracy(accuracy_in), flinchProbability(flinch_prob_in)
{
}
class VineWhip : public Move
{
public:
    VineWhip() : Move("Vine Whip", DamageTypes::grass, Categories::physical, 45, 100, 0) {};
};

class Ember : public Move
{
public:
    Ember() : Move("Ember", DamageTypes::fire, Categories::special, 40, 100, 0) {};
};

class WaterGun : public Move
{
public:
    WaterGun() : Move("Water Gun", DamageTypes::water, Categories::special, 40, 100, 0) {};
};

class FireFang : public Move
{
public:
    FireFang() : Move("Fire Fang", DamageTypes::fire, Categories::physical, 65, 95, 10) {};
};