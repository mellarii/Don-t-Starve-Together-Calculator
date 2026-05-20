#include "boss.h"

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <limits>
#include <string>

static void clear() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

static const char* charLabel(int c) {
    switch (c) {
        case 1: return "Wigfrid";
        case 2: return "Wolvgang";
        case 3: return "Wess";
        case 4: return "Wendy";
        default: return "Other";
    }
}

static const char* weaponLabel(int c) {
    switch (c) {
        case 1:  return "Ham Bat";
        case 2:  return "Ruins Bat";
        case 3:  return "Shadow Battle Axe";
        case 4:  return "Cloth Scyte";
        case 5:  return "Void Lunar Part";
        case 6:  return "Night Sword";
        case 7:  return "Glass Cutter";
        case 8:  return "Tentacle Spike";
        case 9:  return "Shield of Terror";
        case 10: return "Spear";
        case 11: return "Wigfrid's Spear";
        case 12: return "Rabbit King Spear";
        default: return "Hand";
    }
}

static const char* debuffLabel(int c) {
    switch (c) {
        case 1: return "Weakness (x1.25)";
        case 2: return "Moon Weakness (x1.10)";
        case 3: return "Shadow Weakness (x1.10)";
        default: return "None";
    }
}

static const char* bossLabel(int c) {
    switch (c) {
        case 1:  return "Bee Queen";
        case 2:  return "Toadstool";
        case 3:  return "Alter Guardian";
        case 4:  return "Klaus";
        case 5:  return "AntLion";
        case 6:  return "Wagboss";
        case 7:  return "Bearger";
        case 8:  return "Dragonfly";
        case 9:  return "Moose";
        case 10: return "Deerclops";
        case 11: return "Minotaur";
        case 12: return "Eye of Terror";
        case 13: return "Twins of Terror";
        default: return "Dummy";
    }
}

static void showStatus(int cc, int cw, int cd, int cb) {
    std::cout << "\n  Char: "    << (cc ? charLabel(cc)  : "-")
              << "  |  Weapon: " << (cw ? weaponLabel(cw) : "-")
              << "  |  Debuff: " << (cd ? debuffLabel(cd) : "-")
              << "  |  Boss: "   << (cb ? bossLabel(cb)   : "-")
              << "\n";
    for (int i = 0; i < 75; ++i) std::cout << '-';
    std::cout << '\n';
}

int main() {

    auto handleBadInput = []() {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    };

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

    bool keepRunning = true;

    while (keepRunning) {

    Character Character;
    Weapon Weapon;
    EffectManager Effects;
    Boss* selectedBoss = &Dummy;

    int choice_character = 0;
    int choice_weapon = 0;
    int choice_debuffs = 0;
    int choice_boss = 0;
    char continueChoice = ' ';

    // ---- Character ----
    clear();
    showStatus(choice_character, choice_weapon, choice_debuffs, choice_boss);
    std::cout << "Select character:\n"
              << "  1) Wigfrid  (x1.25)\n"
              << "  2) Wolvgang (x2.0)\n"
              << "  3) Wess     (x0.75)\n"
              << "  4) Wendy    (x0.75)\n"
              << "  5) Other    (x1.0)\n"
              << "> ";
    std::cin >> choice_character;
    handleBadInput();

    switch (choice_character)
    {
        case 1: Character.selectWigfrid(); break;
        case 2: Character.selectWolvgang(); break;
        case 3: Character.selectWess(); break;
        case 4: Character.selectWendy(); break;
        default: Character.selectOther(); break;
    };

    // ---- Weapon ----
    clear();
    showStatus(choice_character, choice_weapon, choice_debuffs, choice_boss);
    std::cout << "Select weapon:\n"
              << "  1) Ham Bat             7) Glass Cutter\n"
              << "  2) Ruins Bat           8) Tentacle Spike\n"
              << "  3) Shadow Battle Axe   9) Shield of Terror\n"
              << "  4) Cloth Scyte        10) Spear\n"
              << "  5) Void Lunar Part    11) Wigfrid's Spear\n"
              << "  6) Night Sword        12) Rabbit King Spear\n"
              << "  Other) Hand\n"
              << "> ";
    std::cin >> choice_weapon;
    handleBadInput();
    if (choice_weapon < 1 || choice_weapon > 12) choice_weapon = 13;

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

    // ---- Debuffs ----
    clear();
    showStatus(choice_character, choice_weapon, choice_debuffs, choice_boss);
    std::cout << "Select debuffs:\n"
              << "  1) Weakness (x1.25)\n"
              << "  2) Moon Enemy Weakness (x1.10)\n"
              << "  3) Shadow Enemy Weakness (x1.10)\n"
              << "  4) None\n"
              << "> ";
    std::cin >> choice_debuffs;
    handleBadInput();

    switch (choice_debuffs)
    {
        case 1: Effects.applyWeakness(); break;
        case 2: Effects.moonEnemyWeakness(); break;
        case 3: Effects.shadowEnemyWeakness(); break;
        default: break;
    };

    // ---- Boss ----
    clear();
    showStatus(choice_character, choice_weapon, choice_debuffs, choice_boss);
    std::cout << "Select boss:\n"
              << "  1) Bee Queen         8) Dragonfly\n"
              << "  2) Toadstool         9) Moose\n"
              << "  3) Alter Guardian   10) Deerclops\n"
              << "  4) Klaus            11) Minotaur\n"
              << "  5) AntLion          12) Eye of Terror\n"
              << "  6) Wagboss          13) Twins of Terror\n"
              << "  7) Bearger          Other) Dummy\n"
              << "> ";
    std::cin >> choice_boss;
    handleBadInput();

    switch (choice_boss)
    {
        case 1: selectedBoss = &motherBee; break;
        case 2: selectedBoss = &ToadStoolDarck; break;
        case 3: selectedBoss = &AlterGuardian; break;
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

    // ---- Result ----
    clear();
    showStatus(choice_character, choice_weapon, choice_debuffs, choice_boss);

    float perHit = selectedBoss->dmg(Character, Effects, Weapon);
    if (choice_boss < 1 || choice_boss > 13) {
        std::cout << "Damage per hit: " << perHit << "\n";
    } else {
        std::cout << "Damage per hit: " << perHit << "\n";
        if (perHit <= 0) {
            std::cout << "DMG is so low, you can't defeat any Boss.\n";
        } else {
            int hits = selectedBoss->hitsToKill(Character, Effects, Weapon);
            int needWeapons = selectedBoss->needWeapon(Character, Effects, Weapon);
            std::cout << "Hits to kill: " << hits << "\n";
            std::cout << "Need weapon: " << needWeapons << "\n";
        }
    }

    std::cout << "\nContinue? (Y/N) > ";
    std::cin >> continueChoice;
    handleBadInput();

    if (continueChoice != 'Y' && continueChoice != 'y') {
        keepRunning = false;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

    std::cout << "Press Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}
