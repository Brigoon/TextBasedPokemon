#include <iostream>
#include "customMonsters.h"
#include "battleEngine.h"
#include "types.h"

void testRandomDamageAdjustments(int damage, int iterations = 5)
{
	Random randomizer;
	static bool verbose = false;
	for (int i = 0; i < iterations; i++)
	{
		std::cout << randomizer.adjustDamage(damage, verbose) << " ";
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

	std::cout << grassType.getStringName() << std::endl;
	std::cout << "These types are super effective: ";
	for (const auto &name : grassType.getSuperEffectives())
	{
		std::cout << StringFromTS(name) << " ";
	}
	std::cout << std::endl;
	std::cout << "These types are not very effective: ";
	for (const auto &name : grassType.getNotEffectives())
	{
		std::cout << StringFromTS(name) << " ";
	}
	std::cout << std::endl;

	std::cout << waterType.getStringName() << std::endl;
	std::cout << "These types are super effective: ";
	for (const auto &name : waterType.getSuperEffectives())
	{
		std::cout << StringFromTS(name) << " ";
	}
	std::cout << std::endl;
	std::cout << "These types are not very effective: ";
	for (const auto &name : waterType.getNotEffectives())
	{
		std::cout << StringFromTS(name) << " ";
	}
	std::cout << std::endl;

	std::cout << ghostType.getStringName() << std::endl;
	std::cout << "Ghost is immune to these types: ";
	for (const auto &name : ghostType.getImmunes())
	{
		std::cout << StringFromTS(name) << " ";
	}
	std::cout << std::endl;
	std::cout << "A grass defender against an incoming water attack has factor = " << calcTypeEffectiveness(&grassType, &waterType) << std::endl;
	std::cout << "A grass defender against an incoming fire attack has factor = " << calcTypeEffectiveness(&grassType, &fireType) << std::endl;
	std::cout << "A ghost defender against an incoming normal attack has factor = " << calcTypeEffectiveness(&ghostType, &normalType) << std::endl;

	fsm.commenceBattle(&bulbasaur, &charmander);

	testRandomDamageAdjustments(damage);
}