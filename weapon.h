#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon {
    private:
    float dfltDmg;
    float trueDmg;
    int maxUsage;
    public:
    void selectHand();
    void selectRuinsBat();
    void selectHamBat();

    float getDfltDamage() const;
    float getTrueDamage() const;
    int getMaxUsage() const;
};

#endif