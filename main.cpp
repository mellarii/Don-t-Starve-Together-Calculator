#include "boss.h"

#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <utility>

int main() {
    int choice_character = 3;
    int choice_weapon = 3;
    int choice_debuffs = 5;
    int choice_boss = 13;

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

    std::cout << " \nNow select Weapon:\n  1) HamBat (59.5 dmg)\n  2) RuinsBat (86.7)\n";
    std::cin >> choice_weapon;
    switch (choice_weapon)
    {
        case 1: Weapon.selectHamBat(); break;
        case 2: Weapon.selectRuinsBat(); break;
        default: Weapon.selectHand(); break;
    };

    std::cout << " \nNow select Debufs (at bosses):\n  1) Weakness (x1.25)\n  2) Moon Enemy Weakness (x1.10 and if character have buffs in his skill tree)\n  3) Shadow Enemy Weakness (x1.10 and if character have buffs in his skill tree)\n  4) None\n";
    std::cin >> choice_debuffs;
    switch (choice_debuffs)
    {
        case 1: Effects.applyWeakness(); break;
        case 2: Effects.moonEnemyWeakness(); break;
        case 3: Effects.shadowEnemyWeakness(); break;
        default: break;
    };

    std::cout << "\nNow select Boss:\n";
    std::cout << "1) Bee Quin          7)Bearger\n";
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
        default: selectedBoss = &Dummy; break;
    };

    float perHit = selectedBoss->dmg(Character, Effects, Weapon);
    if (choice_boss > 12) { std::cout << "Damage per hit: " << perHit << "\n"; 
    } else {
    std::cout << "\nSelected Boss: " << selectedBoss->name() << "\n";
    if (perHit <=0) {
        std::cout << "DMG is so low, you cant defeat any Boss.";
    } else {
        int hits = selectedBoss->hitsToKill(Character, Effects, Weapon);
        int needWeapons = selectedBoss->needWeapon(Character, Effects, Weapon);
        std::cout << "Damage per hit: " << perHit << "\n";
        std::cout << "Hits to kill boss: " << hits << "\n";
        std::cout << "Nedd weapon: " << needWeapons << "\n";
    }
    }

    return 0;
}

/*
int main() {
    // Characters
    Character volv;
    volv.selectVolvgang(); // x2.0

    Character vig;
    vig.selectVigfrid();  // x1.25

    // Effects
    EffectManager noEffect;
    EffectManager weakness;
    weakness.applyWeakness(); // x1.25

    // Weapons
    Weapon ruins;
    ruins.selectRuinsBat(); // dfltDmg = 86.7

    Weapon ham;
    ham.selectHamBat();     // dfltDmg = 59.5

    // Bosses
    MotherBee motherBee;
    ToadStoolDarck toad;
    AlterGuardian guardian;

    // Helper function for output
    auto test = [&](const Boss& boss, const Character& ch, const EffectManager& eff, const Weapon& w,
                    const std::string& bossName, const std::string& chName, const std::string& wName) {
        float per = boss.dmg(ch, eff, w);
        std::cout << "== " << bossName << " | " << chName << " | " << wName << " ==\n";
        std::cout << "Damage per hit: " << per << '\n';
        if (per <= 0.0f) {
            std::cout << "Cannot deal damage (per <= 0), hits-to-kill skipped.\n\n";
        } else {
            int hits = boss.hitsToKill(ch, eff, w);
            std::cout << "Hits to kill: " << hits << "\n";
        }

        float nUse = boss.needWeapon(ch,eff,w);
        std::cout << "Need: " << nUse << " " << wName << "\n";
    };

    // Example tests
    test(motherBee, volv, weakness, ruins,   "MotherBee", "Volvgang (x2.0)",   "Ruins Bat (86.7)");
    test(motherBee, vig,    noEffect, ruins, "MotherBee", "Vigfrid (x1.25)",   "Ruins Bat (86.7)");
    test(guardian,  volv,   weakness, ham,   "AlterGuardian", "Volvgang (x2.0)", "Ham Bat (59.5)");
    test(toad,      vig,    weakness, ruins, "ToadStoolDarck", "Vigfrid (x1.25)", "Ruins Bat (86.7)");

    return 0;
}
*/