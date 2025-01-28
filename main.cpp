#include <iostream>
#include "customMonsters.h"
#include "battleEngine.h"

using namespace std;

int main()
{
	Bulbasaur bulbasaur;
	Charmander charmander;
	Squirtle squirtle;
	BattleEngine::StateMachine fsm;
	Random randomizer;
	const int damage = 50;
	const bool verbose = false;

	fsm.commenceBattle(&bulbasaur, &charmander);
	for (int i = 0; i < 5; i++)
	{
		cout << randomizer.AdjustDamage(damage, verbose) << " ";
	};
	cout << endl;
}