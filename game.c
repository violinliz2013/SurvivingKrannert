#include <gbalib.h>

int main() {
    // Sizes, Positions, Colors, Integers
    int randomY = randomInteger(0, 159);
    Position bulletRespawn = {250, randomY};

    //Backgrounds, Sprites, Gifs

    //button stuff

    //Collisions
    bool bulletCollision1 = checkCollisionSprite();
    if (bulletCollision1 == true) {
        hideSprite();
        wait(1);
        showSprite();
        updatePosition(, bulletRespawn);
        updateScreen();
    }
    bool bulletCollision2 = checkCollisionSprite();
    if (bulletCollision2 == true) {
        hideSprite();
        wait(1);
        showSprite();
        updatePosition(, bulletRespawn);
        updateScreen();
    }
    bool bulletCollision3 = checkCollisionSprite();
    if (bulletCollision3 == true) {
        hideSprite();
        wait(1);
        showSprite();
        updatePosition(, bulletRespawn);
        updateScreen();
    }
    bool bulletCollision4 = checkCollisionSprite();
    if (bulletCollision4 == true) {
        hideSprite();
        wait(1);
        showSprite();
        updatePosition(, bulletRespawn);
        updateScreen();
    }
    bool bulletCollision5 = checkCollisionSprite();
    if (bulletCollision5 == true) {
        hideSprite();
        wait(1);
        showSprite();
        updatePosition(, bulletRespawn);
        updateScreen();
    }
}