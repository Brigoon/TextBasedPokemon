#include <iostream>
#include "rng.h"
// #include "moves.h"

Random::Random()
{
}

float Random::AdjustDamage(int damage) // Move move
{
    float factor = Random::applyUniformDistribution(damageLowerCase, damageUpperCase);

    if (binaryEvent(criticalProbability))
    {
        std::cout << "Critical hit!" << std::endl;
        factor *= criticalMultiplier;
    };

    // weather, stab, type still to be implmented as a damage adjustment
    // move.GetDamageType()
    // in addition to considering stats of mons
    return damage * factor;
};