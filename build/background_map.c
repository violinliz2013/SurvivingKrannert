#include "background.h"
#include "background_data.h"

// This is cursed. I apologize

#define NUM_BACKGROUNDS 5

static Background backgrounds[NUM_BACKGROUNDS];
static int curr_image = 0;

static void addImage(u32 width, u32 height, char *image_name) {
    Size size = {width, height};
    backgrounds[curr_image].size = size;
    backgrounds[curr_image].image_name = image_name;

    curr_image++;
}

static void addImageData(const u16 *background_data) {
    backgrounds[curr_image].background_data = background_data;
    curr_image++;
}

void populateBackgrounds() {
     addImage(TITLESCREEN_WIDTH, TITLESCREEN_HEIGHT, "TITLESCREEN");
  addImage(PAUSESCREEN_WIDTH, PAUSESCREEN_HEIGHT, "PAUSESCREEN");
  addImage(KRANNERTHALL_WIDTH, KRANNERTHALL_HEIGHT, "KRANNERTHALL");
  addImage(LOSESCREEN_WIDTH, LOSESCREEN_HEIGHT, "LOSESCREEN");
  addImage(WINSCREEN_WIDTH, WINSCREEN_HEIGHT, "WINSCREEN");

    curr_image = 0;
     addImageData(titlescreen);
  addImageData(pausescreen);
  addImageData(krannerthall);
  addImageData(losescreen);
  addImageData(winscreen);

}

Background getBackground(char *image_name) {
    int len = strlen(image_name);
    char upper_img_name[len + 1];
    for (int i = 0; i < len; i++) {
        upper_img_name[i] = toupper(image_name[i]);
    }
    upper_img_name[len] = '\0';
    for (int i = 0; i < NUM_BACKGROUNDS; i++) {
        if (!strcmp(backgrounds[i].image_name, upper_img_name)) {
            return backgrounds[i];
        }
    }
    //TODO: exit angrily
    return backgrounds[1];
}