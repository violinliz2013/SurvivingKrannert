#include <gbalib.h>

int main() {

    //Backgrounds, Sprites, Gifs
    Size spriteSize = {16, 16};
    Sprite cherry = createSprite("cherrySprite", spriteSize);
    Sprite chili = createSprite("chiliSprite", spriteSize);
    
    //Buttons, Sprite Movement
    Position protagonistPos = {};
    bool isUpPressed = isButtonDown(UP);
    bool isDownPressed = isButtonDown(DOWN);
    while (true) {
        if (isUpPressed == true) {
            protagonistPos = getPosition();
            protagonistPos.y -= 1;
            updatePosition(, protagonistPos);
        }
        if (isDownPressed == true); {
            protagonistPos = getPosition();
            protagonistPos.y += 1;
            updatePosition(, protagonistPos);
        }
        updateScreen();
    }
    //Bullet Movement, Bullet Collision
    int randomY = randomInteger(0, 159);
    Position bulletRespawn = {250, randomY};
    Position cherryPos = updatePosition(cherry, bulletRespawn);
    Position chiliPos = updatePosition(chili, bulletRespawn);
    Position bullet3Pos = updatePosition(, bulletRespawn);
    Position bullet4Pos = updatePosition(, bulletRespawn);
    Position bullet5Pos = updatePosition(, bulletRespawn);
    while (true) {
        cherryPos = getPosition(cherry);
        cherryPos.x -= 1;
        updatePosition(cherry, cherryPos);
        chiliPos = getPosition(chili);
        chiliPos.x -= 1;
        updatePosition(chili, chiliPos);
        bullet3Pos = getPosition();
        bullet3Pos.x -= 1;
        updatePosition(, bullet3Pos);
        bullet4Pos = getPosition();
        bullet4Pos.x -= 1;
        updatePosition(, bullet4Pos);
        bullet5Pos = getPosition();
        bullet5Pos.x -= 1;
        updatePosition(, bullet5Pos);
        
        bool bulletCollision1 = checkCollisionSprite(, cherry);
        if (bulletCollision1 == true) {
            hideSprite(cherry);
            wait(1);
            showSprite(cherry);
            updatePosition(cherry, bulletRespawn);
            updateScreen();
        }
        bool bulletCollision2 = checkCollisionSprite(chili);
        if (bulletCollision2 == true) {
            hideSprite(chili);
            wait(1);
            showSprite(chili);
            updatePosition(chili, bulletRespawn);
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