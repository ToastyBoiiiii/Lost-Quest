#ifndef LOSTQUEST_DUNGEON_H
#define LOSTQUEST_DUNGEON_H

#include <windows.h>

#define DUNGEON_WIDTH 10
#define DUNGEON_HEIGHT 10

#define LOOT_CHANCE 33
#define MONSTER_CHANCE 45
#define TRAP_CHANCE 20

typedef struct
{
    boolean visited;

    boolean north_door;
    boolean east_door;
    boolean south_door;
    boolean west_door;
    boolean contains_loot;
    boolean is_exit;
    boolean has_key;
    boolean contains_monster;
    boolean has_trap;
    int trap_damage;
} room;

extern room dungeon[DUNGEON_WIDTH][DUNGEON_HEIGHT];

void generateRandomRoom(int x, int y);
void generateDungeon();

#endif //LOSTQUEST_DUNGEON_H
