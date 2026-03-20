######### * Don-t-Starve-Together-Calculator * #########

---Сделано лишь для того, что бы потренировать мои навыки, 
   но если будет полезно кому то кроме меня, будет неплохо.

---Это калькулятор для игры Don-t-Starve-Together, производит
   рассчёты необходимого снаряжения для рейда какого либо босса.


!!! - О нумерации обновлений и коммитах:
--- Название каждого коммита отображает версию, которая в нём была добавлена:
---- v1.0 - первая полноценная работоспособная версия, отмеченная коммитом **Calc v1.0**
---- Буквенные обновления (например v1.0c, v2.6b, v1.4e) - небольшие обновления с мелкими изменениями функционала/польз.интерфейса/системной части
---- Номерные изменения после точки (например, v1.1, v1.6, v2.4) - более глобальные обновления со значительными 
изменениями функционала/польз.интерфейса/системной части.
---- Номерные изменения (например v1.x, v2.x) - кординальные обновления с большим количесиврм изменений 
функционала/польз.интерфейса/системной частей ЛИБО с количеством изменений, сопоставимых по количество и качеству
с "Номерными изменениями после точки".
---- "No many new" - коммиты, не несущие изменеий функционала/польз.интерфейса/системной части, но фиксирующие мелкие 
недочеты/ошибки/изменения, например комментарии в коде, оформление кода, README.txt .

########################################################

#-----/ v1.2 /-----#

- About the server part:
-- Now you can left programm when you need:
--- std::cout << "Do you want to continue? (Y/N)";
--- std::cin >> continueChoice;

-- If choose Y (yes), programm restarts:
--- std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

-- If the program is terminated, the window will not close until you press enter:
--- std::cout << "Press Enter to exit...";
--- std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
--- std::cin.get();

#------------------#

C---( v1.1a )---C

- About Boses:
-- Added one new boss:
--- Twins of Terror.

- About Weapons:
-- Added 10 new Weapons:
--- Shadow Battle Axe, Cloth Scyte, Void Lunar Part, Night Sword, Class Scutter, Tentacle Spike, 
Shield of Terror, Spear, Wigfrid's spear, Rabbit King Spear.

- About the server part:
-- Added CMakem for more simple compile&run project

C---------------C

#-----/ v1.1 /-----#

- About Boses :
-- Added six new booses:
--- Bearger, Dragonfly, Moose, Deerclops, Minotaur, Eye of Terror.

- About server part:
-- File decomposition has been carried out:
--- Bosses main.cpp -> boss.cpp & boss.h ;
--- Characters main.cpp -> characters.cpp & characters.h ;
--- Effects main.cpp -> effects.cpp & effects.h ;
--- Weapons main.cpp -> weapon.cpp & weapon.h .

#------------------#

B---( v1.0b )---B

- About Boses:
-- Fixed Bug with Wagboss Robot (check v1.0b).

- About Effects:
-- Added 2 new effects:
--- Moon Enemy, Shadow Enemy. (In game some character have buffs to 10% in skill tree when you defeat AtriumStalcer/AlterGuardian firstly)

- About the server part:
-- Now function hitsToKill is virtual.

B---------------B

A---( v1.0a )---A

- About Boses:
-- Changed name - defoultManeken -> Dummy.
-- Added 3 new Boses:
--- Klaus, AntLion, Wagboss Robot.

-- Now when you select an option not from the list, the mannequin will be automatically selected.

-- Now when selecting a dummy, only damage per hit with the selected parameters is displayed.

-- Known Bugs:
--- Wagboss Robot -> (The calculation isn't quite accurate. The first phase shouldn't 
have resistance to physical damage, but the others should. I'll fix that in the future).

- About Characters:
-- Added new character:
--- Wess (x0.75 dmg).

-- Changed names:
--- Volvgang -> Wolvgang,
--- Vigfrid -> Wigfrid.

- About the server part:
-- Large number of uses -> INFINIT_USAGE (where it's needed).

A---------------A

#-----/ v1.0 /-----#

- Added simple functionality:
-- "hitDmg" to calculate single hit damage.
-- "hitsToKill" to calculate the number of hits required to kill a boss.
-- "needWeapon" to calculate the required amount of weapons.
-- Other *non-user* functions.

- Added weapon examples:
-- HamBat, RuinsBat, Hand.

- Added debuff examples:
-- Weakness.

- Added boss examples:
-- defoultManeken, ToadStoolDarck, AlterGuardian, MotherBee.

- Added character examples:
-- Vigfrid, Volvgang, Other.

#------------------#
