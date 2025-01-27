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
	Grass grassType;
	Water waterType;

	cout << grassType.GetName() << endl;
	cout << "These types are super effective: ";
	for (const auto &name : grassType.GetSuperEffectives())
	{
		cout << name << " ";
	}
	cout << endl;
	cout << "These types are not very effective: ";
	for (const auto &name : grassType.GetNotEffectives())
	{
		cout << name << " ";
	}
	cout << endl;

	cout << waterType.GetName() << endl;
	cout << "These types are super effective: ";
	for (const auto &name : waterType.GetSuperEffectives())
	{
		cout << name << " ";
	}
	cout << endl;
	cout << "These types are not very effective: ";
	for (const auto &name : waterType.GetNotEffectives())
	{
		cout << name << " ";
	}
	cout << endl;
	// fsm.commenceBattle(&bulbasaur, &charmander);
}