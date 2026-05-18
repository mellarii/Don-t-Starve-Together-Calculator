#include "weapon.h"

#include <iostream>
#include <cmath>
#include <limits>
#include <utility>

constexpr int INFINITE_USAGE = std::numeric_limits<int>::max();

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

void Weapon::selectShadowBattleAxe() {
    dfltDmg = 41.8f;
    trueDmg = 51.0f;
    maxUsage = 200;
};

void Weapon::selectClothScyte() {
    dfltDmg = 41.8f;
    trueDmg = 47.0f;
    maxUsage = 200;
};

void Weapon::selectVoidLunarPart() {
    dfltDmg = 45.9f;
    trueDmg = 38.0f;
    maxUsage = 200;
};

void Weapon::selectnightSword() {
    dfltDmg = 68.0f;
    trueDmg = 0.0f;
    maxUsage = 100;
};

void Weapon::selectGlasscutter() {
    dfltDmg = 68.0f;
    trueDmg = 0.0f;
    maxUsage = 75;
};

void Weapon::selectTentaclespike() {
    dfltDmg = 51.0f;
    trueDmg = 0.0f;
    maxUsage = 100;
};

void Weapon::selectSpearWathgrithr() {
    dfltDmg = 42.5f;
    trueDmg = 0.0f;
    maxUsage = 200;
};

void Weapon::selectSpear() {
    dfltDmg = 34.0f;
    trueDmg = 0.0f;
    maxUsage = 150;
};

void Weapon::selectshieldOfTerror() {
    dfltDmg = 51.0f;
    trueDmg = 0.0f;
    maxUsage = 315;
};

void Weapon::selectRabbitKingSpear() {
    dfltDmg = 51.0f;
    trueDmg = 0.0f;
    maxUsage = 125;
};

float Weapon::getDfltDamage() const { return dfltDmg; };
float Weapon::getTrueDamage() const { return trueDmg; };
int Weapon::getMaxUsage() const { return maxUsage; };