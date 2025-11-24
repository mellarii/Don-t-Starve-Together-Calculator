#include "effects.h"

#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <utility>

float totalEffectMultiplier = 1.0f;

void EffectManager::applyWeakness() { 
    totalEffectMultiplier *= 1.25f; 
}
void EffectManager::moonEnemyWeakness() {
    totalEffectMultiplier *= 1.10f;
}
void EffectManager::shadowEnemyWeakness() {
    totalEffectMultiplier *= 1.10f;
}

float EffectManager::getMultiplier() const { return totalEffectMultiplier; };