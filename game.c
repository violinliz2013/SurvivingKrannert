#include <gbalib.h>
void startGame() {
    Color krannertwall =createColor(252, 131, 67);
    Color black = createColor(0, 0, 0);
    Position mikeStart = {40, 80};
    Position startTextPos = {200, 20};
    Position origin = {0, 0};
    Size startTextSize = {30, 20};
    Size spriteSize = {32, 32};
    Sprite mike = createSprite ("mikesprite", spriteSize);
    drawBackground("krannerthall", origin);
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
    drawFilledRectangle(krannertwall, startTextPos, startTextSize);
}
int main()
{
    //Sound
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
    Size spriteSize = {32, 32};
    Size box1Size = {30, 17};
    Size box2Size = {170, 17};
    Size text1Size = {200, 17};
    Sprite mike = createSprite ("mikesprite", spriteSize);
    Sprite cherry = createSprite("realcherry", spriteSize);
    Sprite chili = createSprite("realchili", spriteSize);
    Sprite plum = createSprite("plum", spriteSize);
    Sprite carrot = createSprite("realcarrot", spriteSize);
    Sprite watermelon = createSprite("watermelon", spriteSize);
    Color white = createColor(255, 255, 255);
    Color black = createColor(0, 0, 0);

    //TitleScreen
    drawBackground("titlescreen", origin);
    wait(2);
    animateTextSlow("Surviving Krannert", black, ts1Pos, text1Size);
    wait(2);
    animateTextSlow("Press B to begin", black, ts2Pos, text1Size);
    bool wasBPressed = isButtonDown(B);
    if (wasBPressed == true) {
        startGame();
<<<<<<< HEAD
        wait(59.5);
        winGame = true;
=======
        wait(60);
>>>>>>> e0c77b4e734dc2ecdfeb6af5c46ad59b0950f0c2
    }

    //Buttons, Sprite Movement
    Position mikePos = {40, 80};
    bool isUpPressed = isButtonDown(UP);
    bool isDownPressed = isButtonDown(DOWN);
    bool gameStop = isSpriteHidden(mike);
    while (gameStop == false)
    {
        if (isUpPressed == true)
        {
            mikePos = getPosition(mike);
            mikePos.y -= 1;
            updatePosition(mike, mikePos);
        }
        if (isDownPressed == true)
            ;
        {
            mikePos = getPosition(mike);
            mikePos.y += 1;
            updatePosition(mike, mikePos);
        }
        updateScreen();
    }

    //Bullet Movement, Bullet Collision
    int randomY = randomInteger(0, 120);
    Position bulletRespawn = {250, randomY};
    Position cherryPos = bulletRespawn;
    Position chiliPos = bulletRespawn;
    Position plumPos = bulletRespawn;
    Position carrotPos = bulletRespawn;
    Position watermelonPos = bulletRespawn;

    while (gameStop == false)
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
    }

    bool cherryCollision = checkCollisionSprite(mike, cherry);
    bool chiliCollision = checkCollisionSprite(mike, chili);
    bool plumCollision = checkCollisionSprite(mike, plum);
    bool carrotCollision = checkCollisionSprite(mike, carrot);
    bool watermelonCollision = checkCollisionSprite(mike, watermelon);
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
        drawBackground("losescreen", origin);
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
    bool wasStartPressed = wasButtonPressed(START);
    bool wasSelectPressed = wasButtonPressed(SELECT);
    if (wasStartPressed == true)
    {
        drawBackground(, origin);
        hideSprite();
    }
    //Win
}