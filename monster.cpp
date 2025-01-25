#include "monster.h"

using namespace std;

Monster::Monster(uint8 h_in, uint8 a_in, uint8 d_in, uint8 sa_in, uint8 sd_in, uint8 s_in, string n_in) :
	name(n_in), experience(0), level(1), maxHealth(h_in), currentHealth(h_in), attack(a_in), defense(d_in), specialAttack(sa_in), specialDefense(sd_in), speed(s_in) {}

void Monster::PrintStats()
{
	cout << "Level:           " << +level << '\n';
	cout << "Health:          "  << +currentHealth << "/" << +maxHealth << '\n';
	cout << "Attack:          " << +attack << '\n';
	cout << "Defense:         " << +defense << '\n';
	cout << "Special Attack:  " << +specialAttack << '\n';
	cout << "Special Defense: " << +specialDefense << '\n';
	cout << "Speed:           " << +speed << '\n';
	cout << "Experience:      " << experience << "\n\n";
}

void Monster::PrintHealth()
{
	if (currentHealth > 0)
		cout << name << "'s health is now at " << +currentHealth << "/" << +maxHealth << "!\n\n";
	else
		cout << name << " has fainted!\n\n";
}

void Monster::Heal(uint8 heal)
{
	uint8 amountHealed = heal;
	if (heal > maxHealth - currentHealth)
	{
		amountHealed = maxHealth - currentHealth;
		currentHealth = maxHealth;
	}
	else
		currentHealth += heal;

	PrintHealth();
}

void Monster::TakeDamage(Monster* attacker)
{
	cout << attacker->GetName() << " used " << attacker->move.name << "!\n";
	if (attacker->move.damage >= currentHealth)
		currentHealth = 0;
	else
		currentHealth -= attacker->move.damage;

	PrintHealth();
}