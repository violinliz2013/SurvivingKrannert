#include <gbalib.h>
Sprite mike;
void startGame()
{
    Color krannertwall = createColor(252, 131, 67);
    Color black = createColor(0, 0, 0);
    Color red = createColor(255, 0, 0);
    Position mikeStart = {40, 80};
    Position startTextPos = {200, 20};
    Position origin = {0, 0};
    Size startTextSize = {39, 20};
    Size spriteSize = {32, 32};
    Size mikeSize = {17, 30};
    mike = createSprite("mikesprite", mikeSize);
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
    drawFilledRectangle(krannertwall, startTextPos, startTextSize);
}
int main()
{
    //Sound
    Sound music = createSound("oldvideogamemusic");
    playSound(music, true);

    //Backgrounds, Sprites, Gifs, Colors
    Position origin = {0, 0};
    Position text1Pos = {100, 20};
    Position text2Pos = {40, 140};
    Position box1Pos = {95, 15};
    Position box2Pos = {35, 135};
    Position ts1Pos = {60, 20};
    Position ts2Pos = {65, 140};
    int randomY = randomInteger(0, 120);
    int health = 5;
    int bulletsDodged = 0;
    Position bulletRespawn = {250, randomY};
    Position cherryPos = {250, 10};
    Position chiliPos = {200, 120};
    Position plumPos = {150, 10};
    Position carrotPos = {100, 120};
    Position watermelonPos = {50, 10};
    Size spriteSize = {32, 32};
    Size cherrySize = {14, 22};
    Size chiliSize = {23, 19};
    Size plumSize = {20, 20};
    Size carrotSize = {27, 21};
    Size watermelonSize = {24, 22};
    Size box1Size = {50, 17};
    Size box2Size = {170, 17};
    Size text1Size = {200, 17};
    Sprite cherry = createSprite("realcherry", cherrySize);
    Sprite chili = createSprite("realchili", chiliSize);
    Sprite plum = createSprite("plum", plumSize);
    Sprite carrot = createSprite("realcarrot", carrotSize);
    Sprite watermelon = createSprite("watermelon", watermelonSize);
    Background krannertHall = createBackground("krannerthall");
    Background losescreen = createBackground("losescreen");
    Background pausescreen = createBackground("pausescreen");
    Background titlescreen = createBackground("titlescreen");
    Background winscreen = createBackground("winscreen");
    Color white = createColor(255, 255, 255);
    Color black = createColor(0, 0, 0);
    Color red = createColor(255, 0, 0);
    bool cherryCollision = false;
    bool chiliCollision = false;
    bool plumCollision = false;
    bool carrotCollision = false;
    bool watermelonCollision = false;
    updatePosition(cherry, cherryPos);
    updatePosition(chili, chiliPos);
    updatePosition(plum, plumPos);
    updatePosition(carrot, carrotPos);
    updatePosition(watermelon, watermelonPos);

    //TitleScreen
    drawBackground(titlescreen, origin);
    wait(2);
    animateTextSlow("Surviving Krannert", black, ts1Pos, text1Size);
    wait(2);
    animateTextSlow("Press B to begin", black, ts2Pos, text1Size);
    bool wasBPressed = false;
    bool gaming = false;
    while (wasBPressed == false)
    {
        wasBPressed = isButtonDown(B);
        updateScreen();
        if (wasBPressed == true)
        {
            gaming = true;
            startGame();
        }
    }

    //Buttons, Sprite Movement
    Position mikePos = {40, 80};
    bool isUpPressed = false;
    bool isDownPressed = false;
    bool wasAPressed = false;
    while (gaming == true)
    {
        isUpPressed = isButtonDown(UP);
        isDownPressed = isButtonDown(DOWN);
        if (isUpPressed == true && mikePos.y > 0)
        {
            mikePos = getPosition(mike);
            mikePos.y -= 1;
            updatePosition(mike, mikePos);
        }
        if (isDownPressed == true && mikePos.y <= 129)
        {
            mikePos = getPosition(mike);
            mikePos.y += 1;
            updatePosition(mike, mikePos);
        }
        int randomRespawn = randomInteger(0, 120);
        Position bulletRespawn = {250, randomRespawn};
        showSprite(cherry);
        cherryPos = getPosition(cherry);
        cherryPos.x -= 1;
        updatePosition(cherry, cherryPos);
        if (cherryPos.x <= 0)
        {
            bulletsDodged += 1;
            updatePosition(cherry, bulletRespawn);
        }
        cherryCollision = checkCollisionSprite(mike, cherry);
        if (cherryCollision == true)
        {
            health -= 1;
            hideSprite(cherry);
            updatePosition(cherry, bulletRespawn);
            showSprite(cherry);
        }
        showSprite(chili);
        chiliPos = getPosition(chili);
        chiliPos.x -= 1;
        updatePosition(chili, chiliPos);
        if (chiliPos.x <= 0)
        {
            bulletsDodged += 1;
            updatePosition(chili, bulletRespawn);
        }
        chiliCollision = checkCollisionSprite(mike, chili);
        if (chiliCollision == true)
        {
            health -= 1;
            hideSprite(chili);
            updatePosition(chili, bulletRespawn);
            showSprite(chili);
        }
        showSprite(plum);
        plumPos = getPosition(plum);
        plumPos.x -= 1;
        updatePosition(plum, plumPos);
        if (plumPos.x <= 0)
        {
            bulletsDodged += 1;
            updatePosition(plum, bulletRespawn);
        }
        plumCollision = checkCollisionSprite(mike, plum);
        if (plumCollision == true)
        {
            health -= 1;
            hideSprite(plum);
            updatePosition(plum, bulletRespawn);
            showSprite(plum);
        }
        showSprite(carrot);
        carrotPos = getPosition(carrot);
        carrotPos.x -= 1;
        updatePosition(carrot, carrotPos);
        if (carrotPos.x <= 0)
        {
            bulletsDodged += 1;
            updatePosition(carrot, bulletRespawn);
        }
        carrotCollision = checkCollisionSprite(mike, carrot);
        if (carrotCollision == true)
        {
            health -= 1;
            hideSprite(carrot);
            updatePosition(carrot, bulletRespawn);
            showSprite(carrot);
        }
        showSprite(watermelon);
        watermelonPos = getPosition(watermelon);
        watermelonPos.x -= 1;
        updatePosition(watermelon, watermelonPos);
        if (watermelonPos.x <= 0)
        {
            bulletsDodged += 1;
            updatePosition(watermelon, bulletRespawn);
        }
        watermelonCollision = checkCollisionSprite(mike, watermelon);
        if (watermelonCollision == true)
        {
            health -= 1;
            hideSprite(watermelon);
            updatePosition(watermelon, bulletRespawn);
            showSprite(watermelon);
        }
        if (health <= 0)
        {
            gaming = false;
        }
        if (bulletsDodged >= 20)
        {
            gaming = false;
        }
        while (gaming == false)
        {
            if (health <= 0)
            {
                drawBackground(losescreen, origin);
                hideSprite(mike);
                hideSprite(cherry);
                hideSprite(chili);
                hideSprite(plum);
                hideSprite(carrot);
                hideSprite(watermelon);
                drawFilledRectangle(black, box1Pos, box1Size);
                drawFilledRectangle(black, box2Pos, box2Size);
                drawHollowRectangle(white, box1Pos, box1Size);
                drawHollowRectangle(white, box2Pos, box2Size);
                drawText("FAILED", white, text1Pos);
                drawText("Press A to try again", white, text2Pos);
                health = 1;
                updateScreen();
            }
            if (bulletsDodged >= 20)
            {
                drawBackground(winscreen, origin);
                hideSprite(mike);
                hideSprite(cherry);
                hideSprite(chili);
                hideSprite(plum);
                hideSprite(carrot);
                hideSprite(watermelon);
                drawFilledRectangle(black, box1Pos, box1Size);
                drawFilledRectangle(black, box2Pos, box2Size);
                drawHollowRectangle(white, box1Pos, box1Size);
                drawHollowRectangle(white, box2Pos, box2Size);
                drawText("SUCCESS", white, text1Pos);
                drawText("Press A to try again", white, text2Pos);
                bulletsDodged = 0;
                updateScreen();
            }
            wasAPressed = isButtonDown(A);
            updateScreen();
            if (wasAPressed == true)
            {
                health = 5;
                bulletsDodged = 0;
                gaming = true;
                startGame();
            }
        }
        updateScreen();
    }
}