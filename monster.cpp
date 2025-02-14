#include <iostream>
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

	printHealth();
}

void Monster::takeDamage(Monster *attacker)
{
	std::cout << attacker->getName() << " used " << attacker->move->GetName() << "!\n";
	int damage = randomizer.AdjustDamage(attacker->move->GetDamage());
	std::cout << "It did " << damage << " damage!\n";
	if (damage >= currentHealth)
		currentHealth = 0;
	else
		currentHealth -= damage;

	printHealth();
}