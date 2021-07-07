/*
 * Exported with nin10kit v1.8
 * Invocation command was nin10kit --mode=sprites --bpp=8 --for_bitmap --transparent=FF00FF ./build/sprite_data ./sprites/cherrySprite.png ./sprites/chiliSprite.png 
 * Time-stamp: Wednesday 07/07/2021, 15:37:04
 * 
 * Image Information
 * -----------------
 * ./sprites/cherrySprite.png 16@16
 * ./sprites/chiliSprite.png 16@16
 * Transparent color: (255, 0, 255)
 * 
 * All bug reports / feature requests are to be filed here https://github.com/TricksterGuy/nin10kit/issues
 */

#ifndef SPRITE_DATA_H
#define SPRITE_DATA_H

#define SPRITE_DATA_PALETTE_TYPE (1 << 13)
#define SPRITE_DATA_DIMENSION_TYPE (1 << 6)

extern const unsigned short sprite_data_palette[256];
#define SPRITE_DATA_PALETTE_SIZE 512
#define SPRITE_DATA_PALETTE_LENGTH 256

extern const unsigned short sprite_data[256];
#define SPRITE_DATA_SIZE 512
#define SPRITE_DATA_LENGTH 256

#define CHERRYSPRITE_PALETTE_ID (0 << 12)
#define CHERRYSPRITE_SPRITE_SHAPE (0 << 14)
#define CHERRYSPRITE_SPRITE_SIZE (1 << 14)
#define CHERRYSPRITE_ID 512

#define CHILISPRITE_PALETTE_ID (0 << 12)
#define CHILISPRITE_SPRITE_SHAPE (0 << 14)
#define CHILISPRITE_SPRITE_SIZE (1 << 14)
#define CHILISPRITE_ID 520

#endif

