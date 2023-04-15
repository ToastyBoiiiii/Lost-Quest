#include <stdio.h>
#include <string.h>

#include "../game/item.h"
#include "../game/monster.h"

int main()
{
    FILE *monsterFp = fopen("../data/monsterList.data", "wb");
    FILE *hardMonsterFp = fopen("../data/hardMonsterList.data", "wb");
    FILE *bossMonsterFp = fopen("../data/bossMonsterList.data", "wb");
    
    monster fileMonster;

    strncpy(fileMonster.name, "Giant Rat", 20);
    fileMonster.health = 10;
    fileMonster.min_attack_damage = 5;
    fileMonster.max_attack_damage = 8;
    fileMonster.min_gold_loot = 3;
    fileMonster.max_gold_loot = 5;
    fileMonster.damage_type_resistance = -1;
    fwrite(&fileMonster, sizeof(monster), 1, monsterFp);

    strncpy(fileMonster.name, "Bandit", 20);
    fileMonster.health = 30;
    fileMonster.min_attack_damage = 7;
    fileMonster.max_attack_damage = 10;
    fileMonster.min_gold_loot = 5;
    fileMonster.max_gold_loot = 8;
    fileMonster.damage_type_resistance = -1;
    fwrite(&fileMonster, sizeof(monster), 1, monsterFp);

    strncpy(fileMonster.name, "Ape", 20);
    fileMonster.health = 10;
    fileMonster.min_attack_damage = 5;
    fileMonster.max_attack_damage = 10;
    fileMonster.min_gold_loot = 3;
    fileMonster.max_gold_loot = 8;
    fileMonster.damage_type_resistance = -1;
    fwrite(&fileMonster, sizeof(monster), 1, monsterFp);

    strncpy(fileMonster.name, "Goblin", 20);
    fileMonster.health = 10;
    fileMonster.min_attack_damage = 5;
    fileMonster.max_attack_damage = 8;
    fileMonster.min_gold_loot = 3;
    fileMonster.max_gold_loot = 5;
    fileMonster.damage_type_resistance = -1;
    fwrite(&fileMonster, sizeof(monster), 1, monsterFp);

    strncpy(fileMonster.name, "Orc", 20);
    fileMonster.health = 25;
    fileMonster.min_attack_damage = 5;
    fileMonster.max_attack_damage = 15;
    fileMonster.min_gold_loot = 8;
    fileMonster.max_gold_loot = 20;
    fileMonster.damage_type_resistance = -1;
    fwrite(&fileMonster, sizeof(monster), 1, monsterFp);

    strncpy(fileMonster.name, "Animated Armor", 20);
    fileMonster.health = 30;
    fileMonster.min_attack_damage = 5;
    fileMonster.max_attack_damage = 10;
    fileMonster.min_gold_loot = 3;
    fileMonster.max_gold_loot = 5;
    fileMonster.damage_type_resistance = MANA_WEAPON;
    fwrite(&fileMonster, sizeof(monster), 1, monsterFp);

    strncpy(fileMonster.name, "Zombie", 20);
    fileMonster.health = 20;
    fileMonster.min_attack_damage = 8;
    fileMonster.max_attack_damage = 10;
    fileMonster.min_gold_loot = 5;
    fileMonster.max_gold_loot = 10;
    fileMonster.damage_type_resistance = RANGED_WEAPON;
    fwrite(&fileMonster, sizeof(monster), 1, monsterFp);

    strncpy(fileMonster.name, "Skeleton", 20);
    fileMonster.health = 20;
    fileMonster.min_attack_damage = 8;
    fileMonster.max_attack_damage = 10;
    fileMonster.min_gold_loot = 5;
    fileMonster.max_gold_loot = 10;
    fileMonster.damage_type_resistance = RANGED_WEAPON;
    fwrite(&fileMonster, sizeof(monster), 1, monsterFp);

    strncpy(fileMonster.name, "Ghoul", 20);
    fileMonster.health = 20;
    fileMonster.min_attack_damage = 5;
    fileMonster.max_attack_damage = 8;
    fileMonster.min_gold_loot = 8;
    fileMonster.max_gold_loot = 15;
    fileMonster.damage_type_resistance = -1;
    fwrite(&fileMonster, sizeof(monster), 1, monsterFp);

    strncpy(fileMonster.name, "Kobold", 20);
    fileMonster.health = 15;
    fileMonster.min_attack_damage = 8;
    fileMonster.max_attack_damage = 10;
    fileMonster.min_gold_loot = 3;
    fileMonster.max_gold_loot = 15;
    fileMonster.damage_type_resistance = -1;
    fwrite(&fileMonster, sizeof(monster), 1, monsterFp);

    // Harder Monsters
    strncpy(fileMonster.name, "Hell Hound", 20);
    fileMonster.health = 50;
    fileMonster.min_attack_damage = 5;
    fileMonster.max_attack_damage = 20;
    fileMonster.min_gold_loot = 10;
    fileMonster.max_gold_loot = 30;
    fileMonster.damage_type_resistance = MANA_WEAPON;
    fwrite(&fileMonster, sizeof(monster), 1, hardMonsterFp);

    strncpy(fileMonster.name, "Shadow Wanderer", 20);
    fileMonster.health = 75;
    fileMonster.min_attack_damage = 1;
    fileMonster.max_attack_damage = 30;
    fileMonster.min_gold_loot = 15;
    fileMonster.max_gold_loot = 50;
    fileMonster.damage_type_resistance = MELEE_WEAPON;
    fwrite(&fileMonster, sizeof(monster), 1, hardMonsterFp);

    strncpy(fileMonster.name, "Flameskull", 20);
    fileMonster.health = 60;
    fileMonster.min_attack_damage = 10;
    fileMonster.max_attack_damage = 20;
    fileMonster.min_gold_loot = 10;
    fileMonster.max_gold_loot = 20;
    fileMonster.damage_type_resistance = -1;
    fwrite(&fileMonster, sizeof(monster), 1, hardMonsterFp);

    strncpy(fileMonster.name, "Giant", 20);
    fileMonster.health = 45;
    fileMonster.min_attack_damage = 15;
    fileMonster.max_attack_damage = 25;
    fileMonster.min_gold_loot = 5;
    fileMonster.max_gold_loot = 30;
    fileMonster.damage_type_resistance = -1;
    fwrite(&fileMonster, sizeof(monster), 1, hardMonsterFp);

    strncpy(fileMonster.name, "Blood Witch", 20);
    fileMonster.health = 75;
    fileMonster.min_attack_damage = 5;
    fileMonster.max_attack_damage = 30;
    fileMonster.min_gold_loot = 20;
    fileMonster.max_gold_loot = 50;
    fileMonster.damage_type_resistance = MANA_WEAPON;
    fwrite(&fileMonster, sizeof(monster), 1, hardMonsterFp);

    // Boss Monsters
    strncpy(fileMonster.name, "Amethyst Dragon", 20);
    fileMonster.health = 150;
    fileMonster.min_attack_damage = 30;
    fileMonster.max_attack_damage = 50;
    fileMonster.min_gold_loot = 100;
    fileMonster.max_gold_loot = 100;
    fileMonster.damage_type_resistance = MELEE_WEAPON;
    fwrite(&fileMonster, sizeof(monster), 1, bossMonsterFp);

    strncpy(fileMonster.name, "Red Dracolich", 20);
    fileMonster.health = 150;
    fileMonster.min_attack_damage = 25;
    fileMonster.max_attack_damage = 75;
    fileMonster.min_gold_loot = 100;
    fileMonster.max_gold_loot = 100;
    fileMonster.damage_type_resistance = RANGED_WEAPON;
    fwrite(&fileMonster, sizeof(monster), 1, bossMonsterFp);

    strncpy(fileMonster.name, "Archmage", 20);
    fileMonster.health = 200;
    fileMonster.min_attack_damage = 40;
    fileMonster.max_attack_damage = 55;
    fileMonster.min_gold_loot = 100;
    fileMonster.max_gold_loot = 100;
    fileMonster.damage_type_resistance = MANA_WEAPON;
    fwrite(&fileMonster, sizeof(monster), 1, bossMonsterFp);

    fclose(monsterFp);
    fclose(hardMonsterFp);
    fclose(bossMonsterFp);

    return 0;
}