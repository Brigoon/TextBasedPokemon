#include <iostream>
#include "rng.h"
// #include "moves.h"


float Random::adjustValue(float value, float lower, float upperOrSigma, bool verbose)
{
    return adjustValue(value, lower, upperOrSigma, verbose, distribution);
}
float Random::adjustValue(float value, float lower, float upperOrSigma, bool verbose, char distribution_arg)
{
    float factor;
    switch (distribution_arg) {
        case 'A': 
        case 'U':
            factor = applyUniformDistribution(lower, upperOrSigma);
            if (verbose) { std::cout << "Factor applied: " << factor << std::endl; };
            value *= factor;
            break;
        case 'I':
        case 'N':
            factor = value;
            value = applyGaussianDistribution(value, upperOrSigma);
            if (verbose) { std::cout << "New value: " << value << ". Started at " << factor << std::endl; };
            break; 
        case ' ':
            if (verbose) { std::cout << "No distribution input, returning same value" << std::endl; };
            break; //not technically needed, but here to be explicit that we return same value
        default:
            throw std::invalid_argument("Unknown distribution");
    }
    return value;
}

float Random::adjustValue(Move* move, bool verbose)
{
    int damage = move->getDamage();

    return adjustAttackDamage(damage, verbose);
}

float Random::adjustAttackDamage(int damage, bool verbose)
{
    float factor = applyUniformDistribution(damageLowerCase, damageUpperCase);
    if ((damage > 0) && (binaryEvent(criticalProbability)))
    {
        if (verbose) { std::cout << "Critical hit!" << std::endl; };
        factor *= criticalMultiplier;
    };
    return damage * factor;
}