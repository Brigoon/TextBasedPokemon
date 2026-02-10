#include <iostream>
#include <string>
#include "battleEngine.h"
#include "statuses.h"

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
			Move* move = monster->getMove(idx);
			if (!move->isValid()) {
				std::cout << badMove << '\n';
			}
			else if (move->getPP() == 0) {
				std::cout << move->getName() << noPP << '\n';
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

	handleAttack(defender, attacker);
	if (!defender->isFainted()) {
		handleAttack(attacker, defender);
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
	Move reset = Move();
	firstMonster->setLastUsedMove(&reset);
	secondMonster->setLastUsedMove(&reset);
	curState = States::NoState;
}

void BattleEngine::StateMachine::handleAttack(Monster* defender, Monster* attacker)
{
	//see if status prevents attack
	if (!attacker->getStatus()->willAttack()) {
		attacker->getStatus()->handleEffect(attacker, false, true);
		return;
	}

	// otherwise, get chosen move and apply RNG & other adjustments
	Move* lastUsed = attacker->getLastUsedMove();
	std::cout << attacker->getName() << " used " << lastUsed->getName() << "!\n";
	lastUsed->setPP(lastUsed->getPP() - 1);
	int accuracy = lastUsed->getAccuracy();

	if (!randomizer.binaryEvent(accuracy)) {
		std::cout << "But it missed!" << std::endl;
		//apply any existing status effects
		if (attacker->getStatus() != &Statuses::None) {
			attacker->getStatus()->handleEffect(attacker, false, true);
		}
		return;
	}

	float damage = randomizer.adjustValue(lastUsed);
	defender->takeDamage(damage);

	// see if attack applied a status to the monster
	const Statuses::BaseStatus* status = lastUsed->getStatus();
	if ((status != &Statuses::None) && (status != &Statuses::Flinched)) {
		int prob = lastUsed->getSecondaryEffectProbability();
		if ((prob != 0) && (randomizer.binaryEvent(prob))) {
			bool hasStatus = defender->getStatus() == status;
			defender->setStatus(status);
			status->handleEffect(defender, true, hasStatus);
		}
	}

	// flinch check
	if (status == &Statuses::Flinched) {
		int prob = lastUsed->getSecondaryEffectProbability();
		if ((prob != 0) && (randomizer.binaryEvent(prob))) {
			status->handleEffect(defender, true, false);
		}
	}
}	