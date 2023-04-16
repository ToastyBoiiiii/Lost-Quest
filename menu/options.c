#include <stdio.h>

#include "../utils/utils.h"
#include "../utils/windowsFunctions.h"

#include "options.h"
#include "cheats.h"

SLIDER difficulty = {1, 1, 3, 1};

SLIDER generalAudio = {100, 0, 100, 5};
SLIDER musicAudio = {100, 0, 100, 5};
SLIDER soundAudio = {100, 0, 100, 5};

void audioOptions(int w, int h)
{
    int result;
    int selectedItem = 0;

    char buffer[20];
    int length[3];

    system("cls");

    for(;;)
    {
        ResetConsoleSize(w, h);

        gotoXY(0, 0);
        printf("\n\n\n\n\n\n\n");
        printSpacesAndText(w/2-29/2, " _____     _   _\n");
        printSpacesAndText(w/2-29/2, "|     |___| |_|_|___ ___ ___\n");
        printSpacesAndText(w/2-29/2, "|  |  | . |  _| | . |   |_ -|\n");
        printSpacesAndText(w/2-29/2, "|_____|  _|_| |_|___|_|_|___|\n");
        printSpacesAndText(w/2-29/2, "      |_|\n");

        sprintf(buffer, "General: %d%%", generalAudio.VALUE);
        printCenterMenu(0, selectedItem, buffer, w, h, 0, 2);
        length[0] = strlen(buffer);

        sprintf(buffer, "Music: %d%%", musicAudio.VALUE);
        printCenterMenu(1, selectedItem, buffer, w, h, 0, 3);
        length[1] = strlen(buffer);

        sprintf(buffer, "Sound: %d%%", soundAudio.VALUE);
        printCenterMenu(2, selectedItem, buffer, w, h, 0, 4);
        length[2] = strlen(buffer);

        printCenterMenu(3, selectedItem, "Back", w, h, 0, 6);

        result = menuInput(&selectedItem, 4);
        if(result)
        {
            if(selectedItem == 0) // General Audio
            {
                handleSlider(&generalAudio, result);

                sprintf(buffer, "General: %d%%", generalAudio.VALUE);
                removeSliderExcess(1, strlen(buffer) + 4, 2, w, h);
            } else if(selectedItem == 1) // Music Audio
            {
                handleSlider(&musicAudio, result);

                sprintf(buffer, "Music: %d%%", musicAudio.VALUE);
                removeSliderExcess(1, strlen(buffer) + 4, 3, w, h);
            } else if(selectedItem == 2) // Sound Audio
            {
                handleSlider(&soundAudio, result);

                sprintf(buffer, "Sound: %d%%", soundAudio.VALUE);
                removeSliderExcess(1, strlen(buffer) + 4, 4, w, h);
            } else if(result == 1) // Back
            {
                system("cls");
                break;
            }
        }
    }
}

void options(int w, int h)
{
    int result;
    int selectedItem = 0;

    char buffer[20];

    int keyCodes[11] = {-5, -5, -4, -4, -3, -2, -3, -2, 'b', 'a', '\r'};
    int cheatProgress = 0;
    int key;

    system("cls");

    for(;;)
    {
        ResetConsoleSize(w, h);

        gotoXY(0, 0);
        printf("\n\n\n\n\n\n\n");
        printSpacesAndText(w/2-29/2, " _____     _   _\n");
        printSpacesAndText(w/2-29/2, "|     |___| |_|_|___ ___ ___\n");
        printSpacesAndText(w/2-29/2, "|  |  | . |  _| | . |   |_ -|\n");
        printSpacesAndText(w/2-29/2, "|_____|  _|_| |_|___|_|_|___|\n");
        printSpacesAndText(w/2-29/2, "      |_|\n");

        sprintf(buffer, "Difficulty: %s", (difficulty.VALUE != 3) ? ((difficulty.VALUE == 1) ? ("Easy") : ("Medium")) : ("Hard"));
        printCenterMenu(0, selectedItem, buffer, w, h, 0, 2);
        printCenterMenu(1, selectedItem, "Audio", w, h, 0, 3);
        printCenterMenu(2, selectedItem, "Back", w, h, 0, 5);

        result = menuInput2(&selectedItem, 3, &key);
        if(result)
        {
            if(selectedItem == 0) // Difficulty
            {
                handleSlider(&difficulty, result);

                sprintf(buffer, "Difficulty: %s", (difficulty.VALUE != 3) ? ((difficulty.VALUE == 1) ? ("Easy") : ("Medium")) : ("Hard"));
                removeSliderExcess(1, strlen(buffer) + 4, 2, w, h);
            } else if(selectedItem == 1 && result == 1) // Audio
            {
                audioOptions(w, h);
            } else if(result == 1) // Back
            {
                system("cls");
                break;
            }
        }

        if(cheatProgress == 11)
        {
            cheatMenu(w, h);
            cheatProgress = 0;
        }

        if(keyCodes[cheatProgress] == key)
        {
            cheatProgress++;
        } else if(key != -1)
        {
            cheatProgress = 0;
        }
    }
}