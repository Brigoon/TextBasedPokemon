#pragma once

#include "monster.h"
#include "rng.h"

namespace BattleEngine
{
	enum class States
	{
		NoState,
		Intro,
		Choose,
		Battle,
		Conclusion
	}; // States

	class StateMachine
	{
	public:
		StateMachine() : curState(States::NoState), firstMonster(nullptr), secondMonster(nullptr) {}
		~StateMachine() {}

		void commenceBattle(Monster *, Monster *);

	private:
		States curState;
		Monster *firstMonster;
		Monster *secondMonster;
		Random randomizer;

		void handleIntro();
		void handleChoose();
		void handleBattle();
		void handleConclusion();
		bool checkForFlinch(Monster *, Monster *);
		void handleAttackSequence(Monster *, Monster *);
	}; // StateMachine
} // BattleEngine