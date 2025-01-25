class Random
{
public:
    static bool criticalHit()
    {
        return true;
    };
    bool flinched()
    {
        return false;
    }
    float adjustDamage(int damage)
    {
        if (criticalHit())
        {
            damage = damage * criticalMultiplier;
        };
        return damage;
    };

private:
    float criticalMultiplier = 1.5;
    float criticalProbability = 1 / 24;
    float flinchProbability = 0;
};