#include <gbalib.h>
Sprite mike;
void startGame()
{
    Color krannertwall = createColor(252, 131, 67);
    Color black = createColor(0, 0, 0);
    Position mikeStart = {40, 80};
    Position startTextPos = {200, 20};
    Position origin = {0, 0};
    Size startTextSize = {40, 20};
    Size spriteSize = {32, 32};
    mike = createSprite("mikesprite", spriteSize);
    Background krannertHall = createBackground("krannertHall");
    drawBackground(krannertHall, origin);
    showSprite(mike);
    updatePosition(mike, mikeStart);
    drawText("Ready?", black, startTextPos);
    wait(1.5);
    drawFilledRectangle(krannertwall, startTextPos, startTextSize);
    wait(0.5);
    drawText("3", black, startTextPos);
    wait(0.5);
    drawFilledRectangle(krannertwall, startTextPos, startTextSize);
    wait(0.5);
    drawText("2", black, startTextPos);
    wait(0.5);
    drawFilledRectangle(krannertwall, startTextPos, startTextSize);
    wait(0.5);
    drawText("1", black, startTextPos);
    wait(0.5);
    drawFilledRectangle(krannertwall, startTextPos, startTextSize);
    wait(0.5);
    drawText("Go!", black, startTextPos);
    wait(0.5);
    bool gaming = true;
    drawFilledRectangle(krannertwall, startTextPos, startTextSize);
}
int main()
{
    while (true)
    {//Sound
    Sound music = createSound("oldvideogamemusic");
    playSound(music, true);

    //Backgrounds, Sprites, Gifs, Colors
    Position origin = {0, 0};
    Position text1Pos = {110, 20};
    Position text2Pos = {40, 140};
    Position box1Pos = {105, 15};
    Position box2Pos = {35, 135};
    Position ts1Pos = {60, 20};
    Position ts2Pos = {65, 140};
    int randomY = randomInteger(0, 120);
    Position bulletRespawn = {250, randomY};
    Position cherryPos = bulletRespawn;
    Position chiliPos = bulletRespawn;
    Position plumPos = bulletRespawn;
    Position carrotPos = bulletRespawn;
    Position watermelonPos = bulletRespawn;
    Size spriteSize = {32, 32};
    Size box1Size = {30, 17};
    Size box2Size = {170, 17};
    Size text1Size = {200, 17};
    Sprite mike;
    Sprite cherry = createSprite("realcherry", spriteSize);
    Sprite chili = createSprite("realchili", spriteSize);
    Sprite plum = createSprite("plum", spriteSize);
    Sprite carrot = createSprite("realcarrot", spriteSize);
    Sprite watermelon = createSprite("watermelon", spriteSize);
    Background krannertHall = createBackground("krannerthall");
    Background losescreen = createBackground("losescreen");
    Background pausescreen = createBackground("pausescreen");
    Background titlescreen = createBackground("titlescreen");
    Background winscreen = createBackground("winscreen");
    Color white = createColor(255, 255, 255);
    Color black = createColor(0, 0, 0);
    bool cherryCollision = false;

    //TitleScreen
    drawBackground(titlescreen, origin);
    wait(2);
    animateTextSlow("Surviving Krannert", black, ts1Pos, text1Size);
    wait(2);
    animateTextSlow("Press B to begin", black, ts2Pos, text1Size);
    bool wasBPressed = false;
    bool gaming = false;
    if (wasBPressed == false)
    {
        wasBPressed = isButtonDown(B);
        updateScreen();
        if (wasBPressed == true)
        {
            startGame();
        }
    }

    //Buttons, Sprite Movement
    Position mikePos = {40, 80};
    bool isUpPressed = false;
    bool isDownPressed = false;
<<<<<<< HEAD
    if (gaming == true)
=======
    while (true)
>>>>>>> 5a20f9db45f6294a9ea9dc6e49c58916f68f1207
    {
        isUpPressed = isButtonDown(UP);
        isDownPressed = isButtonDown(DOWN);
        if (isUpPressed == true)
        {
            Position mikePos = getPosition(mike);
            mikePos.y -= 1;
            updatePosition(mike, mikePos);
        }
        if (isDownPressed == true)
        {
            Position mikePos = getPosition(mike);
            mikePos.y += 1;
            updatePosition(mike, mikePos);
        }
        int randomRespawn = randomInteger(0, 120);
        Position bulletRespawn = {250, randomRespawn};
        showSprite(cherry);
        cherryPos = getPosition(cherry);
        cherryPos.x -= 2;
        updatePosition(cherry, cherryPos);
        if (cherryPos.x <= -20)
        {
            updatePosition(cherry, bulletRespawn);
        }
        cherryCollision = checkCollisionSprite(mike, cherry);
        if (cherryCollision == true)
        {
            hideSprite(cherry);
            updatePosition(cherry, bulletRespawn);
            showSprite(cherry);
        }
        updateScreen();
    }

    //Bullet Movement, Bullet Collision
    

<<<<<<< HEAD
    if (true) {
=======
    /*while (true) {
>>>>>>> 5a20f9db45f6294a9ea9dc6e49c58916f68f1207
        int randomRespawn = randomInteger(0, 120);
        Sprite cherry;
        Position bulletRespawn = {200, randomRespawn};
        showSprite(cherry);
        cherryPos = getPosition(cherry);
        cherryPos.x -= 2;
        updatePosition(cherry, cherryPos);
        if (cherryPos.x <= -20)
        {
            updatePosition(cherry, bulletRespawn);
        }
        updateScreen();
    }*/

    /*while (gaming == true)
    {
        cherryPos = getPosition(cherry);
        cherryPos.x -= 5;
        updatePosition(cherry, cherryPos);
        chiliPos = getPosition(chili);
        chiliPos.x -= 5;
        updatePosition(chili, chiliPos);
        plumPos = getPosition(plum);
        plumPos.x -= 5;
        updatePosition(plum, plumPos);
        carrotPos = getPosition(carrot);
        carrotPos.x -= 5;
        updatePosition(carrot, carrotPos);
        watermelonPos = getPosition(watermelon);
        watermelonPos.x -= 5;
        updatePosition(watermelon, watermelonPos);
        updateScreen();
    }*/

    /*bool cherryCollision = checkCollisionSprite(mike, cherry);
    bool chiliCollision = checkCollisionSprite(mike, chili);
    bool plumCollision = checkCollisionSprite(mike, plum);
    bool carrotCollision = checkCollisionSprite(mike, carrot);
    bool watermelonCollision = checkCollisionSprite(mike, watermelon);
    if (gaming == true)
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
        if (plumCollision == true)
        {
            hideSprite(plum);
            updatePosition(plum, bulletRespawn);
            wait(1);
            showSprite(plum);
        }
        if (carrotCollision == true)
        {
            hideSprite(carrot);
            updatePosition(carrot, bulletRespawn);
            wait(1);
            showSprite(carrot);
        }
        if (watermelonCollision == true)
        {
            hideSprite(watermelon);
            updatePosition(watermelon, bulletRespawn);
            wait(1);
            showSprite(watermelon);
        }
        updateScreen();
    }

    if (gaming == true)
    {
        if (cherryPos.x <= -40)
        {
            updatePosition(cherry, bulletRespawn);
        }
        if (chiliPos.x <= -40)
        {
            updatePosition(chili, bulletRespawn);
        }
        if (plumPos.x <= -40)
        {
            updatePosition(plum, bulletRespawn);
        }
        if (carrotPos.x <= -40)
        {
            updatePosition(carrot, bulletRespawn);
        }
        if (watermelonPos.x <= -40)
        {
            updatePosition(watermelon, bulletRespawn);
        }
    }*/

    //Health and Lose Screen
    /*bool wasAPressed = isButtonDown(A);
    int health = 5;
    if (cherryCollision == true || cherryCollision == true || plumCollision == true || carrotCollision == true || watermelonCollision == true)
    {
        health -= 1;
    }
    if (health <= 0)
    {
        gaming = false;
        drawBackground(losescreen, origin);
        drawFilledRectangle(black, box1Pos, box1Size);
        drawFilledRectangle(black, box2Pos, box2Size);
        drawHollowRectangle(white, box1Pos, box1Size);
        drawHollowRectangle(white, box2Pos, box2Size);
        drawText("FAILED", white, text1Pos);
        drawText("Press A to start again", white, text2Pos);
        if (wasAPressed == true)
        {
            gaming = true;
            startGame();
        }
    }*/
    wait(59.5);
    gaming = false;

    //Win
}
}
    