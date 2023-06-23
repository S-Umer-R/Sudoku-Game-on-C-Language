# Sudoku Game

This repository contains a simple implementation of a Sudoku game in C. The game allows players to play Sudoku puzzles at different difficulty levels, solve Sudoku puzzles, and view high scores. The game provides a command-line interface for interaction.

## Features

The Sudoku game includes the following features:

1. **Play Game**: Players can choose the difficulty level (easy, medium, or hard) and play a Sudoku game. The game generates a Sudoku grid with some pre-filled cells, and players can solve the puzzle by entering numbers for the empty cells.

2. **Display High Scores**: Players can view the high scores achieved by previous players. The high scores are stored in a file called `highscores.txt`.

3. **Solve Sudoku Puzzle**: Players can enter a custom Sudoku puzzle and the game will attempt to solve it. The solution, if found, will be displayed.

4. **Exit**: Players can choose to exit the game at any time.

## Getting Started

To compile and run the Sudoku game, follow these steps:

1. Navigate to the project directory.
   ```
   cd sudoku-game
   ```

2. Compile the C source code using a C compiler (e.g., GCC).
   ```
   gcc -o sudoku-game main.c
   ```

3. Run the compiled executable.
   ```
   ./sudoku-game
   ```

## How to Play

1. When you run the game, you will see a menu with options numbered from 1 to 4.

2. Select option 1 to play the game. Choose a difficulty level by entering a number from 1 to 3 (1 for easy, 2 for medium, and 3 for hard).

3. The game will generate a Sudoku grid with some pre-filled cells. The pre-filled cells cannot be modified.

4. To solve the Sudoku puzzle, enter the row and column numbers (both ranging from 0 to 8) for the cell you want to check.

5. If the entered number is a valid move according to the Sudoku rules, it will be placed in the cell. Otherwise, you will be prompted to try again.

6. Continue solving the puzzle by entering row and column numbers until all the cells are filled or until you decide to exit the game.

7. If you successfully solve the Sudoku puzzle, a congratulatory message will be displayed. Otherwise, the game will indicate that you should continue solving.

8. At any time, you can select option 2 from the menu to view the high scores achieved by previous players.

9. To solve a custom Sudoku puzzle, select option 3 from the menu. Enter the numbers for each cell of the Sudoku puzzle, with 0 representing an empty cell. The game will attempt to solve the puzzle and display the solution if found.

10. To exit the game, select option 4 from the menu.
