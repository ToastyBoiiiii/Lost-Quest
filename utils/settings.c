#include <stdio.h>

#include "settings.h"

void saveSettings(int data[SAVE_AMOUNT])
{
    FILE *fp = fopen("data/settings/settings.data", "wb");

    fwrite(data, sizeof(int), SAVE_AMOUNT, fp);

    fclose(fp);
}

void loadSettings(int data[SAVE_AMOUNT])
{
    FILE *fp = fopen("data/settings/settings.data", "rb");

    fread(data, sizeof(int), SAVE_AMOUNT, fp);

    fclose(fp);
}