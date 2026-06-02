#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

/* Function to initialize canvas with '_' */
void initializeCanvas() {

    int i, j;

    for(i = 0; i < ROWS; i++) {

        for(j = 0; j < COLS; j++) {

            canvas[i][j] = '_';
        }
    }
}

/* Function to display canvas */
void displayCanvas() {

    int i, j;

    printf("\nCURRENT CANVAS:\n\n");

    for(i = 0; i < ROWS; i++) {

        for(j = 0; j < COLS; j++) {

            printf("%c ", canvas[i][j]);
        }

        printf("\n");
    }
}

int main() {

    int choice;

    initializeCanvas();

    while(1) {

        printf("\n===== 2D GRAPHICS EDITOR =====\n");

        printf("1. Display Canvas\n");
        printf("2. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                displayCanvas();
                break;

            case 2:
                printf("Exiting Program...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
