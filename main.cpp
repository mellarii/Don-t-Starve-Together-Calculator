#include "boss.h"

#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <utility>

int main() {
    int choice_character = 3;
    int choice_weapon = 13;
    int choice_debuffs = 5;
    int choice_boss = 14;

    Character Character;
    Weapon Weapon;
    EffectManager Effects;
    ToadStoolDarck toad;
    AlterGuardian guardian;

    Dummy Dummy;
    MotherBee motherBee;
    ToadStoolDarck ToadStoolDarck;
    Klaus Klaus;
    AlterGuardian AlterGuardian;
    WagbossRobotPosessed WagbossRobotPosessed;
    AntLion AntLion;
    Bearger Bearger;
    Dragonfly Dragonfly;
    Moose Moose;
    Deerclops Deerclops;
    Minotaur Minotaur;
    Eyeofterror Eyeofterror;
    TwinsOfTerror TwinsOfTerror;
    Boss* selectedBoss = &Dummy;

    std::cout << "Select the terms for calculation: \n First - Character:\n  1) Wigfrid (x1.25)\n  2) Wolvgan (x2.0 in stongest form)\n  3) Wess (x0.75)\n  4) Other characters (deafoult dmg)\n";
    std::cin >> choice_character;
    switch (choice_character)
    {
        case 1: Character.selectWigfrid(); break;
        case 2: Character.selectWolvgang(); break;
        case 3: Character.selectWess(); break;
        default: Character.selectOther(); break;
    };

    std::cout << "\nNow select weapon:\n";
    std::cout << "1) Ham Bat           7) Class Scutter\n";
    std::cout << "2) Ruins Bat         8) Tentacle Spike\n";
    std::cout << "3) Shadow Battle Axe 9) Shield of Terror\n";
    std::cout << "4) Cloth Scyte      10) Spear\n";
    std::cout << "5) Void Lunar Part  11) Wigfrid's spear\n";
    std::cout << "6) Night Sword      12) Rabbit King Spear\n";
    std::cin >> choice_weapon;
    switch (choice_weapon)
    {
        case 1: Weapon.selectHamBat(); break;
        case 2: Weapon.selectRuinsBat(); break;
        case 3: Weapon.selectShadowBattleAxe(); break;
        case 4: Weapon.selectClothScyte(); break;
        case 5: Weapon.selectVoidLunarPart(); break;
        case 6: Weapon.selectnightSword(); break;
        case 7: Weapon.selectGlasscutter(); break;
        case 8: Weapon.selectTentaclespike(); break;
        case 9: Weapon.selectshieldOfTerror(); break;
        case 10: Weapon.selectSpear(); break;
        case 11: Weapon.selectSpearWathgrithr(); break;
        case 12: Weapon.selectRabbitKingSpear(); break;
        default: Weapon.selectHand(); break;
    };

    std::cout << "\nNow select Debufs (at bosses):\n  1) Weakness (x1.25)\n  2) Moon Enemy Weakness (x1.10 and if character have buffs in his skill tree)\n  3) Shadow Enemy Weakness (x1.10 and if character have buffs in his skill tree)\n  4) None\n";
    std::cin >> choice_debuffs;
    switch (choice_debuffs)
    {
        case 1: Effects.applyWeakness(); break;
        case 2: Effects.moonEnemyWeakness(); break;
        case 3: Effects.shadowEnemyWeakness(); break;
        default: break;
    };

    std::cout << "\nNow select Boss:\n";
    std::cout << "1) Bee Quin          7)Bearger       13)TwinsOfTerror\n";
    std::cout << "2) Toad              8)Dragonfly\n";
    std::cout << "3) Alter Guardian    9)Moose\n";
    std::cout << "4) Klaus            10)Deerclops\n";
    std::cout << "5) AntLion          11)Minotaur\n";
    std::cout << "6) WagBoss Possesed 12) Eye of Terror\n";
    std::cin >> choice_boss;
    switch (choice_boss)
    {
        case 1: selectedBoss = &motherBee; break;
        case 2: selectedBoss = &toad; break;
        case 3: selectedBoss = &guardian; break;
        case 4: selectedBoss = &Klaus; break;
        case 5: selectedBoss = &AntLion; break;
        case 6: selectedBoss = &WagbossRobotPosessed; break;
        case 7: selectedBoss = &Bearger; break; 
        case 8: selectedBoss = &Dragonfly; break;
        case 9: selectedBoss = &Moose; break;
        case 10: selectedBoss = &Deerclops; break;
        case 11: selectedBoss = &Minotaur; break;
        case 12: selectedBoss = &Eyeofterror; break;
        case 13: selectedBoss = &TwinsOfTerror; break;
        default: selectedBoss = &Dummy; break;
    };

    float perHit = selectedBoss->dmg(Character, Effects, Weapon);
    if (choice_boss > 13) { std::cout << "Damage per hit: " << perHit << "\n"; 
    } else {
    std::cout << "\nSelected Boss: " << selectedBoss->name() << "\n";
    if (perHit <=0) {
        std::cout << "DMG is so low, you cant defeat any Boss.";
    } else {
        int hits = selectedBoss->hitsToKill(Character, Effects, Weapon);
        int needWeapons = selectedBoss->needWeapon(Character, Effects, Weapon);
        std::cout << "Damage per hit: " << perHit << "\n";
        std::cout << "Hits to kill boss: " << hits << "\n";
        std::cout << "Nedd weapon: " << needWeapons << "\n" << std::endl;
    }
    }

    return 0;
}