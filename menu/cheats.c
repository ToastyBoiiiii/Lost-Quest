#include <stdio.h>

#include "../utils/windowsFunctions.h"
#include "../utils/utils.h"

int infiniteHealth = 0;
int infiniteDamage = 0;

void cheatMenu(int w, int h)
{
    int selectedItem = 0;
    char buffer[20];

    system("cls");

    for(;;)
    {
        ResetConsoleSize(w, h);

        gotoXY(0, 0);
        printf("\n\n\n\n\n\n\n");

        printSpacesAndText(w/2-27/2, " _____ _           _\n");
        printSpacesAndText(w/2-27/2, "|     | |_ ___ ___| |_ ___\n");
        printSpacesAndText(w/2-27/2, "|   --|   | -_| .'|  _|_ -|\n");
        printSpacesAndText(w/2-27/2, "|_____|_|_|___|__,|_| |___|\n");

        sprintf(buffer, "Infinite Health: %s", (infiniteHealth)?("On"):("Off"));
        printCenterMenu(0, selectedItem, buffer, w, h, 0, -1);

        sprintf(buffer, "Infinite Damage: %s", (infiniteDamage)?("On"):("Off"));
        printCenterMenu(1, selectedItem, buffer, w, h, 0, 0);

        printCenterMenu(2, selectedItem, "Back", w, h, 0, 1);

        if(menuInput(&selectedItem, 3) == 1)
        {
            if(selectedItem == 0) // infinite Health
            {
                infiniteHealth = !infiniteHealth;

                sprintf(buffer, "Infinite Health: %s", (infiniteHealth)?("On"):("Off"));
                removeSliderExcess(1, strlen(buffer)+4, -1, w, h);
            } else if(selectedItem == 1) // infinite Damage
            {
                infiniteDamage = !infiniteDamage;

                sprintf(buffer, "Infinite Damage: %s", (infiniteDamage)?("On"):("Off"));
                removeSliderExcess(1, strlen(buffer)+4, 0, w, h);
            } else // Back
            {
                system("cls");
                return;
            }
        }
    }
}