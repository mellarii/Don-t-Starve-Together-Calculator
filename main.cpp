#include <iostream>
#include <cmath>
#include <limits>
#include <string>

class Boss {
    protected:
    float health;
    int trueDefence;
    int defence;

    public:
    Boss(float h, int d, int td) : health(h), defence(d ? 1 : 0), trueDefence(td) {}
    virtual ~Boss() = default;
    float dmg(const Character& attacer, const EffectManager& currentEffects, const Weapon& currentWeapon) const {
        /*
        float charDmgBonus = attacer.getCharacterDmgBonus();
        float EffectMultiplier = currentEffects.getMultiplier();
        float dfltDmg = currentWeapon.getDfltDamage();
        float trueDmg = currentWeapon.getTrueDamage();
        */

        float hitDmg = 0.0f;
        if (defence > 0) {
            hitDmg = (std::sqrt((dfltDmg * charDmgBonus * EffectMultiplier) * 4.0f + 64.0f) - 8.0f) * 4.0f + trueDmg - trueDefence;
        } else {
            hitDmg = (dfltDmg * charDmgBonus * EffectMultiplier) + trueDmg - trueDefence;
        }

        return hitDmg;
    }
}