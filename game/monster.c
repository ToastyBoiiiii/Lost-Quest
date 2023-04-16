#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "monster.h"

monster monsterList[MONSTER_COUNT];
monster hardMonsterList[HARD_MONSTER_COUNT];
monster bossMonsterList[BOSS_MONSTER_COUNT];

void initMonsters()
{
    FILE *monsterFp = fopen("data/monsterList.data", "rb");
    FILE *hardMonsterFp = fopen("data/hardMonsterList.data", "rb");
    FILE *bossMonsterFp = fopen("data/bossMonsterList.data", "rb");

    if(monsterFp == NULL || hardMonsterFp == NULL || bossMonsterFp == NULL)
    {
        fprintf(stderr, "[ERROR] Couldn't read monster file");
        exit(1);
    }

    int index = 0;

    while(fread(&monsterList[index], sizeof(monster), 1, monsterFp))
        index++;

    index = 0;
    while(fread(&hardMonsterList[index], sizeof(monster), 1, hardMonsterFp))
        index++;

    index = 0;
    while(fread(&bossMonsterList[index], sizeof(monster), 1, bossMonsterFp))
        index++;

    fclose(monsterFp);
    fclose(hardMonsterFp);
    fclose(bossMonsterFp);
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