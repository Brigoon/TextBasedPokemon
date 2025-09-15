#include <iostream>
#include "rng.h"
// #include "moves.h"

Random::Random(char distribution_in) : distribution(distribution_in) {}

float Random::adjustValue(float value, bool verbose)
{
    return adjustValue(value, ' ', verbose);
}

float Random::adjustValue(float value, char distribution, bool verbose) // Move move
{
    switch (distribution)
    {
        case 'A':
        {
            return adjustAttackDamage(value, verbose);
        }
        case 'E':
        {
            return applyGaussianDistribution(value, 1.0);
        }
        case ' ':
        {
            return value;
        }
        default:
        {
            throw std::invalid_argument("Unknown location");
        }
    }
};

float Random::adjustValue(Move move, bool verbose)
{
    int damage = move.getDamage();

    return adjustAttackDamage(damage, verbose);
}

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