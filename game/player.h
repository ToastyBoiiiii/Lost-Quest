#ifndef LOSTQUEST_PLAYER_H
#define LOSTQUEST_PLAYER_H

#include "item.h"

#define MAX_LEVEL 30

typedef struct
{
    int room_x;
    int room_y;

    float health;
    float max_health;
    float mana;
    float max_mana;

    char has_key;

    int money;

    int level;
    int xp;

    int health_skill;
    int attack_skill;
    int defence_skill;
    int speed_skill;
    int mana_skill;
    int mana_cost_skill;

    item inventory[10];
} Player;

extern Player player;

void initPlayer();

#endif //LOSTQUEST_PLAYER_H