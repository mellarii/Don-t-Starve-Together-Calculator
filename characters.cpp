#include "characters.h"

Character::Character() : totalCharDmgBonus(1.0f) {}

void Character::selectOther() {
    totalCharDmgBonus = 1.0f;
}

void Character::selectWess() {
    totalCharDmgBonus = 0.75f;
}

void Character::selectWolvgang() {
    totalCharDmgBonus = 2.0f;
}

void Character::selectWigfrid() {
    totalCharDmgBonus = 1.25f;
}

float Character::getCharacterDmgBonus() const { return totalCharDmgBonus; }