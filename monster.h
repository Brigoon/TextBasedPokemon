#pragma once

#include "helper.h"

class Move
{
public:
	Move() : name("---"), damage(0), accuracy(0) {}

	std::string name;
	uint8 damage;
	uint8 accuracy;
};

class Monster {
public:
	Monster() {}
	Monster(uint8, uint8, uint8, uint8, uint8, uint8, std::string);
	~Monster() {}

	std::string GetName() { return name; }

	uint32 GetExperience() { return experience; }

	uint8 GetLevel() { return level; }
	uint8 GetMaxHealth() { return maxHealth; }
	uint8 GetCurrentHealth() { return currentHealth; }
	uint8 GetAttack() { return attack; }
	uint8 GetDefense() { return defense; }
	uint8 GetSpecialAttack() { return specialAttack; }
	uint8 GetSpecialDefense() { return specialDefense; }
	uint8 GetSpeed() { return speed; }

	void SetName(std::string in) { name = in; }

	void PrintStats();
	void PrintHealth();
	void Heal(uint8);
	void TakeDamage(Monster*);

	Move move;

private:
	std::string name = "missingno";

	uint32 experience = 0;

	uint8 level = 1;
	uint8 maxHealth = 1;
	uint8 currentHealth = 1;
	uint8 attack = 1;
	uint8 defense = 1;
	uint8 specialAttack = 1;
	uint8 specialDefense = 1;
	uint8 speed = 1;
};