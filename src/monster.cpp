#include <iostream>
#include <string>
#include "monster.h"

Monster::Monster(int health_in, int attack_in, int defense_in, int specialAttack_in, int specialDefense_in, int speed_in, std::string name_in) : name(name_in), experience(0), level(1), maxHealth(health_in), currentHealth(health_in), attack(attack_in), defense(defense_in), specialAttack(specialAttack_in), specialDefense(specialDefense_in), speed(speed_in)
{
}

std::string Monster::getStatsString()
{
	std::string stats;
	stats += "Level:           " + std::to_string(level) + "\n";
	stats += "Health:          " + std::to_string(currentHealth) + "/" + std::to_string(maxHealth) + "\n";
	stats += "Attack:          " + std::to_string(attack) + "\n";
	stats += "Defense:         " + std::to_string(defense) + "\n";
	stats += "Special Attack:  " + std::to_string(specialAttack) + "\n";
	stats += "Special Defense: " + std::to_string(specialDefense) + "\n";
	stats += "Speed:           " + std::to_string(speed) + "\n";
	stats += "Experience:      " + std::to_string(experience) + "\n";
	return stats;
}
void Monster::printStats()
{
	std::cout << getStatsString();
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

void Monster::takeDamage(float damage)
{
	std::cout << "It did " << damage << " damage!\n";
	if (damage >= currentHealth)
		currentHealth = 0;
	else
		currentHealth -= damage;
	printHealth();
}

std::string Monster::getMovesString() {
	std::string output = "";
	for (int i = 0; i < 4; ++i) {
		std::string _name;
		if (moves[i].isValid()) {
			_name = moves[i].getName();
			_name += " (PP = " + std::to_string(moves[i].getPP()) + ")";
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
		//std::cout << _name;
	}
	output += '\n';
	return output;
}
void Monster::printMoves()
{
	std::cout << getMovesString();
}