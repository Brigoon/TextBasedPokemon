#pragma once

#include <string>
#include "rng.h"
#include "moves.h"

class Monster
{
public:
	Monster() {}
	Monster(int health_in, int attack_in, int defense_in, int specialAttack_in, int specialDefense_in, int speed_in, std::string name_in);
	~Monster() {}

	std::string getName() { return name; }

	int getExperience() { return experience; }

	int getLevel() { return level; }
	int getMaxHealth() { return maxHealth; }
	int getCurrentHealth() { return currentHealth; }
	int getAttack() { return attack; }
	int getDefense() { return defense; }
	int getSpecialAttack() { return specialAttack; }
	int getSpecialDefense() { return specialDefense; }
	int getSpeed() { return speed; }
	Move getLastUsedMove() { return lastUsedMove; }

	void setName(std::string in) { name = in; }

	void printStats();
	void printHealth();
	void heal(int);
	void takeDamage(Monster *);

	void setMove(Move m, int idx) { moves[idx] = m; }
	void setLastUsedMove(Move m) { lastUsedMove = m; }

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
	Move moves[4];
	Random randomizer;
	Move lastUsedMove = moves[0];
};