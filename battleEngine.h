#pragma once

#include "monster.h"

namespace BattleEngine
{
	enum class States
	{
		NoState,
		Intro,
		Choose,
		Battle,
		Conclusion
	}; //States

	class StateMachine
	{
	public:
		StateMachine() : curState(States::NoState), firstMonster(nullptr), secondMonster(nullptr) {}
		~StateMachine() {}

		void commenceBattle(Monster*, Monster*);

	private:
		States curState;
		Monster* firstMonster;
		Monster* secondMonster;

		void handleIntro();
		void handleChoose();
		void handleBattle();
		void handleConclusion();
	}; //StateMachine
} //BattleEngine