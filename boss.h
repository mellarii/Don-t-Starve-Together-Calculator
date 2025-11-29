#ifndef BOSS_H
#define BOSS_H

#include "characters.h"
#include "weapon.h"
#include "effects.h"

#include <limits>
#include <string>

constexpr float INFINITE_HITPOINTS = std::numeric_limits<float>::max();

class Boss {
protected:
    float health;
    int trueDefence;
    int defence;

public:
    Boss(float h, int d, int td);
    virtual ~Boss() = default;

    float dmg(const Character& attacker, const EffectManager& currentEffects, const Weapon& currentWeapon) const;

    virtual int hitsToKill(const Character& attacker, const EffectManager& effects, const Weapon& weapon) const;

    int needWeapon(const Character& attacker, const EffectManager& effects, const Weapon& weapon) const;

    virtual std::string name() const = 0;
};

class Dummy : public Boss {
public:
    Dummy() : Boss(INFINITE_HITPOINTS, 0, 0) {}
    std::string name() const override;
};

class Bearger : public Boss {
    public:
    Bearger() : Boss(6000, 0, 0) {}
    std::string name() const override;
};

class Dragonfly : public Boss {
    public:
    Dragonfly() : Boss(27500, 0, 0) {}
    std::string name() const override;
};

class Moose : public Boss {
    public:
    Moose() : Boss(6000, 0, 0) {}
    std::string name() const override;
};

class Deerclops : public Boss {
    public:
    Deerclops() : Boss(4000, 0, 0) {}
    std::string name() const override;
};

class Minotaur : public Boss {
    public:
    Minotaur() : Boss(10000, 0, 0) {}
    std::string name() const override;
};

class Eyeofterror : public Boss {
    public:
    Eyeofterror() : Boss(5000, 0, 0) {}
    std::string name() const override;
};

class MotherBee : public Boss {
public:
    MotherBee() : Boss(22500.0f, 0, 0) {}
    std::string name() const override;
};

class ToadStoolDarck : public Boss {
public:
    ToadStoolDarck() : Boss(99999.0f, 0, 0) {}
    std::string name() const override;
};

class AlterGuardian : public Boss {
public:
    AlterGuardian() : Boss((10000.0f + 18000.0f + 18250.0f), 0, 0) {}
    std::string name() const override;
};

class WagbossRobotPosessed : public Boss {
public:
    WagbossRobotPosessed() : Boss((22500.0f + 16000.0f), 1, 0) {}

    int hitsToKill(const Character& attacker, const EffectManager& currentEffects, const Weapon& currentWeapon) const override;

    std::string name() const override;
};

class Klaus : public Boss {
public:
    Klaus() : Boss((10000.0f + 5000.0f), 0, 0) {}
    std::string name() const override;
};

class AntLion : public Boss {
public:
    AntLion() : Boss(6000.0f, 0, 0) {}
    std::string name() const override;
};

class TwinsOfTerror : public Boss {
    public:
    TwinsOfTerror() : Boss(20000.0f, 0, 0) {}
    std::string name() const override;
};

#endif // BOSS_H