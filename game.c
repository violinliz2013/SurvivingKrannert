#include <gbalib.h>

int main() {

    //Backgrounds, Sprites, Gifs
    Position origin = {0, 0};
    Size spriteSize = {16, 16};
    Sprite cherry = createSprite("cherrySprite", spriteSize);
    Sprite chili = createSprite("chiliSprite", spriteSize);
    
    //Buttons, Sprite Movement
    Position protagonistPos = {};
    bool isUpPressed = isButtonDown(UP);
    bool isDownPressed = isButtonDown(DOWN);
    bool gameStop = isSpriteHidden();
    while (gameStop == false) {
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
    int randomY = randomInteger(0, 120);
    Position bulletRespawn = {250, randomY};
    Position cherryPos = updatePosition(cherry, bulletRespawn);
    Position chiliPos = updatePosition(chili, bulletRespawn);
    Position bullet3Pos = updatePosition(, bulletRespawn);
    Position bullet4Pos = updatePosition(, bulletRespawn);
    Position bullet5Pos = updatePosition(, bulletRespawn);
    
    while (gameStop == false) {
        cherryPos = getPosition(cherry);
        cherryPos.x -= 5;
        updatePosition(cherry, cherryPos);
        chiliPos = getPosition(chili);
        chiliPos.x -= 5;
        updatePosition(chili, chiliPos);
        bullet3Pos = getPosition();
        bullet3Pos.x -= 5;
        updatePosition(, bullet3Pos);
        bullet4Pos = getPosition();
        bullet4Pos.x -= 5;
        updatePosition(, bullet4Pos);
        bullet5Pos = getPosition();
        bullet5Pos.x -= 5;
        updatePosition(, bullet5Pos);
        updateScreen();
    }
    
    bool bulletCollision1 = checkCollisionSprite(, cherry);
    while (gameStop == false) {
        if (bulletCollision1 == true) {
            hideSprite(cherry);
            wait(1);
            showSprite(cherry);
            updatePosition(cherry, bulletRespawn);
        }
        bool bulletCollision2 = checkCollisionSprite(chili);
        if (bulletCollision2 == true) {
            hideSprite(chili);
            wait(1);
            showSprite(chili);
            updatePosition(chili, bulletRespawn);
        }
        bool bulletCollision3 = checkCollisionSprite();
        if (bulletCollision3 == true) {
            hideSprite();
            wait(1);
            showSprite();
            updatePosition(, bulletRespawn);
        }
        bool bulletCollision4 = checkCollisionSprite();
        if (bulletCollision4 == true) {
            hideSprite();
            wait(1);
            showSprite();
            updatePosition(, bulletRespawn);
        }
        bool bulletCollision5 = checkCollisionSprite();
        if (bulletCollision5 == true) {
            hideSprite();
            wait(1);
            showSprite();
            updatePosition(, bulletRespawn);
        }
        updateScreen();
    }

    while (gameStop == false) {
        if (cherryPos.x <= -40) {
            updatePosition(cherry, bulletRespawn);
        }
        if (chiliPos.x <= -40) {
            updatePosition(chili, bulletRespawn);
        }
        if (bullet3Pos.x <= -40) {
            updatePosition(, bulletRespawn);
        }
        if (bullet4Pos.x <= -40) {
            updatePosition(, bulletRespawn);
        }
        if (bullet5Pos.x <= -40) {
            updatePosition(, bulletRespawn);
        }
    }
    //Pause Menu Code
    bool isStartPressed = wasButtonPressed(START);
    if (isStartPressed == true) {
        drawBackground(, origin);
        hideSprite();

    }
}