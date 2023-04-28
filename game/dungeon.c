#include <windows.h>

#include "../utils/utils.h"

#include "player.h"
#include "dungeon.h"

room dungeon[DUNGEON_WIDTH][DUNGEON_HEIGHT];

void generateRandomRoom(int x, int y)
{
    if(x >= DUNGEON_WIDTH || y >= DUNGEON_HEIGHT)
    {
        return;
    }

    dungeon[x][y].visited = TRUE;
    dungeon[x][y].contains_loot = randomChance(LOOT_CHANCE, 100);
    dungeon[x][y].contains_monster = randomChance(MONSTER_CHANCE, 100);
    dungeon[x][y].has_trap = randomChance(TRAP_CHANCE, 100);

    if(dungeon[x][y].has_trap)
    {
        dungeon[x][y].trap_damage = rand()%10+5;
    }
}

boolean validPosition(int x, int y)
{
    if(x < 0 || y < 0 || x > DUNGEON_WIDTH-1 || y > DUNGEON_HEIGHT - 1)
    {
        return FALSE;
    } else if(dungeon[x][y].visited)
    {
        return FALSE;
    }

    return TRUE;
}

int findNeighbors(int x, int y, int neighbors[4][2])
{
    int foundNeighbors = 0;

    if(validPosition(x, y-1))
    {
        neighbors[foundNeighbors][0] = x;
        neighbors[foundNeighbors][1] = y-1;
        foundNeighbors++;
    }
    if(validPosition(x+1, y))
    {
        neighbors[foundNeighbors][0] = x+1;
        neighbors[foundNeighbors][1] = y;
        foundNeighbors++;
    }
    if(validPosition(x, y+1))
    {
        neighbors[foundNeighbors][0] = x;
        neighbors[foundNeighbors][1] = y+1;
        foundNeighbors++;
    }
    if(validPosition(x-1, y))
    {
        neighbors[foundNeighbors][0] = x-1;
        neighbors[foundNeighbors][1] = y;
        foundNeighbors++;
    }

    return foundNeighbors;
}

int findUnconnectedNeighbors(int x, int y, int neighbors[4][2])
{
    int foundNeighbors = 0;

    if(validPosition(x, y-1) && !dungeon[x][y].north_door)
    {
        neighbors[foundNeighbors][0] = x;
        neighbors[foundNeighbors][1] = y-1;
        foundNeighbors++;
    }
    if(validPosition(x+1, y) && !dungeon[x][y].east_door)
    {
        neighbors[foundNeighbors][0] = x+1;
        neighbors[foundNeighbors][1] = y;
        foundNeighbors++;
    }
    if(validPosition(x, y+1) && !dungeon[x][y].south_door)
    {
        neighbors[foundNeighbors][0] = x;
        neighbors[foundNeighbors][1] = y+1;
        foundNeighbors++;
    }
    if(validPosition(x-1, y) && !dungeon[x][y].west_door)
    {
        neighbors[foundNeighbors][0] = x-1;
        neighbors[foundNeighbors][1] = y;
        foundNeighbors++;
    }

    return foundNeighbors;
}

void connectRooms(int room1[2], int room2[2])
{
    int delta[2] = {room1[0] - room2[0], room1[1] - room2[1]};

    if(delta[0] == 0 && delta[1] == -1)
    {
        dungeon[room1[0]][room1[1]].south_door = TRUE;
        dungeon[room2[0]][room2[1]].north_door = TRUE;
    } else if(delta[0] == 1 && delta[1] == 0)
    {
        dungeon[room1[0]][room1[1]].west_door = TRUE;
        dungeon[room2[0]][room2[1]].east_door = TRUE;
    } else if(delta[0] == 0 && delta[1] == 1)
    {
        dungeon[room1[0]][room1[1]].north_door = TRUE;
        dungeon[room2[0]][room2[1]].south_door = TRUE;
    } else if(delta[0] == -1 && delta[1] == 0)
    {
        dungeon[room1[0]][room1[1]].east_door = TRUE;
        dungeon[room2[0]][room2[1]].west_door = TRUE;
    }
}

