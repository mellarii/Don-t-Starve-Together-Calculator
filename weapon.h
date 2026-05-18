#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon {
    private:
    float dfltDmg = 10.0f;
    float trueDmg = 0.0f;
    int maxUsage = 1000000000;
    public:
    void selectHand();
    void selectRuinsBat();
    void selectHamBat();
    void selectShadowBattleAxe();
    void selectClothScyte();
    void selectVoidLunarPart();
    void selectnightSword();
    void selectGlasscutter();
    void selectTentaclespike();
    void selectSpearWathgrithr();
    void selectSpear();
    void selectshieldOfTerror();
    void selectRabbitKingSpear();

    float getDfltDamage() const;
    float getTrueDamage() const;
    int getMaxUsage() const;
};

#endif