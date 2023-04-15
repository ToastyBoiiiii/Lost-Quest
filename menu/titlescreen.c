#include <stdio.h>

#include "mainMenu.h"
#include "options.h"

#include "../utils/windowsFunctions.h"

void titleScreen(int w, int h)
{
    int selectedItem = 0;

    system("cls");

    for(;;)
    {
        ResetConsoleSize(w, h);

        gotoXY(0, 0);
        printf("\n\n\n\n\n\n\n");
        printSpacesAndText(w/2-22, " __            _      _____             _\n");
        printSpacesAndText(w/2-22, "|  |   ___ ___| |_   |     |_ _ ___ ___| |_\n");
        printSpacesAndText(w/2-22, "|  |__| . |_ -|  _|  |  |  | | | -_|_ -|  _|\n");
        printSpacesAndText(w/2-22, "|_____|___|___|_|    |__  _|___|___|___|_|\n");
        printSpacesAndText(w/2-22, "                        |__|\n");

        printCenterMenu(0, selectedItem, "Start Game", w, h, 0, 2);
        printCenterMenu(1, selectedItem, "Options", w, h, 0, 4);
        printCenterMenu(2, selectedItem, "Quit", w, h, 0, 6);

        if(menuInput(&selectedItem, 3) == 1)
        {
            if(selectedItem == 0) // Start Game
            {
                mainMenu(w, h);
            } else if(selectedItem == 1) // Options
            {
                options(w, h);
            } else // Quit
            {
                return;
            }
        }
    }
}