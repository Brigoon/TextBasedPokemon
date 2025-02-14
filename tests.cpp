#include "rng.h"

bool TestRandomDamageAdjustments(int damage, int iterations = 5)
{
    Random randomizer;
    float damages[5];
    static bool verbose = false;
    for (int i = 0; i < iterations; i++)
	{
		damages[i] = randomizer.AdjustDamage(damage, verbose);
	};
}