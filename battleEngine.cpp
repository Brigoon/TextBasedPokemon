#include <iostream>
#include <string>
#include "battleEngine.h"

void BattleEngine::StateMachine::commenceBattle(Monster* a, Monster* b)
{
	firstMonster = a;
	secondMonster = b;

	if (firstMonster->getCurrentHealth() == 0)
	{
		std::cout << firstMonster->getName() << " has no health and cannot battle!\n";
		curState = States::NoState;
	}
	else if (secondMonster->getCurrentHealth() == 0)
	{
		std::cout << secondMonster->getName() << " has no health and cannot battle!\n";
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
	std::cout << firstMonster->getName() << " was sent out!\n";
	std::cout << secondMonster->getName() << " was sent out!\n\n";

	// abilities, items, weather, etc can occur here

	curState = States::Choose;
}

void BattleEngine::StateMachine::handleChoose()
{
	// would need to check for abilities, items, weather, etc here
	int firstMonsterIdx = chooseMove(firstMonster);
	int secondMonsterIdx = chooseMove(secondMonster);
	
	firstMonster->setLastUsedMove(firstMonster->getMove(firstMonsterIdx));
	secondMonster->setLastUsedMove(secondMonster->getMove(secondMonsterIdx));

	curState = States::Battle;
}

int BattleEngine::StateMachine::chooseMove(Monster* monster)
{
	int idx;
	std::string nonIntOrOOB = "Invalid input. Please enter a number between 1 and 4, inclusive.";
	std::string badMove = "Invalid move selected. Please choose a number with a move that is not '--'.";
	std::string noPP = " has no PP left! Please choose another move.";
	std::cout << monster->getName() << ", choose a move to use: " << '\n';
	monster->printMoves();
	while (true) {
		std::cin >> idx;
		if (std::cin.fail()) {
			std::cout << nonIntOrOOB << '\n';
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
		}
		else if ((idx < 1) || (idx > 4)) {
			std::cout << nonIntOrOOB << '\n';
		}
		else {
			idx -= 1; // account for 0-based indexing vs human readability
			Move _move = monster->getMove(idx);
			if (!_move.isValid()) {
				std::cout << badMove << '\n';
			}
			else if (_move.getPP() == 0) {
				std::cout << _move.getName() << noPP << '\n';
			}
			else {return idx;}
		}
	}
}

void BattleEngine::StateMachine::handleBattle()
{
	Monster* attacker;
	Monster* defender;
 	// speed check and then apply damage
	const int speedDifference = firstMonster->getSpeed() - secondMonster->getSpeed();
	if (speedDifference > 0) {
		attacker = firstMonster;
		defender = secondMonster;
	}
	else if (speedDifference < 0) {
		attacker = secondMonster;
		defender = firstMonster;
	}
	else
	{
		// randomizer for first attack
		if (randomizer.binaryEvent(0.5F))
		{
			attacker = firstMonster;
			defender = secondMonster;
		}
		else
		{
			attacker = secondMonster;
			defender = firstMonster;
		}
	}

	defender->takeDamage(attacker);
	if ((!defender->isFainted()) && (!checkForFlinch(defender, attacker)))
	{
		attacker->takeDamage(defender);
	}

	if (defender->isFainted())
	{
		std::cout << attacker->getName() << " has won the battle!\n\n";
		curState = States::Conclusion;
	}
	else if (attacker->isFainted())
	{
		std::cout << defender->getName() << " has won the battle!\n\n";
		curState = States::Conclusion;
	}
	else
	{
		curState = States::Choose;
	}
}

void BattleEngine::StateMachine::handleConclusion()
{
	curState = States::NoState;
}

bool BattleEngine::StateMachine::checkForFlinch(Monster* defender, Monster* attacker)
{
	bool flinched = false;
	// if (randomizing.BinaryEvent(attacker->GetLastMove().GetFlinchProbability()))
	if (randomizer.binaryEvent(0.5F))
	{
		std::cout << defender->getName() << " flinched!\n\n";
		flinched = true;
	}
	return flinched;
}
