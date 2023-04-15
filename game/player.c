#include "player.h"

Player player;

void initPlayer()
{
    player.health = 100;
    player.max_health = 100;
    player.mana = 100;
    player.max_mana = 100;

    player.has_key = 0;

    player.money = 0;

    player.level = 1;
    player.xp = 0;

    player.health_skill = 0;
    player.attack_skill = 0;
    player.defence_skill = 0;
    player.speed_skill = 0;
    player.mana_skill = 0;
    player.mana_cost_skill = 0;

    for(int i = 0; i < 10; i++)
    {
        player.inventory[i].item_type = EMPTY;
    }
}