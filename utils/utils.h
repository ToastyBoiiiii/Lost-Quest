#ifndef LOSTQUEST_UTILS_H
#define LOSTQUEST_UTILS_H

#include <windows.h>

#define LEFT 2
#define RIGHT 3

#define menuInput(selectedItem, menuLength) menuInput2(selectedItem, menuLength, NULL)

typedef struct
{
    int VALUE;
    int MIN_VALUE;
    int MAX_VALUE;
    int STEP_SIZE;
} SLIDER;

boolean randomChance(int chance, int max_num);
void slowPrint(int time, const char *string);
void printSpaces(int spaces);
void printSpacesAndText(int spaces, char *str);
void printMessage(char *message, int w, int h, int sleepTime);
void printCenterText(char *str, int w, int h, int offsetX, int offsetY);

void printMenu(int menuItem, int selectedItem, char *str, int x, int y);
void printCenterMenu(int menuItem, int selectedItem, char *str, int w, int h, int offsetX, int offsetY);
int menuInput2(int *selectedItem, int menuLength, int *keyCode);
void handleSlider(SLIDER *slider, int menuResult);
void removeSliderExcess(int excess, int length, int offsetY, int w, int h);

#endif //LOSTQUEST_UTILS_H