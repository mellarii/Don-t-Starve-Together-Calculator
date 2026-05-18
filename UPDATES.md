# Changelog

## v1.2
- Added option to continue or exit the program after calculation
- Program window stays open until Enter is pressed on exit

## v1.1b
- **Bosses**: Added Twins of Terror
- **Weapons**: Added 10 new weapons (Shadow Battle Axe, Cloth Scyte, Void Lunar Part, Night Sword, Glass Cutter, Tentacle Spike, Shield of Terror, Spear, Wigfrid's Spear, Rabbit King Spear)
- **Build**: Added CMake support

## v1.1
- **Bosses**: Added Bearger, Dragonfly, Moose, Deerclops, Minotaur, Eye of Terror
- **Refactor**: Decomposed into separate modules (boss, character, effect, weapon)

## v1.0c
- **Bosses**: Fixed Wagboss Robot calculation bug
- **Effects**: Added Moon Enemy and Shadow Enemy weakness effects
- **Core**: `hitsToKill` is now virtual

## v1.0b
- **Bosses**: Renamed defoultManeken → Dummy; added Klaus, AntLion, Wagboss Robot
- **Characters**: Added Wes (x0.75 dmg); fixed naming (Volvgang → Wolvgang, Vigfrid → Wigfrid)
- **Mechanics**: Infinite usage constant introduced

## v1.0
- Initial release with basic functionality:
  - `dmg()` — single hit damage calculation
  - `hitsToKill()` — hits required to defeat a boss
  - `needWeapon()` — required weapon count
- Weapons: Ham Bat, Ruins Bat, Hand
- Debuffs: Weakness
- Bosses: Dummy, Toadstool, Alter Guardian, Bee Queen
- Characters: Wigfrid, Wolfgang, Other
