#include <stdio.h>
#include <stdlib.h>

#include "../utils/windowsFunctions.h"
#include "../utils/utils.h"

#include "../game/player.h"

int moveItem(int w, int h, int itemIndex)
{
    SLIDER dropCount = {player.inventory[itemIndex].item_count, 1, player.inventory[itemIndex].item_count, 1};

    int result;
    int selectedItem = 0;

    char buffer[30];
    int length[3];

    system("cls");

    for(;;)
    {
        ResetConsoleSize(w, h);

        for(int i = 0; i < 10; i++)
        {
            if(player.inventory[i].item_type == EMPTY)
                sprintf(buffer, "Empty");
            else
                sprintf(buffer, "%dx %s", player.inventory[i].item_count, player.inventory[i].name);

            printCenterMenu(i, selectedItem, buffer, w, h, 0, i-6);
        }

        printCenterMenu(10, selectedItem, "Back", w, h, 0, 5);

        result = menuInput(&selectedItem, 11);
        if(result)
        {
            if(selectedItem == 10) // Quit
            {
                system("cls");
                return 0;
            }

            item tempItem = player.inventory[selectedItem];
            player.inventory[selectedItem] = player.inventory[itemIndex];
            player.inventory[itemIndex] = tempItem;
            system("cls");
            return 1;
        }
    }
}

int dropItem(int w, int h, int itemIndex)
{
    SLIDER dropCount = {player.inventory[itemIndex].item_count, 1, player.inventory[itemIndex].item_count, 1};

    int result;
    int selectedItem = 0;

    char buffer[20];
    int length[3];

    system("cls");

    for(;;)
    {
        ResetConsoleSize(w, h);

        sprintf(buffer, "Amount: %d of %d", dropCount.VALUE, dropCount.MAX_VALUE);
        printCenterMenu(0, selectedItem, buffer, w, h, 0, -1);

        printCenterMenu(1, selectedItem, "Back", w, h, 0, 1);

        result = menuInput(&selectedItem, 2);
        if(result)
        {
            if(selectedItem == 0) // Drop Count
            {
                if(result == 1)
                {
                    if(player.inventory[itemIndex].item_count - dropCount.VALUE <= 0)
                        player.inventory[itemIndex].item_type = EMPTY;
                    else
                        player.inventory[itemIndex].item_count -= dropCount.VALUE;

                    system("cls");
                    return 1;
                }

                handleSlider(&dropCount, result);

                sprintf(buffer, "Amount: %d of %d", dropCount.VALUE, dropCount.MAX_VALUE);
                removeSliderExcess(1, strlen(buffer) + 4, -1, w, h);
            } else if(result == 1) // Back
            {
                system("cls");
                return 0;
            }
        }
    }
}

void manageItem(int w, int h, int itemIndex)
{
    int selectedItem = 0;
    char buffer[30];

    system("cls");

    for(;;)
    {
        ResetConsoleSize(w, h);

        sprintf(buffer, "Manage %s", player.inventory[itemIndex].name);
        printCenterText(buffer, w, h, 0, -4);

        printCenterMenu(0, selectedItem, "Use", w, h, 0, -2);
        printCenterMenu(1, selectedItem, "Move", w, h, 0, -1);
        printCenterMenu(2, selectedItem, "Drop", w, h, 0, 0);

        printCenterMenu(3, selectedItem, "Back", w, h, 0, 2);

        if(menuInput(&selectedItem, 4) == 1)
        {
            if(selectedItem == 0)
            {

            } else if(selectedItem == 1)
            {
                if(moveItem(w, h, itemIndex))
                {
                    break;
                }
            } else if(selectedItem == 2)
            {
                if(dropItem(w, h, itemIndex))
                {
                    break;
                }
            } else // Quit
            {
                system("cls");
                return;
            }
        }
    }
}

void openInventory(int w, int h)
{
    int selectedItem = 0;
    char buffer[30];

    system("cls");

    for(;;)
    {
        ResetConsoleSize(w, h);

        printCenterText("Manage Inventory", w, h, 0, -8);

        for(int i = 0; i < 10; i++)
        {
            if(player.inventory[i].item_type == EMPTY)
                sprintf(buffer, "Empty");
            else
                sprintf(buffer, "%dx %s", player.inventory[i].item_count, player.inventory[i].name);

            printCenterMenu(i, selectedItem, buffer, w, h, 0, i-6);
        }

        printCenterMenu(10, selectedItem, "Back", w, h, 0, 5);

        if(menuInput(&selectedItem, 11) == 1)
        {
            if(selectedItem == 10)// Quit
            {
                system("cls");
                return;
            }

            if(player.inventory[selectedItem].item_type != EMPTY)
            {
                manageItem(w, h, selectedItem);
            }
        }
    }
}