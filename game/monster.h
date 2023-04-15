#ifndef LOSTQUEST_MONSTER_H
#define LOSTQUEST_MONSTER_H

#define MONSTER_COUNT 10
#define HARD_MONSTER_COUNT 5
#define BOSS_MONSTER_COUNT 3

typedef struct
{
    char name[20];

    int health;
    int min_attack_damage;
    int max_attack_damage;
    int min_gold_loot;
    int max_gold_loot;
    int damage_type_resistance;
} monster;

extern monster monsterList[MONSTER_COUNT];
extern monster hardMonsterList[HARD_MONSTER_COUNT];
extern monster bossMonsterList[BOSS_MONSTER_COUNT];

void initMonsters();
monster generateMonster(int len, monster monsterList[len]);

#endif //LOSTQUEST_MONSTER_H