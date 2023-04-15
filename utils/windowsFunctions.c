#include <windows.h>
#include <stdio.h>
#include <conio.h>

#include "windowsFunctions.h"

void gotoXY(unsigned x, unsigned y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){(short)x, (short)y});
}

void getXY(int *x, int *y)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        *x = csbi.dwCursorPosition.X;
        *y = csbi.dwCursorPosition.Y;
    }
}

void setColor(int front_color, int background_color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, background_color * 16 + front_color);
}

void resetColor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BLACK * 16 + DARK_WHITE);
}

void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void showCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void SetConsoleWindowSize(int width, int height)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size = {(short)width, (short)height};
    SMALL_RECT rect = {0, 0, (short)(width - 1), (short)(height - 1)};

    SetConsoleScreenBufferSize(hConsole, size);
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
}

void GetConsoleWindowSize(int* width, int* height)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;

    GetConsoleScreenBufferInfo(hConsole, &info);
    *width = info.srWindow.Right - info.srWindow.Left + 1;
    *height = info.srWindow.Bottom - info.srWindow.Top + 1;
}

void RemoveConsoleScrollbars()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFOEX info;
    info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    GetConsoleScreenBufferInfoEx(hConsole, &info);

    COORD size = { (short)(info.srWindow.Right - info.srWindow.Left + 1), (short)(info.srWindow.Bottom - info.srWindow.Top + 1)};
    SetConsoleScreenBufferSize(hConsole, size);

    SMALL_RECT rect = { 0, 0, (short)(size.X - 1), (short)(size.Y - 1)};
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
}

void ResetConsoleSize(int w, int h)
{
    int tw, th;
    GetConsoleWindowSize(&tw, &th);
    if(tw != w || th != h)
    {
        SetConsoleWindowSize(w, h);
        RemoveConsoleScrollbars();
        hideCursor();
        system("cls");
    }
}

void DisableMaximizeButton()
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, FALSE);

    DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
}

void EnableMaximizeButton()
{
    HMENU hMenu = GetSystemMenu(GetConsoleWindow(), FALSE);

    EnableMenuItem(hMenu, SC_MAXIMIZE, MF_BYCOMMAND | MF_ENABLED);
}

BOOL IsConsoleActiveWindow()
{
    HWND hWnd = GetForegroundWindow();
    HWND hConsoleWnd = GetConsoleWindow();
    return (hWnd == hConsoleWnd);
}

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode == HC_ACTION)
    {
        KBDLLHOOKSTRUCT* pKey = (KBDLLHOOKSTRUCT*)lParam;
        if (pKey->vkCode == VK_F11 && IsConsoleActiveWindow())
        {
            return 1;
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

DWORD WINAPI KeyboardThread(LPVOID lpParameter)
{
    UNREFERENCED_PARAMETER(lpParameter);

    HHOOK hHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);
    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hHook);

    return 0;
}

void DisableF11ForFullscreen()
{
    HANDLE hThread = CreateThread(NULL, 0, KeyboardThread, NULL, 0, NULL);
    CloseHandle(hThread);
}