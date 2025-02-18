#include <iostream>
#include "customMonsters.h"
#include "battleEngine.h"
#include "types.h"

void testRandomDamageAdjustments(int damage, int iterations = 5)
{
    Random randomizer;
    const bool verbose = false;
    for (int i = 0; i < iterations; i++)
	{
		std::cout << randomizer.adjustDamage(damage, verbose) << " ";
	};
	std::cout << std::endl;
}

void printEffectives(DamageType* type)
{
	std::cout << type->getStringName() << std::endl;
	std::cout << "These types are super effective: ";
	for (const auto &name : type->getSuperEffectives())
	{
		std::cout << StringFromTS(name) << " ";
	}
	std::cout << std::endl;

	std::cout << "These types are not very effective: ";
	for (const auto &name : type->getNotEffectives())
	{
		std::cout << StringFromTS(name) << " ";
	}
	std::cout << std::endl;
}

int main()
{
	Bulbasaur bulbasaur;
	Charmander charmander;
	Squirtle squirtle;
	BattleEngine::StateMachine fsm;
	Grass grassType;
	Ghost ghostType;
	const int damage = 50;

	fsm.commenceBattle(&bulbasaur, &charmander);

	printEffectives(&grassType);
	printEffectives(&ghostType);
	testRandomDamageAdjustments(damage);
}