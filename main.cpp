#include <iostream>
#include "customMonsters.h"
#include "battleEngine.h"
#include "types.h"

void TestRandomDamageAdjustments(int damage, int iterations = 5)
{
    Random randomizer;
    static bool verbose = false;
    for (int i = 0; i < iterations; i++)
	{
		std::cout << randomizer.adjustDamage(damage, verbose) << " ";
	};
	std::cout << std::endl;
}

void PrintEffectives(DamageType* type)
{
	std::cout << type->GetStringName() << std::endl;
	std::cout << "These types are super effective: ";
	for (const auto &name : type->GetSuperEffectives())
	{
		std::cout << StringFromTS(name) << " ";
	}
	std::cout << std::endl;

	std::cout << "These types are not very effective: ";
	for (const auto &name : type->GetNotEffectives())
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
	static int damage = 50;

	fsm.commenceBattle(&bulbasaur, &charmander);

	PrintEffectives(&grassType);
	PrintEffectives(&ghostType);
	TestRandomDamageAdjustments(damage);
}