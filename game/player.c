#include <math.h>

#include "player.h"

#include "../utils/utils.h"

#include "../menu/skills.h"

Player player;

void initPlayer()
{
    player.health = START_HEALTH;
    player.max_health = START_HEALTH;
    player.mana = START_MANA;
    player.max_mana = START_MANA;
    player.manaRegeneration = 0;

    player.attack = 0;
    player.defence = 0;
    player.speed = 0;

    player.has_key = 0;

    player.money = 0;

    player.level = 1;
    player.xp = 0;

    for(int i = 0; i < 10; i++)
    {
        player.inventory[i].item_type = EMPTY;
    }
}

void updatePlayer()
{
    player.max_health = START_HEALTH * pow(1.1f, health.VALUE);
    player.health = (player.health > player.max_health)?(player.max_health):(player.health);

    player.max_mana = START_HEALTH * pow(1.1f, mana.VALUE);
    player.mana = (player.mana > player.max_mana)?(player.max_mana):(player.mana);

    player.manaRegeneration = manaRegeneration.VALUE;
    player.attack = attack.VALUE;
    player.defence = defence.VALUE;
    player.speed = speed.VALUE;
}