#include <iostream>
#include "monster.h"

Monster::Monster(int health_in, int attack_in, int defense_in, int specialAttack_in, int specialDefense_in, int speed_in, std::string name_in) : name(name_in), experience(0), level(1), maxHealth(health_in), currentHealth(health_in), attack(attack_in), defense(defense_in), specialAttack(specialAttack_in), specialDefense(specialDefense_in), speed(speed_in)
{
}

void Monster::PrintStats()
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

void Monster::PrintHealth()
{
	if (currentHealth > 0)
		std::cout << name << "'s health is now at " << currentHealth << "/" << maxHealth << "!\n\n";
	else
		std::cout << name << " has fainted!\n\n";
}

void Monster::Heal(int heal)
{
	int amountHealed = heal;
	if (heal > maxHealth - currentHealth)
	{
		amountHealed = maxHealth - currentHealth;
		currentHealth = maxHealth;
	}
	else
		currentHealth += heal;

	PrintHealth();
}

void Monster::TakeDamage(Monster *attacker) void Monster::TakeDamage(Monster *attacker)
{
	std::cout << attacker->GetName() << " used " << attacker->move.name << "!\n";
	int damage = randomizer.AdjustDamage(attacker->move.damage);
	std::cout << "It did " << damage << " damage!\n";
	if (damage >= currentHealth)
		currentHealth = 0;
	else
		currentHealth -= damage;

	PrintHealth();
}