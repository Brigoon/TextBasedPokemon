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
		std::cout << randomizer.AdjustDamage(damage, verbose) << " ";
	};
	std::cout << std::endl;
}

int main()
{
	Bulbasaur bulbasaur;
	Charmander charmander;
	Squirtle squirtle;
	BattleEngine::StateMachine fsm;
	Normal normalType;
	Grass grassType;
	Water waterType;
	Fire fireType;
	Ghost ghostType;
	static int damage = 50;

	std::cout << grassType.GetStringName() << std::endl;
	std::cout << "These types are super effective: ";
	for (const auto &name : grassType.GetSuperEffectives())
	{
		std::cout << StringFromTS(name) << " ";
	}
	std::cout << std::endl;
	std::cout << "These types are not very effective: ";
	for (const auto &name : grassType.GetNotEffectives())
	{
		std::cout << StringFromTS(name) << " ";
	}
	std::cout << std::endl;

	std::cout << waterType.GetStringName() << std::endl;
	std::cout << "These types are super effective: ";
	for (const auto &name : waterType.GetSuperEffectives())
	{
		std::cout << StringFromTS(name) << " ";
	}
	std::cout << std::endl;
	std::cout << "These types are not very effective: ";
	for (const auto &name : waterType.GetNotEffectives())
	{
		std::cout << StringFromTS(name) << " ";
	}
	std::cout << std::endl;

	std::cout << ghostType.GetStringName() << std::endl;
	std::cout << "Ghost is immune to these types: ";
	for (const auto &name : ghostType.GetImmunes())
	{
		std::cout << StringFromTS(name) << " ";
	}
	std::cout << std::endl;
	std::cout << "A grass defender against an incoming water attack has factor = " << CalcTypeEffectiveness(&grassType, &waterType) << std::endl;
	std::cout << "A grass defender against an incoming fire attack has factor = " << CalcTypeEffectiveness(&grassType, &fireType) << std::endl;
	std::cout << "A ghost defender against an incoming normal attack has factor = " << CalcTypeEffectiveness(&ghostType, &normalType) << std::endl;
	
	fsm.commenceBattle(&bulbasaur, &charmander);

	TestRandomDamageAdjustments(damage);
}