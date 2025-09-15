#pragma once

#include <random>

class Random
{
public:
    Random() {}
    Random(char location_in);
    ~Random() {}
    bool binaryEvent(float prob = 0) { return applyBernoulli(prob); };
    float adjustValue(float, bool = true);
    float adjustValue(float, char, bool = true);

private:
    const char location = ' ';
    const float criticalMultiplier = 1.5;
    const float criticalProbability = 1.0F / 2;
    const float damageLowerCase = 0.85;
    const float damageUpperCase = 1.05;

    float adjustAttackDamage(int, bool = true);

    std::mt19937 getDevice()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        return gen;
    }
    bool applyBernoulli(float probability)
    {
        std::mt19937 gen = getDevice();
        std::bernoulli_distribution p(probability);
        return p(gen);
    }
    float applyUniformDistribution(float lower, float upper)
    {
        std::mt19937 gen = getDevice();
        std::uniform_real_distribution<> p(lower, upper);
        return p(gen);
    }
    float applyGaussianDistribution(float mean, float sigma)
    {
        std::mt19937 gen = getDevice();
        std::normal_distribution<> p(mean, sigma);
        return p(gen);
    }
};