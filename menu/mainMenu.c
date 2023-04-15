#include <stdio.h>
#include <stdlib.h>

#include "../utils/windowsFunctions.h"
#include "../utils/utils.h"

#include "map.h"
#include "inventory.h"
#include "skills.h"

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