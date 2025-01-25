#include <iostream>
#include "battleEngine.h"

void BattleEngine::StateMachine::commenceBattle(Monster* a, Monster* b)
{
	firstMonster = a;
	secondMonster = b;

	if (firstMonster->GetCurrentHealth() == 0)
	{
		std::cout << firstMonster->GetName() << " has no health and cannot battle!\n";
		curState = States::NoState;
	}
	else if (secondMonster->GetCurrentHealth() == 0)
	{
		std::cout << secondMonster->GetName() << " has no health and cannot battle!\n";
		curState = States::NoState;
	}
	else
		curState = States::Intro;

	while (curState != States::NoState)
	{
		switch (curState)
		{
		case BattleEngine::States::Intro:
			handleIntro();
			break;
		case BattleEngine::States::Choose:
			handleChoose();
			break;
		case BattleEngine::States::Battle:
			handleBattle();
			break;
		case BattleEngine::States::Conclusion:
			handleConclusion();
			break;
		default:
			break;
		}
	}
}

void BattleEngine::StateMachine::handleIntro()
{
	std::cout << firstMonster->GetName() << " was sent out!\n";
	std::cout << secondMonster->GetName() << " was sent out!\n\n";

	// abilities, items, weather, etc can occur here

	curState = States::Choose;
}

void BattleEngine::StateMachine::handleChoose()
{
	// would need to check for abilities, items, weather, etc here

	curState = States::Battle;
}

void BattleEngine::StateMachine::handleBattle()
{
	// speed check and then apply damage
	if (firstMonster->GetSpeed() == secondMonster->GetSpeed())
	{
		//randomizer for first attack
	}
	else if (firstMonster->GetSpeed() > secondMonster->GetSpeed())
	{
		secondMonster->TakeDamage(firstMonster);
		firstMonster->TakeDamage(secondMonster);
	}
	else
	{
		firstMonster->TakeDamage(secondMonster);
		secondMonster->TakeDamage(firstMonster);
	}

	if (firstMonster->GetCurrentHealth() == 0)
	{
		std::cout << secondMonster->GetName() << " has won the battle!\n\n";
		curState = States::Conclusion;
	}
	else if (secondMonster->GetCurrentHealth() == 0)
	{
		std::cout << firstMonster->GetName() << " has won the battle!\n\n";
		curState = States::Conclusion;
	}
	else
		curState = States::Choose;
}

void BattleEngine::StateMachine::handleConclusion()
{
	curState = States::NoState;
}