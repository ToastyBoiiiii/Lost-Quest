#include <stdio.h>
#include <stdlib.h>

#include "../utils/windowsFunctions.h"
#include "../utils/utils.h"

#include "map.h"
#include "inventory.h"
#include "skills.h"

#include "../game/player.h"

void mainMenu(int w, int h)
{
    int selectedItem = 0;

    system("cls");

    for(;;)
    {
        ResetConsoleSize(w, h);

        printCenterMenu(0, selectedItem, "Move", w, h, 0, -1);
        printCenterMenu(1, selectedItem, "Inventory", w, h, 0, 0);
        printCenterMenu(2, selectedItem, "Skills", w, h, 0, 1);

        // Print Status of Player
        gotoXY(2, 1);
        printf("Player - Level %d(%d/%d Xp)\n", player.level, player.xp, calculateXp());
        printf("  Money: %d", player.money);
        setColor(DARK_YELLOW, BLACK);
        printf("%c\n\n", 189);
        resetColor();

        printf("  Health: %c", 186);
        for(int i = 0; i < 10; i++)
        {
            if(player.health / player.max_health * 10 > i)
                setColor(BLACK, DARK_RED);
            else
                resetColor();

            printf(" ");
        }
        resetColor();
        printf("%c %3.0f/%3.0f Hp\n", 186, player.health, player.max_health);

        printf("  Mana:   %c", 186);
        for(int i = 0; i < 10; i++)
        {
            if(player.mana / player.max_mana * 10 > i)
                setColor(BLACK, DARK_CYAN);
            else
                resetColor();

            printf(" ");
        }
        resetColor();
        printf("%c %3.0f/%3.0f Mp\n", 186, player.mana, player.max_mana);

        if(menuInput(&selectedItem, 3) == 1)
        {
            if(selectedItem == 0) // Move on Map
            {
                map(w, h);
            } else if(selectedItem == 1) // Manage Inventory
            {
                openInventory(w, h);
            } else // Skills
            {
                skills(w, h);
            }
        }
    }
}