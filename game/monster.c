#include <stdlib.h>
#include <string.h>

#include "item.h"
#include "monster.h"

monster monsterList[MONSTER_COUNT];
monster hardMonsterList[HARD_MONSTER_COUNT];
monster bossMonsterList[BOSS_MONSTER_COUNT];

void initMonsters()
{
    strncpy(monsterList[0].name, "Giant Rat", 20);
    monsterList[0].health = 10;
    monsterList[0].min_attack_damage = 5;
    monsterList[0].max_attack_damage = 8;
    monsterList[0].min_gold_loot = 3;
    monsterList[0].max_gold_loot = 5;
    monsterList[0].damage_type_resistance = -1;

    strncpy(monsterList[1].name, "Bandit", 20);
    monsterList[1].health = 30;
    monsterList[1].min_attack_damage = 7;
    monsterList[1].max_attack_damage = 10;
    monsterList[1].min_gold_loot = 5;
    monsterList[1].max_gold_loot = 8;
    monsterList[1].damage_type_resistance = -1;

    strncpy(monsterList[2].name, "Ape", 20);
    monsterList[2].health = 10;
    monsterList[2].min_attack_damage = 5;
    monsterList[2].max_attack_damage = 10;
    monsterList[2].min_gold_loot = 3;
    monsterList[2].max_gold_loot = 8;
    monsterList[2].damage_type_resistance = -1;

    strncpy(monsterList[3].name, "Goblin", 20);
    monsterList[3].health = 10;
    monsterList[3].min_attack_damage = 5;
    monsterList[3].max_attack_damage = 8;
    monsterList[3].min_gold_loot = 3;
    monsterList[3].max_gold_loot = 5;
    monsterList[3].damage_type_resistance = -1;

    strncpy(monsterList[4].name, "Orc", 20);
    monsterList[4].health = 25;
    monsterList[4].min_attack_damage = 5;
    monsterList[4].max_attack_damage = 15;
    monsterList[4].min_gold_loot = 8;
    monsterList[4].max_gold_loot = 20;
    monsterList[4].damage_type_resistance = -1;

    strncpy(monsterList[5].name, "Animated Armor", 20);
    monsterList[5].health = 30;
    monsterList[5].min_attack_damage = 5;
    monsterList[5].max_attack_damage = 10;
    monsterList[5].min_gold_loot = 3;
    monsterList[5].max_gold_loot = 5;
    monsterList[5].damage_type_resistance = MANA_WEAPON;

    strncpy(monsterList[6].name, "Zombie", 20);
    monsterList[6].health = 20;
    monsterList[6].min_attack_damage = 8;
    monsterList[6].max_attack_damage = 10;
    monsterList[6].min_gold_loot = 5;
    monsterList[6].max_gold_loot = 10;
    monsterList[6].damage_type_resistance = RANGED_WEAPON;

    strncpy(monsterList[7].name, "Skeleton", 20);
    monsterList[7].health = 20;
    monsterList[7].min_attack_damage = 8;
    monsterList[7].max_attack_damage = 10;
    monsterList[7].min_gold_loot = 5;
    monsterList[7].max_gold_loot = 10;
    monsterList[7].damage_type_resistance = RANGED_WEAPON;

    strncpy(monsterList[8].name, "Ghoul", 20);
    monsterList[8].health = 20;
    monsterList[8].min_attack_damage = 5;
    monsterList[8].max_attack_damage = 8;
    monsterList[8].min_gold_loot = 8;
    monsterList[8].max_gold_loot = 15;
    monsterList[8].damage_type_resistance = -1;

    strncpy(monsterList[9].name, "Kobold", 20);
    monsterList[9].health = 15;
    monsterList[9].min_attack_damage = 8;
    monsterList[9].max_attack_damage = 10;
    monsterList[9].min_gold_loot = 3;
    monsterList[9].max_gold_loot = 15;
    monsterList[9].damage_type_resistance = -1;

    // Harder Monsters
    strncpy(hardMonsterList[0].name, "Hell Hound", 20);
    hardMonsterList[0].health = 50;
    hardMonsterList[0].min_attack_damage = 5;
    hardMonsterList[0].max_attack_damage = 20;
    hardMonsterList[0].min_gold_loot = 10;
    hardMonsterList[0].max_gold_loot = 30;
    hardMonsterList[0].damage_type_resistance = MANA_WEAPON;

    strncpy(hardMonsterList[1].name, "Shadow Wanderer", 20);
    hardMonsterList[1].health = 75;
    hardMonsterList[1].min_attack_damage = 1;
    hardMonsterList[1].max_attack_damage = 30;
    hardMonsterList[1].min_gold_loot = 15;
    hardMonsterList[1].max_gold_loot = 50;
    hardMonsterList[1].damage_type_resistance = MELEE_WEAPON;

    strncpy(hardMonsterList[2].name, "Flameskull", 20);
    hardMonsterList[2].health = 60;
    hardMonsterList[2].min_attack_damage = 10;
    hardMonsterList[2].max_attack_damage = 20;
    hardMonsterList[2].min_gold_loot = 10;
    hardMonsterList[2].max_gold_loot = 20;
    hardMonsterList[2].damage_type_resistance = -1;

    strncpy(hardMonsterList[3].name, "Giant", 20);
    hardMonsterList[3].health = 45;
    hardMonsterList[3].min_attack_damage = 15;
    hardMonsterList[3].max_attack_damage = 25;
    hardMonsterList[3].min_gold_loot = 5;
    hardMonsterList[3].max_gold_loot = 30;
    hardMonsterList[3].damage_type_resistance = -1;

    strncpy(hardMonsterList[4].name, "Blood Witch", 20);
    hardMonsterList[4].health = 75;
    hardMonsterList[4].min_attack_damage = 5;
    hardMonsterList[4].max_attack_damage = 30;
    hardMonsterList[4].min_gold_loot = 20;
    hardMonsterList[4].max_gold_loot = 50;
    hardMonsterList[4].damage_type_resistance = MANA_WEAPON;

    // Boss Monsters
    strncpy(bossMonsterList[0].name, "Amethyst Dragon", 20);
    bossMonsterList[0].health = 150;
    bossMonsterList[0].min_attack_damage = 30;
    bossMonsterList[0].max_attack_damage = 50;
    bossMonsterList[0].min_gold_loot = 100;
    bossMonsterList[0].max_gold_loot = 100;
    bossMonsterList[0].damage_type_resistance = MELEE_WEAPON;

    strncpy(bossMonsterList[1].name, "Red Dracolich", 20);
    bossMonsterList[1].health = 150;
    bossMonsterList[1].min_attack_damage = 25;
    bossMonsterList[1].max_attack_damage = 75;
    bossMonsterList[1].min_gold_loot = 100;
    bossMonsterList[1].max_gold_loot = 100;
    bossMonsterList[1].damage_type_resistance = RANGED_WEAPON;

    strncpy(bossMonsterList[2].name, "Archmage", 20);
    bossMonsterList[2].health = 200;
    bossMonsterList[2].min_attack_damage = 40;
    bossMonsterList[2].max_attack_damage = 55;
    bossMonsterList[2].min_gold_loot = 100;
    bossMonsterList[2].max_gold_loot = 100;
    bossMonsterList[2].damage_type_resistance = MANA_WEAPON;
}

monster generateMonster(int len, monster randomMonsterList[len])
{
    monster randomMonster;
    int randomMonsterIndex = rand()%len;

    strncpy(randomMonster.name, randomMonsterList[randomMonsterIndex].name, 20);
    randomMonster.health = randomMonsterList[randomMonsterIndex].health;
    randomMonster.min_attack_damage = randomMonsterList[randomMonsterIndex].min_attack_damage;
    randomMonster.max_attack_damage = randomMonsterList[randomMonsterIndex].max_attack_damage;
    randomMonster.min_gold_loot = randomMonsterList[randomMonsterIndex].min_gold_loot;
    randomMonster.max_gold_loot = randomMonsterList[randomMonsterIndex].max_gold_loot;
    randomMonster.damage_type_resistance = randomMonsterList[randomMonsterIndex].damage_type_resistance;

    return randomMonster;
}