#pragma once

#include <string>
#include "rng.h"
#include "moves.h"

class Monster
{
public:
	Monster() {}
	Monster(int health_in, int attack_in, int defense_in, int specialAttack_in, int specialDefense_in, int speed_in, std::string name_in);
	~Monster() {delete move;}

	std::string GetName() { return name; }

	int GetExperience() { return experience; }

	int GetLevel() { return level; }
	int GetMaxHealth() { return maxHealth; }
	int GetCurrentHealth() { return currentHealth; }
	int GetAttack() { return attack; }
	int GetDefense() { return defense; }
	int GetSpecialAttack() { return specialAttack; }
	int GetSpecialDefense() { return specialDefense; }
	int GetSpeed() { return speed; }

	void SetName(std::string in) { name = in; }

	void PrintStats();
	void PrintHealth();
	void Heal(int);
	void TakeDamage(Monster *);

	void SetMove(Move* m) { move = m; }
	Move* GetMove()  {return move; }

private:
	std::string name = "missingno";

	int experience = 0;

	int level = 1;
	int maxHealth = 1;
	int currentHealth = 1;
	int attack = 1;
	int defense = 1;
	int specialAttack = 1;
	int specialDefense = 1;
	int speed = 1;
	Move* move = nullptr;

	Random randomizer;
};