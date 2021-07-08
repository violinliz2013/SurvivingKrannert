#include "sound.h"
#include "AAS_Data.h"

// This is cursed. I apologize

#define NUM_SOUNDS 1 + 0

static Sound sounds[NUM_SOUNDS];
static int curr_sound = 0;

static void addSound(const char *mem_start, const char *mem_end, char *sound_name) {
    sounds[curr_sound].mem_start = mem_start;
    sounds[curr_sound].mem_end = mem_end;
    sounds[curr_sound].sound_name = sound_name;
    curr_sound++;
}

void populateSounds() {
     addSound(AAS_DATA_SFX_START_oldvideogamemusic, AAS_DATA_SFX_END_oldvideogamemusic, "oldvideogamemusic");

}

Sound getSound(char *sound_name) {
    for (int i = 0; i < NUM_SOUNDS; i++) {
        if (!strcmp(sounds[i].sound_name, sound_name)) {
            return sounds[i];
        }
    }
    //TODO: exit angrily
    return sounds[0];
}