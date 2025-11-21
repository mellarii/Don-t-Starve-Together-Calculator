#include <iostream>
#include <cmath>
#include <limits>
#include <string>

constexpr float INFINITE_HITPOINTS = std::numeric_limits<float>::max();
constexpr int INFINITE_USAGE = std::numeric_limits<int>::max();

class EffectManager {
    private:
    float totalEffectMultiplier = 1.0f;
    public:
    void applyWeakness() { 
        totalEffectMultiplier *= 1.25f; 
    }

    float getMultiplier() const { return totalEffectMultiplier; };
};

class Character {
    private:
    float totalCharDmgBonus = 1.0f;
    public:
    void selectOther() {
        totalCharDmgBonus = 1.0f;
    };
    void selectWess() {
        totalCharDmgBonus = 0.75f;
    };
    void selectWolvgang() {
        totalCharDmgBonus = 2.0f;
    };
    void selectWigfrid() {
        totalCharDmgBonus = 1.25f;
    };

    float getCharacterDmgBonus() const { return totalCharDmgBonus; };
};

class Weapon {
    private:
    float dfltDmg = 10.0f;
    float trueDmg = 0.0f;
    int maxUsage = INFINITE_USAGE;
    public:
    void selectHand() {
        dfltDmg = 10.0f;
        trueDmg = 0.0f;
        maxUsage = 1000000000;
    };
    void selectRuinsBat() {
        dfltDmg = 86.7f;
        trueDmg = 0.0f;
        maxUsage = 200;
    };
    void selectHamBat() {
        dfltDmg = 59.5f;
        trueDmg = 0.0f;
        maxUsage = INFINITE_USAGE;
    };

    float getDfltDamage() const { return dfltDmg; };
    float getTrueDamage() const { return trueDmg; };
    int getMaxUsage() const { return maxUsage; };
};

class Boss {
    protected:
    float health;
    int trueDefence;
    int defence;

    public:
    Boss(float h, int d, int td) : health(h), defence(d ? 1 : 0), trueDefence(td) {}
    virtual ~Boss() = default;
    float dmg(const Character& attacer, const EffectManager& currentEffects, const Weapon& currentWeapon) const {
        float charDmgBonus = attacer.getCharacterDmgBonus();
        float EffectMultiplier = currentEffects.getMultiplier();
        float dfltDmg = currentWeapon.getDfltDamage();
        float trueDmg = currentWeapon.getTrueDamage();

        float hitDmg = 0.0f;
        if (defence > 0) {
            hitDmg = (std::sqrt((dfltDmg * charDmgBonus * EffectMultiplier) * 4.0f + 64.0f) - 8.0f) * 4.0f + trueDmg - trueDefence;
        } else {
            hitDmg = (dfltDmg * charDmgBonus * EffectMultiplier) + trueDmg - trueDefence;
        }

        return hitDmg;
    }

    int hitsToKill(const Character& attacer, const EffectManager& currentEffects, const Weapon& currentWeapon) const {
        float per = dmg(attacer, currentEffects, currentWeapon);

        return static_cast<int>(std::ceil(health/per));
    }

    int needWeapon(const Character& attacer, const EffectManager& currentEffects, const Weapon& currentWeapon) const {
        float fuck = hitsToKill(attacer, currentEffects, currentWeapon);
        int usage = currentWeapon.getMaxUsage();
        
        return static_cast<int>(std::ceil(fuck/usage));
    }

    virtual std::string name() const = 0;
};

class Dummy : public Boss {
    public:
    Dummy() : Boss(INFINITE_HITPOINTS, 0, 0) {}
    std::string name() const override {
        return "Dummy";
    }
};

class MotherBee : public Boss {
    public:
    MotherBee() : Boss(22500.0f, 0, 0) {}
    std::string name() const override {
        return "Bee Quin";
    }
};

class ToadStoolDarck : public Boss {
    public:
    ToadStoolDarck() : Boss(99999.0f, 0, 0) {}
    std::string name() const override {
        return "Toad";
    }
};

class AlterGuardian : public Boss {
    public:
    AlterGuardian() : Boss((10000.0f + 18000.0f + 18250.0f), 0, 0) {}
    std::string name() const override {
        return "Alter Guardian";
    }
};

class WagbossRobotPosessed : public Boss {
    public:
    WagbossRobotPosessed() : Boss((10000.0f + 22500.0f + 16000.0f), 1, 0) {}
    std::string name() const override {
        return "Alter Guardian -> Wagboss Robot Posessed (1 - 3 phases) -> Lunar Rift";
    }
};

class Klaus : public Boss {
    public:
    Klaus() : Boss((10000.0f+5000.0f),0,0) {}
    std::string name() const override {
        return "Klaus";
    }
};

class AntLion : public Boss {
    public:
    AntLion() : Boss(6000.0f, 0, 0) {}
    std::string name() const override {
        return "Antlion";
    }
};

int main() {
    int choice_character = 3;
    int choice_weapon = 3;
    int choice_debuffs = 2;
    int choice_boss = 4;

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

    std::cout << " \nNow select Debufs (at bosses):\n  1) Weakness (x1.25)\n  2) None\n";
    std::cin >> choice_debuffs;
    switch (choice_debuffs)
    {
        case 1: Effects.applyWeakness(); break;
    };

    std::cout << " \nNow select Boss:\n  1) Bee Quin\n  2) Toad\n  3) Alter Guardian\n  4) Klaus\n  5) AntLion\n  6) WagBoss Possesed\n";
    std::cin >> choice_boss;
    switch (choice_boss)
    {
        case 1: selectedBoss = &motherBee; break;
        case 2: selectedBoss = &toad; break;
        case 3: selectedBoss = &guardian; break;
        case 4: selectedBoss = &Klaus; break;
        case 5: selectedBoss = &AntLion; break;
        case 6: selectedBoss = &WagbossRobotPosessed; break;
        default: selectedBoss = &Dummy; break;
    };

    float perHit = selectedBoss->dmg(Character, Effects, Weapon);
    if (choice_boss > 6) { std::cout << "Damage per hit: " << perHit << "\n"; 
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