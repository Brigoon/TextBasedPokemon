#include <random>

class Random
{
public:
    bool binaryEvent(float probability = 0)
    {
        return applyBernoulli(probability);
    };
    float AdjustDamage(int damage);

private:
    float criticalMultiplier = 1.5;
    float criticalProbability = 1.0F / 2;
    float damageLowerCase = 0.85;
    float damageUpperCase = 1.05;

    bool applyBernoulli(float probability)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::bernoulli_distribution p(probability);
        return p(gen);
    }
    float applyUniformDistribution(float lower, float upper)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> p(lower, upper);
        return p(gen);
    }
};