#include <random>

class Random
{
public:
    bool criticalHit()
    {
        return apply_bernoulli(criticalProbability);
    };
    bool flinched(float probability = 0)
    {
        return apply_bernoulli(probability);
    }
    float adjustDamage(int damage)
    {
        damage *= applyUniformDistribution(damageLowerCase, damageUpperCase);

        if (criticalHit())
        {
            std::cout << "Critical hit!" << std::endl;
            damage = damage * criticalMultiplier;
        };
        return damage;
    };

private:
    float criticalMultiplier = 1.5;
    float criticalProbability = 1.0F / 2;
    float flinchProbability = 0;
    float damageLowerCase = 0.85;
    float damageUpperCase = 1.05;

    bool apply_bernoulli(float probability)
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