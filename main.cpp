#include <iostream>
#include "customMonsters.h"
#include "battleEngine.h"
#include "rng.h"

using namespace std;

int main()
{
	Bulbasaur bulbasaur;
	Charmander charmander;
	Squirtle squirtle;
	BattleEngine::StateMachine fsm;
	Random randomizer;
	int attack = 50;

	fsm.commenceBattle(&bulbasaur, &charmander);
	cout << randomizer.adjustDamage(attack) << endl;
}