#include <iostream>
#include "monster.h"
#include "rng.h"

using namespace std;

Monster::Monster(int health_in, int attack_in, int defense_in, int specialAttack_in, int specialDefense_in, int speed_in, string name_in) : name(name_in), experience(0), level(1), maxHealth(health_in), currentHealth(health_in), attack(attack_in), defense(defense_in), specialAttack(specialAttack_in), specialDefense(specialDefense_in), speed(speed_in)
{
}
Random randomizer;

void Monster::PrintStats()
{
	cout << "Level:           " << level << '\n';
	cout << "Health:          " << currentHealth << "/" << maxHealth << '\n';
	cout << "Attack:          " << attack << '\n';
	cout << "Defense:         " << defense << '\n';
	cout << "Special Attack:  " << specialAttack << '\n';
	cout << "Special Defense: " << specialDefense << '\n';
	cout << "Speed:           " << speed << '\n';
	cout << "Experience:      " << experience << "\n\n";
}

void Monster::PrintHealth()
{
	if (currentHealth > 0)
		cout << name << "'s health is now at " << currentHealth << "/" << maxHealth << "!\n\n";
	else
		cout << name << " has fainted!\n\n";
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

void Monster::TakeDamage(Monster *attacker)
{
	cout << attacker->GetName() << " used " << attacker->move.name << "!\n";
	int damage = randomizer.adjustDamage(attacker->move.damage);
	cout << "It did " << damage << " damage!\n";
	if (damage >= currentHealth)
		currentHealth = 0;
	else
		currentHealth -= damage;

	PrintHealth();
}