void generateDungeon()
{
    for(int x = 0; x < DUNGEON_WIDTH; x++)
    {
        for(int y = 0; y < DUNGEON_HEIGHT; y++)
        {
            dungeon[x][y].visited = FALSE;

            dungeon[x][y].is_exit = FALSE;
            dungeon[x][y].has_key = FALSE;
            dungeon[x][y].contains_loot = FALSE;
            dungeon[x][y].contains_monster = FALSE;
            dungeon[x][y].has_trap = FALSE;

            dungeon[x][y].north_door = FALSE;
            dungeon[x][y].east_door = FALSE;
            dungeon[x][y].south_door = FALSE;
            dungeon[x][y].west_door = FALSE;
        }
    }

    int stackSize = 0;
    int stack[DUNGEON_HEIGHT * DUNGEON_WIDTH][2];

    stack[0][0] = rand()%DUNGEON_WIDTH;
    stack[0][1] = rand()%DUNGEON_HEIGHT;

    player.room_x = stack[0][0];
    player.room_y = stack[0][1];

    int neighborCount;
    int neighbors[4][2];

    dungeon[stack[0][0]][stack[0][1]].visited = TRUE;

    for(int i = 0; i < DUNGEON_HEIGHT * DUNGEON_WIDTH; i++)
    {
        while((neighborCount = findNeighbors(stack[stackSize][0], stack[stackSize][1], neighbors)) == 0)
        {
            stackSize--;

            if(stackSize < 0)
            {
                break;
            }
        }

        if(stackSize < 0)
        {
            break;
        }

        neighborCount = rand()%neighborCount;

        stackSize++;

        stack[stackSize][0] = neighbors[neighborCount][0];
        stack[stackSize][1] = neighbors[neighborCount][1];

        dungeon[stack[stackSize][0]][stack[stackSize][1]].visited = TRUE;
        generateRandomRoom(stack[stackSize][0], stack[stackSize][1]);

        connectRooms(stack[stackSize], stack[stackSize-1]);

        if(i == DUNGEON_WIDTH * DUNGEON_HEIGHT - 2)
        {
            stack[1][0] = stack[stackSize][0];
            stack[1][1] = stack[stackSize][1];

            dungeon[stack[stackSize][0]][stack[stackSize][1]].is_exit = TRUE;
        }
    }

    int keyPos[2];

    do
    {
        keyPos[0] = rand()%DUNGEON_WIDTH;
        keyPos[1] = rand()%DUNGEON_HEIGHT;
    } while((keyPos[0] == stack[0][0] && keyPos[1] == stack[0][1]) || (keyPos[0] == stack[1][0] && keyPos[1] == stack[1][1]));

    dungeon[keyPos[0]][keyPos[1]].has_key = TRUE;

    for(int x = 0; x < DUNGEON_WIDTH; x++)
    {
        for(int y = 0; y < DUNGEON_HEIGHT; y++)
        {
            dungeon[x][y].visited = FALSE;
        }
    }

    // Add random path
    for(int i = 0; i < min((float)DUNGEON_WIDTH * (float)DUNGEON_HEIGHT * ((float)PATH_PERCENTAGE / 100), (float)DUNGEON_WIDTH * (float)DUNGEON_HEIGHT * 0.9f); i++)
    {
        do
        {
            stack[1][0] = rand()%DUNGEON_WIDTH;
            stack[1][1] = rand()%DUNGEON_HEIGHT;

            neighborCount = findUnconnectedNeighbors(stack[1][0], stack[1][1], neighbors);
        } while(neighborCount == 0);

        connectRooms(stack[1], neighbors[rand()%neighborCount]);
    }

    dungeon[stack[0][0]][stack[0][1]].visited = TRUE;
}