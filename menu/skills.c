#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../utils/windowsFunctions.h"
#include "../utils/utils.h"

#include "../game/player.h"

SLIDER health = {0, 0, MAX_LEVEL, 1};
SLIDER attack = {0, 0, MAX_LEVEL, 1};
SLIDER defence = {0, 0, MAX_LEVEL, 1};
SLIDER speed = {0, 0, MAX_LEVEL, 1};
SLIDER manaRegeneration = {0, 0, MAX_LEVEL, 1};
SLIDER manaCost = {0, 0, MAX_LEVEL, 1};

int calculateXp()
{
    return round(((10*pow((double)player.level - 1, 2)) / (1.5f) + 10) / 10) * 10;
}

void skills(int w, int h)
{
    int selectedItem = 0;
    int skillPoints = player.level - (health.VALUE + attack.VALUE + defence.VALUE + speed.VALUE + manaRegeneration.VALUE + manaCost.VALUE);

    char buffer[30];

    system("cls");

    for(;;)
    {
        ResetConsoleSize(w, h);

        sprintf(buffer, "Level %d", player.level);
        printCenterText(buffer, w, h, 0, -6);

        sprintf(buffer, "XP %d/%d", player.xp, calculateXp());
        printCenterText(buffer, w, h, 0, -5);

        sprintf(buffer, "Skill Points: %d", skillPoints);
        printCenterText(buffer, w, h, 0, -3);


        sprintf(buffer, "Health: %d", health.VALUE);
        printCenterMenu(0, selectedItem, buffer, w, h, 0, -1);

        sprintf(buffer, "Attack: %d", attack.VALUE);
        printCenterMenu(1, selectedItem, buffer, w, h, 0, 0);

        sprintf(buffer, "Defence: %d", defence.VALUE);
        printCenterMenu(2, selectedItem, buffer, w, h, 0, 1);

        sprintf(buffer, "Speed: %d", speed.VALUE);
        printCenterMenu(3, selectedItem, buffer, w, h, 0, 2);

        sprintf(buffer, "Mana Regeneration: %d", manaRegeneration.VALUE);
        printCenterMenu(4, selectedItem, buffer, w, h, 0, 3);

        sprintf(buffer, "Mana Cost: %d", manaCost.VALUE);
        printCenterMenu(5, selectedItem, buffer, w, h, 0, 4);

        printCenterMenu(6, selectedItem, "Back", w, h, 0, 6);

        if(menuInput(&selectedItem, 7) == 1)
        {
            if(selectedItem == 6)
            {
                system("cls");
                return;
            }


        }
    }
}