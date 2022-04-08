#include <audio.h>

Music music = {0};

void InitAudio(void){
    InitAudioDevice();
    music = LoadMusicStream("assets/test.wav");
    PlayMusicStream(music);
}

void UpdateAudio(void){
    UpdateMusicStream(music);
}