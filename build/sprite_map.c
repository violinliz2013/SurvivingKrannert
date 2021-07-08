#include "sprite.h"
#include "sprite_data.h"

// This is cursed. I apologize

#define NUM_SPRITES 7

ObjAttr sprite_list[128]; // max 128 sprites
static ObjAttrImageInfo images[NUM_SPRITES];
static int curr_image = 0;

static void addImage(u16 palette_id, u16 shape, u16 size, u16 id, char *image_name) {
    images[curr_image].palette_id = palette_id;
    images[curr_image].shape = shape;
    images[curr_image].size = size;
    images[curr_image].id = id;
    images[curr_image].image_name = image_name;

    curr_image++;
}

void populateSpriteImages() {
     addImage(REALCHILI_PALETTE_ID, REALCHILI_SPRITE_SHAPE, REALCHILI_SPRITE_SIZE, REALCHILI_ID, "REALCHILI");
  addImage(MIKESPRITE_PALETTE_ID, MIKESPRITE_SPRITE_SHAPE, MIKESPRITE_SPRITE_SIZE, MIKESPRITE_ID, "MIKESPRITE");
  addImage(REALCHERRY_PALETTE_ID, REALCHERRY_SPRITE_SHAPE, REALCHERRY_SPRITE_SIZE, REALCHERRY_ID, "REALCHERRY");
  addImage(BOB_PALETTE_ID, BOB_SPRITE_SHAPE, BOB_SPRITE_SIZE, BOB_ID, "BOB");
  addImage(WATERMELON_PALETTE_ID, WATERMELON_SPRITE_SHAPE, WATERMELON_SPRITE_SIZE, WATERMELON_ID, "WATERMELON");
  addImage(PLUM_PALETTE_ID, PLUM_SPRITE_SHAPE, PLUM_SPRITE_SIZE, PLUM_ID, "PLUM");
  addImage(REALCARROT_PALETTE_ID, REALCARROT_SPRITE_SHAPE, REALCARROT_SPRITE_SIZE, REALCARROT_ID, "REALCARROT");

}

SpriteInfo getSpriteInfo() {
    return (SpriteInfo) {SPRITE_DATA_PALETTE_TYPE, SPRITE_DATA_DIMENSION_TYPE, SPRITE_DATA_PALETTE_LENGTH, SPRITE_DATA_LENGTH};
}

ObjAttrImageInfo *getObjAttrImageInfo(char *image_name) {
    int len = strlen(image_name);
    char upper_img_name[len + 1];
    for (int i = 0; i < len; i++) {
        upper_img_name[i] = toupper(image_name[i]);
    }
    upper_img_name[len] = '\0';
    for (int i = 0; i < NUM_SPRITES; i++) {
        if (!strcmp(images[i].image_name, upper_img_name)) {
            return &images[i];
        }
    }
    //TODO: exit angrily
    return &images[0];
}