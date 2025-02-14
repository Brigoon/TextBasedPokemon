#include "customMonsters.h"
#include "battleEngine.h"

int main()
{
	Bulbasaur bulbasaur;
	Charmander charmander;
	Squirtle squirtle;
	BattleEngine::StateMachine fsm;

	fsm.commenceBattle(&bulbasaur, &charmander);

}