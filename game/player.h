#ifndef LOSTQUEST_PLAYER_H
#define LOSTQUEST_PLAYER_H

#include "item.h"

#define MAX_LEVEL 30

#define START_HEALTH 100
#define START_MANA 100

typedef struct
{
    int room_x;
    int room_y;

    float health;
    int max_health;
    float mana;
    int max_mana;
    int manaRegeneration;

    float attack;
    float defence;
    int speed;

    char has_key;

    int money;

    int level;
    int xp;

    item inventory[10];
} Player;

extern Player player;

void initPlayer();
void updatePlayer();

#endif //LOSTQUEST_PLAYER_H