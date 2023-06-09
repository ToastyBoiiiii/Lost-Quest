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
SLIDER mana = {0, 0, MAX_LEVEL, 1};

int calculateXp()
{
    return round(((10*pow((double)player.level - 1, 2)) / (1.5f) + 10) / 10) * 10;
}

void skills(int w, int h)
{
    int selectedItem = 0;
    int skillPoints;

    int result;
    char buffer[30];

    SLIDER *sliderPointer;

    system("cls");

    for(;;)
    {
        ResetConsoleSize(w, h);

        sprintf(buffer, "Level %d", player.level);
        printCenterText(buffer, w, h, 0, -6);

        sprintf(buffer, "XP %d/%d", player.xp, calculateXp());
        printCenterText(buffer, w, h, 0, -5);

        skillPoints = player.level - (health.VALUE + attack.VALUE + defence.VALUE + speed.VALUE + manaRegeneration.VALUE + mana.VALUE) + 2;
        sprintf(buffer, "Skill Points: %d", skillPoints);
        printCenterText(buffer, w, h, 0, -3);


        sprintf(buffer, "Health(%d): %d HP", health.VALUE, player.max_health);
        printCenterMenu(0, selectedItem, buffer, w, h, 0, -1);

        sprintf(buffer, "Attack(%d): +%.2f%%", attack.VALUE, player.attack);
        printCenterMenu(1, selectedItem, buffer, w, h, 0, 0);

        sprintf(buffer, "Defence(%d): -%.2f%% DMG", defence.VALUE, player.defence);
        printCenterMenu(2, selectedItem, buffer, w, h, 0, 1);

        sprintf(buffer, "Speed(%d): %d", speed.VALUE, player.speed);
        printCenterMenu(3, selectedItem, buffer, w, h, 0, 2);

        sprintf(buffer, "Mana Regeneration(%d): %d", manaRegeneration.VALUE, player.manaRegeneration);
        printCenterMenu(4, selectedItem, buffer, w, h, 0, 3);

        sprintf(buffer, "Mana(%d): %d MP", mana.VALUE, player.max_mana);
        printCenterMenu(5, selectedItem, buffer, w, h, 0, 4);

        printCenterMenu(6, selectedItem, "Back", w, h, 0, 6);

        result = menuInput(&selectedItem, 7);
        if(result)
        {
            if(selectedItem == 6)
            {
                system("cls");
                return;
            }

            if((result == RIGHT || result == 1) && skillPoints-1 == -1)
            {
                continue;
            }

            switch(selectedItem)
            {
                case 0:
                    sliderPointer = &health;
                    sprintf(buffer, "Health(%d): %d HP", health.VALUE, player.max_health);
                    break;
                case 1:
                    sliderPointer = &attack;
                    sprintf(buffer, "Attack(%d): +%.2f%%", attack.VALUE, player.attack);
                    break;
                case 2:
                    sliderPointer = &defence;
                    sprintf(buffer, "Defence(%d): -%.2f%% DMG", defence.VALUE, player.defence);
                    break;
                case 3:
                    sliderPointer = &speed;
                    sprintf(buffer, "Speed(%d): %d", speed.VALUE, player.speed);
                    break;
                case 4:
                    sliderPointer = &manaRegeneration;
                    sprintf(buffer, "Mana Regeneration(%d): %d", manaRegeneration.VALUE, player.manaRegeneration);
                    break;
                case 5:
                    sliderPointer = &mana;
                    sprintf(buffer, "Mana(%d): %d MP", mana.VALUE, player.max_mana);
                    break;
            }

            handleSlider(sliderPointer, result);
            removeSliderExcess(1, strlen(buffer) + 4, selectedItem - 1, w, h);

            sprintf(buffer, "Skill Points: %d", skillPoints);
            removeSliderExcess(1, strlen(buffer), -3, w, h);

            updatePlayer();
        }
    }
}