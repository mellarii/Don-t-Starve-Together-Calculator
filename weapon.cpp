#include "weapon.h"

#include <iostream>
#include <cmath>
#include <limits>
#include <utility>

constexpr int INFINITE_USAGE = std::numeric_limits<int>::max();

float dfltDmg = 10.0f;
float trueDmg = 0.0f;
int maxUsage = INFINITE_USAGE;

void Weapon::selectHand() {
    dfltDmg = 10.0f;
    trueDmg = 0.0f;
    maxUsage = 1000000000;
};
void Weapon::selectRuinsBat() {
    dfltDmg = 86.7f;
    trueDmg = 0.0f;
    maxUsage = 200;
};
void Weapon::selectHamBat() {
    dfltDmg = 59.5f;
    trueDmg = 0.0f;
    maxUsage = INFINITE_USAGE;
};

float Weapon::getDfltDamage() const { return dfltDmg; };
float Weapon::getTrueDamage() const { return trueDmg; };
int Weapon::getMaxUsage() const { return maxUsage; };