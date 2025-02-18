#include <iostream>
#include "rng.h"
// #include "moves.h"

float Random::adjustDamage(int damage, bool verbose) // Move move
{
    float factor = applyUniformDistribution(damageLowerCase, damageUpperCase);

    if (binaryEvent(criticalProbability))
    {
        if (verbose) { std::cout << "Critical hit!" << std::endl; };
        factor *= criticalMultiplier;
    };

    // weather, stab, type still to be implmented as a damage adjustment
    // move.GetDamageType()s
    // in addition to considering stats of mons
    return damage * factor;
};