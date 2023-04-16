#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "audio.h"
#include "windowsFunctions.h"
#include "utils.h"

#include "../menu/options.h"

boolean randomChance(int chance, int max_num)
{
    if(rand()%max_num > chance)
    {
        return FALSE;
    } else
    {
        return TRUE;
    }
}

void slowPrint(int time, const char *string)
{
    for(int i = 0; string[i] == '\0'; i++)
    {
        printf("%c", string[i]);
        if(!kbhit())
        {
            Sleep(time);
        }
    }
    getch();
}

void printSpaces(int spaces)
{
    int x, y;
    getXY(&x, &y);

    gotoXY(spaces, y);
}

void printSpacesAndText(int spaces, char *str)
{
    printSpaces(spaces);
    printf("%s", str);
}

void printMessage(char *message, int w, int h, int sleepTime)
{
    system("cls");
    gotoXY(w / 2 - strlen(message) / 2, h / 2);
    printf("%s", message);
    Sleep(sleepTime);
}

void printCenterText(char *str, int w, int h, int offsetX, int offsetY)
{
    gotoXY(w/2+offsetX-strlen(str)/2, h/2+offsetY);
    printf("%s\n", str);
}

void printMenu(int menuItem, int selectedItem, char *str, int x, int y)
{
    gotoXY(x, y);

    if(selectedItem == menuItem)
    {
        setColor(BLACK, WHITE);
    }

    printf("%c %s %c\n", 174, str, 175);

    resetColor();
}

void printCenterMenu(int menuItem, int selectedItem, char *str, int w, int h, int offsetX, int offsetY)
{
    gotoXY(w/2+offsetX-(strlen(str)+4)/2, h/2+offsetY);

    if(selectedItem == menuItem)
    {
        setColor(BLACK, WHITE);
    }

    printf("%c %s %c\n", 174, str, 175);

    resetColor();
}

int menuInput2(int *selectedItem, int menuLength, int *keyCode)
{
    if(kbhit())
    {
        playAudioFile("click.wav", (int)((float)soundAudio.VALUE / 100 * (float)generalAudio.VALUE));

        int key = getch();

        if(keyCode != NULL)
        {
            *keyCode = key;
        }

        if(key == 'w' || key == 'W') // Navigation Up
        {
            if((*selectedItem) > 0)
            {
                (*selectedItem)--;
            } else
            {
                (*selectedItem) = menuLength-1;
            }
        } else if(key == 's' || key == 'S' || key == '\t') // Navigate Down
        {
            if((*selectedItem) < menuLength-1)
            {
                (*selectedItem)++;
            } else
            {
                (*selectedItem) = 0;
            }
        } else if(key >= 48 && key <= 57) // Hotkeys
        {
            int num = key-48;

            if(num == 0)
            {
                if(menuLength >= 10)
                {
                    (*selectedItem) = 9;
                }
            } else
            {
                if(menuLength >= num)
                {
                    (*selectedItem) = num-1;
                }
            }
        } else if(key == 224) // Arrow Keys
        {
            key = getch();
            switch (key)
	        {
                case 72: // Arrow Up
                    if((*selectedItem) > 0)
                    {
                        (*selectedItem)--;
                    } else
                    {
                        (*selectedItem) = menuLength-1;
                    }

                    if(keyCode != NULL)
                    {
                        *keyCode = -5;
                    }
                    break;
                case 80: // Arrow Down
                    if((*selectedItem) < menuLength-1)
                    {
                        (*selectedItem)++;
                    } else
                    {
                        (*selectedItem) = 0;
                    }

                    if(keyCode != NULL)
                    {
                        *keyCode = -4;
                    }
                    break;
                case 75: // Arrow Left
                    if(keyCode != NULL)
                    {
                        *keyCode = -3;
                    }
                    return LEFT;
                case 77: // Arrow Right
                    if(keyCode != NULL)
                    {
                        *keyCode = -2;
                    }
                    return RIGHT;
            }
        } else if(key == 'a' || key == 'A') // Slider Left
        {
            return LEFT;
        } else if(key == 'd' || key == 'D') // Slider Right
        {
            return RIGHT;
        }else if(key == ' ' || key == '\r') // Option Selected
        {
            return TRUE;
        }
    } else if(keyCode != NULL)
    {
        *keyCode = -1;
    }

    return FALSE;
}

void handleSlider(SLIDER *slider, int menuResult)
{
    if(menuResult == LEFT)
    {
        if(slider->VALUE - slider->STEP_SIZE >= slider->MIN_VALUE)
        {
            slider->VALUE -= slider->STEP_SIZE;
        }
    } else
    {
        if(slider->VALUE + slider->STEP_SIZE <= slider->MAX_VALUE)
        {
            slider->VALUE += slider->STEP_SIZE;
        }
    }
}

void removeSliderExcess(int excess, int length, int offsetY, int w, int h)
{
    gotoXY(w/2-length/2-excess, h/2+offsetY);

    for(int i = 0; i < excess; i++)
    {
        printf(" ");
    }

    gotoXY(w/2-length/2+length, h/2+offsetY);

    for(int i = 0; i < excess; i++)
    {
        printf(" ");
    }
}