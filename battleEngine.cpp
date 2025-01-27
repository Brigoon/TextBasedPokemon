#include <iostream>
#include "battleEngine.h"
#include "rng.h"

Random randomizing;

void BattleEngine::StateMachine::commenceBattle(Monster *a, Monster *b)
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
		// randomizer for first attack
		if (randomizing.BinaryEvent(0.5F))
		{
			secondMonster->TakeDamage(firstMonster);
			handleAttackSequence(secondMonster, firstMonster);
		}
		else
		{
			firstMonster->TakeDamage(secondMonster);
			handleAttackSequence(firstMonster, secondMonster);
		}
	}
	else if (firstMonster->GetSpeed() > secondMonster->GetSpeed())
	{
		secondMonster->TakeDamage(firstMonster);
		handleAttackSequence(secondMonster, firstMonster);
	}
	else
	{
		firstMonster->TakeDamage(secondMonster);
		handleAttackSequence(firstMonster, secondMonster);
	}

	if (curState != States::Conclusion)
	{
		curState = States::Choose;
	}
}

void BattleEngine::StateMachine::handleConclusion()
{
	curState = States::NoState;
}

void BattleEngine::StateMachine::handleAttackSequence(Monster *defender, Monster *attacker)
{
	if (defender->GetCurrentHealth() == 0)
	{
		std::cout << attacker->GetName() << " has won the battle!\n\n";
		curState = States::Conclusion;
	}
	else
	{
		// defender survived, roles are flipped now
		// first, check for flinch
		// if (randomizing.BinaryEvent(attacker->GetLastMove().GetFlinchProbability()))
		if (randomizing.BinaryEvent(0.5F))
		{
			std::cout << defender->GetName() << " flinched!\n\n";
			return;
		}
		// otherwise, flip roles and apply new damage, then continue sequence
		attacker->TakeDamage(defender);
		// recursive works with only 1 move, but wont once we have n > 1 moves to choose from
		handleAttackSequence(attacker, defender);
	}
}