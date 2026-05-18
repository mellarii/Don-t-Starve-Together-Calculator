#include "boss.h"

#include <cmath>
#include <limits>

Boss::Boss(float h, int armour, int tResist) : health(h), trueResist(tResist), hasArmour(armour ? 1 : 0) {}

float Boss::dmg(const Character& attacker, const EffectManager& currentEffects, const Weapon& currentWeapon) const {
    float charDmgBonus = attacker.getCharacterDmgBonus();
    float effectMultiplier = currentEffects.getMultiplier();
    float dfltDmg = currentWeapon.getDfltDamage();
    float trueDmg = currentWeapon.getTrueDamage();

    float hitDmg = 0.0f;
    if (hasArmour > 0) {
        hitDmg = (std::sqrt((dfltDmg * charDmgBonus * effectMultiplier) * 4.0f + 64.0f) - 8.0f) * 4.0f + trueDmg - trueResist;
    } else {
        hitDmg = (dfltDmg * charDmgBonus * effectMultiplier) + trueDmg - trueResist;
    }

    return hitDmg;
}

int Boss::hitsToKill(const Character& attacker, const EffectManager& effects, const Weapon& weapon) const {
    float perHit = dmg(attacker, effects, weapon);
    if (perHit <= 0.0f) {
        return std::numeric_limits<int>::max();
    }
    return static_cast<int>(std::ceil(health / perHit));
}

int Boss::needWeapon(const Character& attacker, const EffectManager& currentEffects, const Weapon& currentWeapon) const {
    int hits = hitsToKill(attacker, currentEffects, currentWeapon);
    if (hits == std::numeric_limits<int>::max()) return hits;
    int usage = currentWeapon.getMaxUsage();
    if (usage <= 0) return std::numeric_limits<int>::max();
    return static_cast<int>(std::ceil(static_cast<float>(hits) / static_cast<float>(usage)));
}

std::string Dummy::name() const {
    return "Dummy";
}

std::string Bearger::name() const {
    return "Bearger";
}

std::string Dragonfly::name() const {
    return "Dragonfly";
}

std::string Moose::name() const {
    return "Moose";
}

std::string Deerclops::name() const {
    return "Deerclops";
}

std::string Minotaur::name() const {
    return "Minotaur";
}

std::string Eyeofterror::name() const {
    return "Eye Of terror";
}

std::string MotherBee::name() const {
    return "Bee Quin";
}

std::string ToadStoolDarck::name() const {
    return "Toad";
}

std::string AlterGuardian::name() const {
    return "Alter Guardian";
}

std::string WagbossRobotPosessed::name() const {
    return "Wagboss Robot";
}

std::string Klaus::name() const {
    return "Klaus";
}

std::string AntLion::name() const {
    return "AntLion";
}

std::string TwinsOfTerror::name() const {
    return "TwinsOfTerror";
}

std::string AtriumStalcer::name() const {
    return "Atrium Stalcer";
}

int WagbossRobotPosessed::hitsToKill(const Character& attacker, const EffectManager& currentEffects, const Weapon& currentWeapon) const {
    float per = dmg(attacker, currentEffects, currentWeapon);
    float charDmgBonus = attacker.getCharacterDmgBonus();
    float EffectMultiplier = currentEffects.getMultiplier();
    float dfltDmg = currentWeapon.getDfltDamage();
    float trueDmg = currentWeapon.getTrueDamage();

    float hit_FFase = (dfltDmg * charDmgBonus * EffectMultiplier) + trueDmg - trueResist;
    if (hit_FFase <= 0.0f) return std::numeric_limits<int>::max();

    int baseHits = static_cast<int>(std::ceil(health / per));
    int extra = static_cast<int>(std::ceil(10000.0f / hit_FFase));
    return baseHits + extra;
}
