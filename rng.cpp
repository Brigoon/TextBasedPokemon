#include <iostream>
#include "rng.h"
// #include "moves.h"

Random::Random(char location_in) : location(location_in) {}

float Random::adjustValue(float value, bool verbose)
{
    return adjustValue(value, ' ', verbose);
}

float Random::adjustValue(float value, char distribution, bool verbose) // Move move
{
    if ((location == ' ') && (distribution == ' '))
    {
        throw std::invalid_argument("Since the location of the randomizer was not set, a distribution char must be passed.");
    }

    switch (location)
    {
        case 'M':
        {
            return adjustAttackDamage(value, verbose);
        }
        case ' ':
        {
            //std::cout << distribution << std::endl;
            return value;
        }
        default:
        {
            throw std::invalid_argument("Unknown location");
        }
    }
};

float Random::adjustAttackDamage(int damage, bool verbose)
{
    float factor = applyUniformDistribution(damageLowerCase, damageUpperCase);
    if (binaryEvent(criticalProbability))
    {
        if (verbose) { std::cout << "Critical hit!" << std::endl; };
        factor *= criticalMultiplier;
    };
    return damage * factor;
}