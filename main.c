#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 9
#define SOZE 3

struct score {
    char player[20];
    int lives;
};

void printBoard(int grid[][SIZE]);
void playGame(int level);
int isValidMove(int grid[][SIZE], int row, int col, int num);
int isBoardFull(int grid[][SIZE]);
int solveSudoku(int grid[][SIZE]);
int nextround(int grid[][SIZE]);
void check(int grid[][SIZE], int row, int col);
void sudoku(int grid[][SIZE]);
void saveScore(struct score player);
void displayHighscores();
void solveSudokuPuzzle(int grid[][SIZE]);
void copyGrid(int grid[][SIZE], int copyGrid[][SIZE]);

void printBoard(int grid[][SIZE]) {
    int i, j;
    printf("\n    Sudoku Board\n");
    printf("  ---------------------\n");
    for (i = 0; i < SIZE; i++) {
        printf("  ");
        for (j = 0; j < SIZE; j++) {
            if (j % SOZE == 0 && j != 0) {
                printf("| ");
            }
            if (grid[i][j] == 0) {
                printf("- ");
            } else {
                printf("%d ", grid[i][j]);
            }
        }
        printf("\n");
        if ((i + 1) % SOZE == 0 && i != SIZE - 1) {
            printf("  ------|-------|------\n");
        }
    }
    printf("  ---------------------\n");
}

void playGame(int level) {
    int grid[SIZE][SIZE];
    int i, j;

    // Initialize grid with zeros
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    // Assign random values to some cells based on the selected level
    int filledCells;
    if (level == 1) {
        filledCells = 30;
    } else if (level == 2) {
        filledCells = 20;
    } else if (level == 3) {
        filledCells = 10;
    }

    srand(time(NULL));
    int count = 0;
    while (count < filledCells) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        int num = rand() % SIZE + 1;
        if (grid[row][col] == 0 && isValidMove(grid, row, col, num)) {
            grid[row][col] = num;
            count++;
        }
    }

    printBoard(grid);
    sudoku(grid);
}

int isValidMove(int grid[][SIZE], int row, int col, int num) {
    int i, j;
    // Check if the number already exists in the same row or column
    for (i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }

    // Check if the number already exists in the same 3x3 box
    int startRow = row - row % SOZE;
    int startCol = col - col % SOZE;
    for (i = 0; i < SOZE; i++) {
        for (j = 0; j < SOZE; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int isBoardFull(int grid[][SIZE]) {
    int row, col;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                return 0; // There are still empty cells
            }
        }
    }
    return 1; // All cells are filled
}

int solveSudoku(int grid[][SIZE]) {
    int row, col, num;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                for (num = 1; num <= SIZE; num++) {
                    if (isValidMove(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid)) {
                            return 1;
                        }
                        grid[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }

    return 1;
}

int nextround(int grid[][SIZE]) {
    int row, col;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                return 1; // There are still empty cells
            }
        }
    }
    return 0; // All cells are filled
}

void check(int grid[][SIZE], int row, int col) {
    int solution = 0;
    int num;

    printf("\nEnter the number: ");
    scanf("%d", &num);

    if (isValidMove(grid, row, col, num)) {
        grid[row][col] = num;
        printf("\nValid Move!\n");
        printBoard(grid);
        solution = solveSudoku(grid);
        if (solution && !nextround(grid)) {
            printf("\nCongratulations! You have solved the Sudoku!\n");
        } else {
            printf("\nContinue solving...\n");
        }
    } else {
        printf("\nInvalid Move! Try again.\n");
    }
}

void sudoku(int grid[][SIZE]) {
    int row, col;
    printf("\nStart solving the Sudoku!\n");
    while (nextround(grid)) {
        printf("\nEnter the row (0-8) and column (0-8) to check: ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
            if (grid[row][col] == 0) {
                check(grid, row, col);
            } else {
                printf("\nThe cell is already filled. Try another one.\n");
            }
        } else {
            printf("\nInvalid input! Try again.\n");
        }
    }
}

void saveScore(struct score player) {
    FILE *file = fopen("highscores.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s %d\n", player.player, player.lives);
        fclose(file);
    }
}

void displayHighscores() {
    printf("\n    High Scores\n");
    printf("  -----------------\n");
    FILE *file = fopen("highscores.txt", "r");
    if (file != NULL) {
        char name[20];
        int lives;
        while (fscanf(file, "%s %d", name, &lives) != EOF) {
            printf("  %-15s %d\n", name, lives);
        }
        fclose(file);
    }
    printf("  -----------------\n");
}

void solveSudokuPuzzle(int grid[][SIZE]) {
    if (solveSudoku(grid)) {
        printf("\nSolution found!\n");
        printBoard(grid);
    } else {
        printf("\nNo solution exists for the given Sudoku puzzle.\n");
    }
}

void copyGrid(int grid[][SIZE], int copyGrid[][SIZE]) {
    int row, col;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            copyGrid[row][col] = grid[row][col];
        }
    }
}

int main() {
    int choice, level;
    struct score player;

    printf("\nWelcome to Sudoku Game!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Play Game\n");
        printf("2. Display High Scores\n");
        printf("3. Solve Sudoku Puzzle\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nSelect Difficulty Level:\n");
                printf("1. Easy\n");
                printf("2. Medium\n");
                printf("3. Hard\n");
                printf("Enter your choice (1-3): ");
                scanf("%d", &level);
                playGame(level);
                break;
            case 2:
                displayHighscores();
                break;
            case 3: {
                int grid[SIZE][SIZE];
                printf("\nEnter the Sudoku puzzle (use 0 for empty cells):\n");
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        printf("Enter the number for row %d, column %d: ", i, j);
                        scanf("%d", &grid[i][j]);
                    }
                }
                printf("\nSolving Sudoku puzzle...\n");
                solveSudokuPuzzle(grid);
                break;
            }
            case 4:
                printf("\nThank you for playing Sudoku! Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
