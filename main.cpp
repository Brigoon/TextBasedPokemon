#include <iostream>
#include "customMonsters.h"
#include "battleEngine.h"
#include "types.h"

using namespace std;

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

	cout << grassType.GetStringName() << endl;
	cout << "These types are super effective: ";
	for (const auto &name : grassType.GetSuperEffectives())
	{
		cout << StringFromTS(name) << " ";
	}
	cout << endl;
	cout << "These types are not very effective: ";
	for (const auto &name : grassType.GetNotEffectives())
	{
		cout << StringFromTS(name) << " ";
	}
	cout << endl;

	cout << waterType.GetStringName() << endl;
	cout << "These types are super effective: ";
	for (const auto &name : waterType.GetSuperEffectives())
	{
		cout << StringFromTS(name) << " ";
	}
	cout << endl;
	cout << "These types are not very effective: ";
	for (const auto &name : waterType.GetNotEffectives())
	{
		cout << StringFromTS(name) << " ";
	}
	cout << endl;

	cout << ghostType.GetStringName() << endl;
	cout << "Ghost is immune to these types: ";
	for (const auto &name : ghostType.GetImmunes())
	{
		cout << StringFromTS(name) << " ";
	}
	cout << endl;
	cout << "A grass defender against an incoming water attack has factor = " << CalcTypeEffectiveness(&grassType, &waterType) << endl;
	cout << "A grass defender against an incoming fire attack has factor = " << CalcTypeEffectiveness(&grassType, &fireType) << endl;
	cout << "A ghost defender against an incoming normal attack has factor = " << CalcTypeEffectiveness(&ghostType, &normalType) << endl;
	// fsm.commenceBattle(&bulbasaur, &charmander);
}