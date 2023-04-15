#include <stdio.h>
#include <conio.h>

#include "../utils/windowsFunctions.h"
#include "../utils/utils.h"

#include "../game/dungeon.h"
#include "../game/player.h"

void map(int w, int h)
{
    system("cls");

    // Color Explanation
    printf("\n  ");

    setColor(BLACK, DARK_PINK);
    printf("  ");
    resetColor();
    printf(" - Player\n\n  ");

    setColor(BLACK, DARK_YELLOW);
    printf("  ");
    resetColor();
    printf(" - Key\n\n  ");

    setColor(BLACK, DARK_RED);
    printf("  ");
    resetColor();
    printf(" - Exit\n\n");

    // Inputs
    gotoXY(0, h - 7);

    if(!(dungeon[player.room_x][player.room_y].north_door && (!dungeon[player.room_x][player.room_y-1].is_exit || player.has_key))) {setColor(DARK_GRAY, BLACK);}
    printf("  W - Move Upwards\n");
    resetColor();

    if(!(dungeon[player.room_x][player.room_y].west_door && (!dungeon[player.room_x-1][player.room_y].is_exit || player.has_key))) {setColor(DARK_GRAY, BLACK);}
    printf("  A - Move Left\n");
    resetColor();

    if(!(dungeon[player.room_x][player.room_y].south_door && (!dungeon[player.room_x][player.room_y+1].is_exit || player.has_key))) {setColor(DARK_GRAY, BLACK);}
    printf("  S - Move Downwards\n");
    resetColor();

    if(!(dungeon[player.room_x][player.room_y].east_door && (!dungeon[player.room_x+1][player.room_y].is_exit || player.has_key))) {setColor(DARK_GRAY, BLACK);}
    printf("  D - Move Right\n\n");
    resetColor();

    printf("  Enter - Back");

    for(int x = 0; x < DUNGEON_WIDTH; x++)
    {
        for(int y = 0; y < DUNGEON_HEIGHT; y++)
        {
            if(dungeon[x][y].visited || (y-1 >= 0 && dungeon[x][y-1].visited && dungeon[x][y].north_door) || (x+1 < DUNGEON_WIDTH && dungeon[x+1][y].visited && dungeon[x][y].east_door) || (y+1 < DUNGEON_HEIGHT && dungeon[x][y+1].visited && dungeon[x][y].south_door) || (x-1 >= 0 && dungeon[x-1][y].visited && dungeon[x][y].west_door))
            {
                // Top Column
                gotoXY(w/2 - DUNGEON_WIDTH*6/2 + x*6, h/2 - DUNGEON_HEIGHT*3/2 + y*3);

                printf("%c%c", 219, 223);

                if(dungeon[x][y].north_door)
                {
                    printf("%c%c", 32, 32);
                } else
                {
                    printf("%c%c", 223, 223);
                }

                printf("%c%c", 223, 219);

                // Middle Column
                gotoXY(w/2 - DUNGEON_WIDTH*6/2 + x*6, h/2 - DUNGEON_HEIGHT*3/2 + y*3+1);

                printf("%c ", (dungeon[x][y].west_door)?(32):(219));

                if(dungeon[x][y].is_exit)
                {
                    setColor(BLACK, DARK_RED);
                } else if(dungeon[x][y].has_key)
                {
                    setColor(BLACK, DARK_YELLOW);
                } else if(x == player.room_x && y == player.room_y)
                {
                    setColor(BLACK, DARK_PINK);
                }

                printf("  ");

                resetColor();

                printf(" %c", (dungeon[x][y].east_door)?(32):(219));

                // Bottom Column
                gotoXY(w/2 - DUNGEON_WIDTH*6/2 + x*6, h/2 - DUNGEON_HEIGHT*3/2 + y*3+2);

                printf("%c%c", 219, 220);

                if(dungeon[x][y].south_door)
                {
                    printf("%c%c", 32, 32);
                } else
                {
                    printf("%c%c", 220, 220);
                }

                printf("%c%c", 220, 219);
            }
        }
    }

    char key;

    for(;;)
    {
        key = getch();

        if(key == 'w' && dungeon[player.room_x][player.room_y].north_door && (!dungeon[player.room_x][player.room_y-1].is_exit || player.has_key))
        {
            player.room_y -= 1;
            break;
        } else if(key == 'a' && dungeon[player.room_x][player.room_y].west_door && (!dungeon[player.room_x-1][player.room_y].is_exit || player.has_key))
        {
            player.room_x -= 1;
            break;
        } else if(key == 's' && dungeon[player.room_x][player.room_y].south_door && (!dungeon[player.room_x][player.room_y+1].is_exit || player.has_key))
        {
            player.room_y += 1;
            break;
        } else if(key == 'd' && dungeon[player.room_x][player.room_y].east_door && (!dungeon[player.room_x+1][player.room_y].is_exit || player.has_key))
        {
            player.room_x += 1;
            break;
        } else if(key == '\r' || key == ' ')
        {
            break;
        }
    }

    dungeon[player.room_x][player.room_y].visited = TRUE;

    if(dungeon[player.room_x][player.room_y].has_key)
    {
        dungeon[player.room_x][player.room_y].has_key = FALSE;
        player.has_key = TRUE;

        printMessage("You found a Key", w, h, 1000);
    }

    if(dungeon[player.room_x][player.room_y].contains_monster)
    {
        // Initiate Combat
    }

    system("cls");
}