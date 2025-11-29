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