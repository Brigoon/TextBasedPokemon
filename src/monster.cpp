#include <iostream>
#include <string>
#include "monster.h"

Monster::Monster(int health_in, int attack_in, int defense_in, int specialAttack_in, int specialDefense_in, int speed_in, std::string name_in) : name(name_in), experience(0), level(1), maxHealth(health_in), currentHealth(health_in), attack(attack_in), defense(defense_in), specialAttack(specialAttack_in), specialDefense(specialDefense_in), speed(speed_in)
{
}

void Monster::printStats()
{
	std::cout << "Level:           " << level << '\n';
	std::cout << "Health:          " << currentHealth << "/" << maxHealth << '\n';
	std::cout << "Attack:          " << attack << '\n';
	std::cout << "Defense:         " << defense << '\n';
	std::cout << "Special Attack:  " << specialAttack << '\n';
	std::cout << "Special Defense: " << specialDefense << '\n';
	std::cout << "Speed:           " << speed << '\n';
	std::cout << "Experience:      " << experience << "\n\n";
}

void Monster::printHealth()
{
	if (currentHealth > 0)
		std::cout << name << "'s health is now at " << currentHealth << "/" << maxHealth << "!\n\n";
	else
		std::cout << name << " has fainted!\n\n";
}

void Monster::heal(int heal)
{
	int amountHealed = heal;
	if (heal > maxHealth - currentHealth)
	{
		amountHealed = maxHealth - currentHealth;
		currentHealth = maxHealth;
	}
	else
		currentHealth += heal;

	std::cout << name << " healed by " << amountHealed << "!\n";
	printHealth();
}

void Monster::takeDamage(Monster* attacker)
{
	std::cout << attacker->getName() << " used " << attacker->getLastUsedMove().getName() << "!\n";
	Move lastUsed = attacker->getLastUsedMove();
	int damage = randomizer.adjustValue(&lastUsed);
	std::cout << "It did " << damage << " damage!\n";
	if (damage >= currentHealth)
		currentHealth = 0;
	else
		currentHealth -= damage;

	attacker->getLastUsedMove().setPP(getLastUsedMove().getPP() - 1);
	printHealth();
}

std::string Monster::getMovesString() {
	std::string output = "";
	for (int i = 0; i < 4; ++i) {
		std::string _name;
		if (moves[i].isValid()) {
			_name = moves[i].getName();
		}
		else {
			_name = "--";
		}
		int _moveNameLength = _name.length();
		int diff = MAX_SPACING - _moveNameLength;
		std::string spacings(diff, ' ');
		output = output + std::to_string(i+1) + ") " + _name + spacings;
		if (i == 1) {
			output += "\n";
		}
	}
	output += '\n';
	return output;
}
void Monster::printMoves()
{
	std::cout << getMovesString();
}