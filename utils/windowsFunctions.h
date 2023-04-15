#ifndef LOSTQUEST_WINDOWSFUNCTIONS_H
#define LOSTQUEST_WINDOWSFUNCTIONS_H

#define BLACK 0
#define DARK_BLUE 1
#define DARK_GREEN 2
#define DARK_CYAN 3
#define DARK_RED 4
#define DARK_PINK 5
#define DARK_YELLOW 6
#define DARK_WHITE 7
#define DARK_GRAY 8
#define BLUE 9
#define GREEN 10
#define CYAN 11
#define RED 12
#define PINK 13
#define YELLOW 14
#define WHITE 15

void gotoXY(unsigned x, unsigned y);
void getXY(int *x, int *y);
void setColor(int front_color, int background_color);
void resetColor();
void hideCursor();
void showCursor();
void SetConsoleWindowSize(int width, int height);
void GetConsoleWindowSize(int* width, int* height);
void RemoveConsoleScrollbars();
void ResetConsoleSize(int w, int h);
void DisableMaximizeButton();
void EnableMaximizeButton();
void DisableF11ForFullscreen();

#endif //LOSTQUEST_WINDOWSFUNCTIONS_H