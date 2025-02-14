#pragma once

#include <random>

class Random
{
public:
    bool BinaryEvent(float prob = 0) { return ApplyBernoulli(prob); };
    float AdjustDamage(int, bool = true);

private:
    const float criticalMultiplier = 1.5;
    const float criticalProbability = 1.0F / 2;
    const float damageLowerCase = 0.85;
    const float damageUpperCase = 1.05;

    bool ApplyBernoulli(float probability)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::bernoulli_distribution p(probability);
        return p(gen);
    }
    float ApplyUniformDistribution(float lower, float upper)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> p(lower, upper);
        return p(gen);
    }
};