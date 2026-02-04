#include <iostream>
#include <string>
#include "statuses.h"

class Monster;

void Statuses::BaseStatus::handleEffect(bool initialApply) {
    if (initialApply) { std::cout << initialMsg; }
    else {std::cout << recurringMsg; }
}
void Statuses::Sleep::handleEffect(Monster* monster, bool initialApply) {
    BaseStatus::handleEffect(initialApply);
}