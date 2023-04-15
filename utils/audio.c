#include <windows.h>
#include <mmsystem.h>

#include "audio.h"

void playAudioFile(const char* fileName, int volume)
{
    // Play Sound
    PlaySound(TEXT(fileName), NULL, SND_ASYNC);

    // Adjust Volume(0% - 100%)
    HWAVEOUT hwo = NULL;
    waveOutGetID(NULL, (LPUINT) &hwo);
    DWORD newVolume = (0xFFFF / 100) * volume;
    waveOutSetVolume(hwo, newVolume);
}