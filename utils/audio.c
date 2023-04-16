#include <string.h>
#include <windows.h>
#include <mmsystem.h>

#include "audio.h"

void playAudioFile(const char* rawFileName, int volume)
{
    char fileName[20];
    strncpy(fileName, "../sound/", 20);
    strncat(fileName, rawFileName, 20);

    // Play Sound
    PlaySound(TEXT(fileName), NULL, SND_ASYNC);

    // Adjust Volume(0% - 100%)
    HWAVEOUT hwo = NULL;
    waveOutGetID(NULL, (LPUINT) &hwo);
    DWORD newVolume = (0xFFFF / 100) * volume;
    waveOutSetVolume(hwo, newVolume);
}