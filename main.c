#include <stdlib.h>
#include <conio.h>
#include <time.h>

#include "utils/windowsFunctions.h"

#include "game/player.h"
#include "game/dungeon.h"
#include "game/item.h"
#include "game/monster.h"

#include "menu/titlescreen.h"

void init()
{
    initPlayer();
    initItems();
    initMonsters();

    player.inventory[0] = generateRandomItem();
    player.inventory[1] = generateRandomItem();
    player.inventory[2] = generateRandomItem();
    player.inventory[3] = generateRandomItem();
    player.inventory[4] = generateRandomItem();
    player.inventory[5] = generateRandomItem();
    player.inventory[6] = generateRandomItem();
    player.inventory[7] = generateRandomItem();
    player.inventory[8] = generateRandomItem();
    player.inventory[9] = generateRandomItem();

    generateDungeon();
}

void close()
{
    system("cls");
    EnableMaximizeButton();
    showCursor();
}

int main()
{
    // Set Random Seed
    srand(time(NULL));

    // Initialize Console
    system("title Lost Quest");
    RemoveConsoleScrollbars();
    DisableMaximizeButton();
    DisableF11ForFullscreen();
    hideCursor();

    // Initialize Variables
    int w, h;
    w = 120;
    h = 30;

    init();

    titleScreen(w, h);

    close();

    return 0;
}