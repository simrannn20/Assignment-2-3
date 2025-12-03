#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int score = 0;
int lives = 3;

void draw(int player, int obstacle) {
    system("cls");

    printf("LIVES: %d    SCORE: %d\n\n", lives, score);

    for(int i = 0; i < 20; i++) {
        if (i == player)
            printf("P");
        else
            printf(" ");
    }
    printf("\n");

    for(int i = 0; i < 20; i++) {
        if (i == obstacle)
            printf("#");
        else
            printf(" ");
    }
    printf("\n");
}

int gameLoop() {
    int player = 0;
    int obstacle = 19;
    int jump = 0;

    score = 0;

    while(lives > 0) {
        if(kbhit()) {
            char ch = getch();
            if(ch == ' ') jump = 1;
        }

        if(jump) {
            player = 1;
            jump = 0;
        } else {
            player = 0;
        }

        draw(player, obstacle);
        Sleep(100);

        obstacle--;

        if(obstacle < 0) {
            obstacle = 19;
            score++;
        }

        if(obstacle == 0 && player == 0) {
            lives--;
            printf("\nCollision! Lives left: %d\n", lives);
            Sleep(700);
        }

        if(lives == 0) {
            system("cls");
            printf("GAME OVER!\nFinal Score: %d\n", score);
            return 0;
        }
    }
}

int main() {
    char choice;

    while(1) {
        lives = 3;
        system("cls");
        printf("===== RUNNER GAME =====\n");
        printf("1. Start Game\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        if(choice == '1') {
            gameLoop();
        } else {
            break;
        }

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &choice);

        if(choice != 'y') break;
    }

    return 0;
}
