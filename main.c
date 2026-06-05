 #include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

/* Initialize Canvas */
void initializeCanvas() {

    int i, j;

    for(i = 0; i < ROWS; i++) {

        for(j = 0; j < COLS; j++) {

            canvas[i][j] = '_';
        }
    }
}

/* Display Canvas */
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

/* Draw Rectangle */
void drawRectangle(int row, int col, int height, int width) {

    int i, j;

    for(i = row; i < row + height; i++) {

        for(j = col; j < col + width; j++) {

            if(i >= 0 && i < ROWS && j >= 0 && j < COLS) {

                canvas[i][j] = '*';
            }
        }
    }
}

/* Draw Horizontal or Vertical Line */
void drawLine(int row1, int col1, int row2, int col2) {

    int i;

    /* Horizontal Line */
    if(row1 == row2) {

        for(i = col1; i <= col2; i++) {

            if(i >= 0 && i < COLS) {

                canvas[row1][i] = '*';
            }
        }
    }

    /* Vertical Line */
    else if(col1 == col2) {

        for(i = row1; i <= row2; i++) {

            if(i >= 0 && i < ROWS) {

                canvas[i][col1] = '*';
            }
        }
    }

    else {

        printf("Only horizontal and vertical lines supported!\n");
    }
}

/* Draw Triangle */
void drawTriangle(int row, int col, int height) {

    int i, j;

    for(i = 0; i < height; i++) {

        for(j = 0; j <= i; j++) {

            if(row + i < ROWS && col + j < COLS) {

                canvas[row + i][col + j] = '*';
            }
        }
    }
}

int main() {

    int choice;

    int row, col, height, width;
    int row1, col1, row2, col2;

    initializeCanvas();

    while(1) {

        printf("\n===== 2D GRAPHICS EDITOR =====\n");

        printf("1. Display Canvas\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Line\n");
        printf("4. Draw Triangle\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:

                displayCanvas();
                break;

            case 2:

                printf("Enter row column height width: ");
                scanf("%d%d%d%d", &row, &col, &height, &width);

                drawRectangle(row, col, height, width);

                break;

            case 3:

                printf("Enter row1 col1 row2 col2: ");
                scanf("%d%d%d%d", &row1, &col1, &row2, &col2);

                drawLine(row1, col1, row2, col2);

                break;

            case 4:

                printf("Enter row column height: ");
                scanf("%d%d%d", &row, &col, &height);

                drawTriangle(row, col, height);

                break;

            case 5:

                printf("Exiting Program...\n");
                return 0;

            default:

                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
 