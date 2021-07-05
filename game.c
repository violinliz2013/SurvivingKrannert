#include <gbalib.h>

int main() {

    //Backgrounds, Sprites, Gifs

    //Buttons, Sprite Movement

    //Bullet Movement, Bullet Collision
    int randomY = randomInteger(0, 159);
    Position bulletRespawn = {250, randomY};
    Position bullet1Pos = updatePosition(, bulletRespawn);
    Position bullet2Pos = updatePosition(, bulletRespawn);
    Position bullet3Pos = updatePosition(, bulletRespawn);
    Position bullet4Pos = updatePosition(, bulletRespawn);
    Position bullet5Pos = updatePosition(, bulletRespawn);
    while (true) {
        bullet1Pos = getPosition();
        bullet1Pos.x -= 1;
        updatePosition(, bullet1Pos);
        bullet2Pos = getPosition();
        bullet2Pos.x -= 1;
        updatePosition(, bullet2Pos);
        bullet3Pos = getPosition();
        bullet3Pos.x -= 1;
        updatePosition(, bullet3Pos);
        bullet4Pos = getPosition();
        bullet4Pos.x -= 1;
        updatePosition(, bullet4Pos);
        bullet5Pos = getPosition();
        bullet5Pos.x -= 1;
        updatePosition(, bullet5Pos);
        
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
    
}