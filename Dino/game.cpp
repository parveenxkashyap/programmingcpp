// Simple Dino Game in C++
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>

// move cursor to x,y
void moveTo(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// delay function
v                   oid pause(unsigned int milliseconds)
{
    clock_t goal = milliseconds + clock();
    while (goal > clock());
}

// show instructions and score
void displayGameInfo()
{
    system("cls");
    moveTo(10, 2);
    printf("Press X to Exit, Press Space to Jump");
    moveTo(62, 2);
    printf("SCORE : ");
    moveTo(1, 25);
    for (int x = 0; x < 79; x++)
        printf("п");
}

int jumpHeight, gameSpeed = 40;

// draw dino
void displayCharacter(int jumpType = 0)
{
    static int animationState = 1;

    if (jumpType == 0)
        jumpHeight = 0;
    else if (jumpType == 2)
        jumpHeight--;
    else
        jumpHeight++;

    moveTo(2, 15 - jumpHeight); printf("                ");
    moveTo(2, 16 - jumpHeight); printf("     мллл      ");
    moveTo(2, 17 - jumpHeight); printf("    ллллллл     ");
    moveTo(2, 18 - jumpHeight); printf("   ллллллллл    ");
    moveTo(2, 19 - jumpHeight); printf("  лллллплллл   ");
    moveTo(2, 20 - jumpHeight); printf(" млллллппллллм  ");
    moveTo(2, 21 - jumpHeight); printf(" ллллллпплллллл ");
    moveTo(2, 22 - jumpHeight); printf(" пллллллппллллп ");

    moveTo(2, 23 - jumpHeight);
    if (jumpType == 1 || jumpType == 2) {
        printf("   ллп плпппл   ");
        moveTo(2, 24 - jumpHeight);
        printf("   лм   лм      ");
    }
    else if (animationState == 1) {
        printf("  пллп  ппп     ");
        moveTo(2, 24 - jumpHeight);
        printf("     лм         ");
        animationState = 2;
    }
    else {
        printf("   плм пл       ");
        moveTo(2, 24 - jumpHeight);
        printf("         лм     ");
        animationState = 1;
    }

    moveTo(2, 25 - jumpHeight);
    if (jumpType != 0)
        printf("                ");
    else
        printf("ппппппппппппппппп");

    pause(gameSpeed);
}

// draw cactus
void displayObstacle()
{
    static int obstaclePosition = 0, score = 0;

    // collision check
    if (obstaclePosition == 56 && jumpHeight < 4) {
        score = 0;
        gameSpeed = 40;
        moveTo(36, 8);
        printf("Game Over");
        getch();
        moveTo(36, 8);
        printf("         ");
    }

    moveTo(74 - obstaclePosition, 20);
    printf("л    л ");

    obstaclePosition++;
    if (obstaclePosition == 73) {
        obstaclePosition = 0;
        score++;
        moveTo(70, 2);
        printf("     ");
        moveTo(70, 2);
        printf("%d", score);
        if (gameSpeed > 20)
            gameSpeed--;
    }
}

int main()
{
    system("mode con: lines=29 cols=82");
    char input;
    int i;

    displayGameInfo();

    while (true) {
        while (!kbhit()) {
            displayCharacter();
            displayObstacle();
        }

        input = getch();
        if (input == ' ') {
            for (i = 0; i < 10; i++) {
                displayCharacter(1);
                displayObstacle();
            }
            for (i = 0; i < 10; i++) {
                displayCharacter(2);
                displayObstacle();
            }
        }
        else if (input == 'x') {
            return 0;
        }
    }
}
