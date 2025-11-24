#ifndef EFFECTS_H
#define EFFECTS_H

#include <iostream>

class EffectManager {
    private:
    float totalEffectMultiplier = 1.0f;
    public:
    void applyWeakness();
    void moonEnemyWeakness();
    void shadowEnemyWeakness();

    float getMultiplier() const;
};

#endif