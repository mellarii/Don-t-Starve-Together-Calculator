#include "effects.h"

#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <utility>

void EffectManager::applyWeakness() { 
    totalEffectMultiplier *= 1.25f; 
}
void EffectManager::moonEnemyWeakness() {
    totalEffectMultiplier *= 1.10f;
}
void EffectManager::shadowEnemyWeakness() {
    totalEffectMultiplier *= 1.10f;
}
void EffectManager::applyBurn() {
    totalEffectMultiplier *= 1.25f;
}


float EffectManager::getMultiplier() const { return totalEffectMultiplier; };