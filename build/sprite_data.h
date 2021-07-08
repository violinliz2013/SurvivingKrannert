/*
 * Exported with nin10kit v1.8
 * Invocation command was nin10kit --mode=sprites --bpp=8 --for_bitmap --transparent=FF00FF ./build/sprite_data ./sprites/realchili.png ./sprites/mikesprite.png ./sprites/realcherry.png ./sprites/bob.png ./sprites/watermelon.png ./sprites/plum.png ./sprites/realcarrot.png 
 * Time-stamp: Thursday 07/08/2021, 15:27:17
 * 
 * Image Information
 * -----------------
 * ./sprites/realchili.png 32@32
 * ./sprites/mikesprite.png 32@32
 * ./sprites/realcherry.png 32@32
 * ./sprites/bob.png 16@16
 * ./sprites/watermelon.png 32@32
 * ./sprites/plum.png 32@32
 * ./sprites/realcarrot.png 32@32
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

extern const unsigned short sprite_data[3200];
#define SPRITE_DATA_SIZE 6400
#define SPRITE_DATA_LENGTH 3200

#define REALCHILI_PALETTE_ID (0 << 12)
#define REALCHILI_SPRITE_SHAPE (0 << 14)
#define REALCHILI_SPRITE_SIZE (2 << 14)
#define REALCHILI_ID 512

#define MIKESPRITE_PALETTE_ID (0 << 12)
#define MIKESPRITE_SPRITE_SHAPE (0 << 14)
#define MIKESPRITE_SPRITE_SIZE (2 << 14)
#define MIKESPRITE_ID 544

#define REALCHERRY_PALETTE_ID (0 << 12)
#define REALCHERRY_SPRITE_SHAPE (0 << 14)
#define REALCHERRY_SPRITE_SIZE (2 << 14)
#define REALCHERRY_ID 576

#define BOB_PALETTE_ID (0 << 12)
#define BOB_SPRITE_SHAPE (0 << 14)
#define BOB_SPRITE_SIZE (1 << 14)
#define BOB_ID 608

#define WATERMELON_PALETTE_ID (0 << 12)
#define WATERMELON_SPRITE_SHAPE (0 << 14)
#define WATERMELON_SPRITE_SIZE (2 << 14)
#define WATERMELON_ID 616

#define PLUM_PALETTE_ID (0 << 12)
#define PLUM_SPRITE_SHAPE (0 << 14)
#define PLUM_SPRITE_SIZE (2 << 14)
#define PLUM_ID 648

#define REALCARROT_PALETTE_ID (0 << 12)
#define REALCARROT_SPRITE_SHAPE (0 << 14)
#define REALCARROT_SPRITE_SIZE (2 << 14)
#define REALCARROT_ID 680

#endif

