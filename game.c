#include <gbalib.h>

int main()
{
    //Sound
    Sound music = createSound("oldvideogamemusic");
    playSOund(music, true);

    //Backgrounds, Sprites, Gifs, Colors
    Position origin = {0, 0};
    Position text1Pos = {110, 20};
    Position text2Pos = {40, 140};
    Position box1Pos = {105, 15};
    Position box2Pos = {35, 135};
    Position ts1Pos = {60, 20};
    Position ts2Pos = {65, 140};
    Size spriteSize = {16, 16};
    Size box1Size = {30, 17};
    Size box2Size = {170, 17};
    Size text1Size = {200, 17};
    Sprite cherry = createSprite("realcherry", spriteSize);
    Sprite chili = createSprite("realchili", spriteSize);
    Sprite plum = createSprite("plum");
    Sprite carrot = createSprite("realcarrot");
    Sprite watermelon = createSprite("watermelon");
    Sprite mike = createSprite("mikesprite");
    Sprite bob = createSprite("bob");
    Color white = createColor(255, 255, 255);
    Color black = createColor(0, 0, 0);

    //TitleScreen
    drawBackground("titleScreen", origin);
    wait(2);
    animateTextSlow("Surviving Krannert", black, ts1Pos, text1Size);
    wait(2);
    animateTextSlow("Press B to begin", black, ts2Pos, text1Size);

    //Buttons, Sprite Movement
    Position protagonistPos = {};
    bool isUpPressed = isButtonDown(UP);
    bool isDownPressed = isButtonDown(DOWN);
    bool gameStop = isSpriteHidden();
    while (gameStop == false)
    {
        if (isUpPressed == true)
        {
            protagonistPos = getPosition();
            protagonistPos.y -= 1;
            updatePosition(, protagonistPos);
        }
        if (isDownPressed == true)
            ;
        {
            protagonistPos = getPosition();
            protagonistPos.y += 1;
            updatePosition(, protagonistPos);
        }
        updateScreen();
    }

    //Bullet Movement, Bullet Collision
    int randomY = randomInteger(0, 120);
    Position bulletRespawn = {250, randomY};
    Position cherryPos = bulletRespawn;
    Position chiliPos = bulletRespawn;
    Position bullet3Pos = bulletRespawn;
    Position bullet4Pos = bulletRespawn;
    Position bullet5Pos = bulletRespawn;

    while (gameStop == false)
    {
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

    bool cherryCollision = checkCollisionSprite(, cherry);
    bool chiliCollision = checkCollisionSprite(, chili);
    bool bulletCollision3 = checkCollisionSprite();
    bool bulletCollision4 = checkCollisionSprite();
    bool bulletCollision5 = checkCollisionSprite();
    while (gameStop == false)
    {
        if (cherryCollision == true)
        {
            hideSprite(cherry);
            updatePosition(cherry, bulletRespawn);
            wait(1);
            showSprite(cherry);
        }
        if (chiliCollision == true)
        {
            hideSprite(chili);
            updatePosition(chili, bulletRespawn);
            wait(1);
            showSprite(chili);
        }
        if (bulletCollision3 == true)
        {
            hideSprite();
            updatePosition(, bulletRespawn);
            wait(1);
            showSprite();
        }
        if (bulletCollision4 == true)
        {
            hideSprite();
            updatePosition(, bulletRespawn);
            wait(1);
            showSprite();
        }
        if (bulletCollision5 == true)
        {
            hideSprite();
            updatePosition(, bulletRespawn);
            wait(1);
            showSprite();
        }
        updateScreen();
    }

    while (gameStop == false)
    {
        if (cherryPos.x <= -40)
        {
            updatePosition(cherry, bulletRespawn);
        }
        if (chiliPos.x <= -40)
        {
            updatePosition(chili, bulletRespawn);
        }
        if (bullet3Pos.x <= -40)
        {
            updatePosition(, bulletRespawn);
        }
        if (bullet4Pos.x <= -40)
        {
            updatePosition(, bulletRespawn);
        }
        if (bullet5Pos.x <= -40)
        {
            updatePosition(, bulletRespawn);
        }
    }

    //Health and Lose Screen
    bool wasAPressed = isButtonDown(A);
    int health = 5;
    if (cherryCollision == true || cherryCollision == true || bulletCollision3 == true || bulletCollision4 == true || bulletCollision5 == true)
    {
        health -= 1;
    }
    if (health <= 0)
    {
        gameStop = true;
        drawBackground("loseScreen", origin);
        drawFilledRectangle(black, box1Pos, box1Size);
        drawFilledRectangle(black, box2Pos, box2Size);
        drawHollowRectangle(white, box1Pos, box1Size);
        drawHollowRectangle(white, box2Pos, box2Size);
        drawText("FAILED", white, text1Pos);
        drawText("Press A to start again", white, text2Pos);
        if (wasAPressed == true) {

        }
    }
    //Pause Menu Code
    bool isStartPressed = wasButtonPressed(START);
    if (isStartPressed == true)
    {
        drawBackground(, origin);
        hideSprite();
    }
    //Win
}