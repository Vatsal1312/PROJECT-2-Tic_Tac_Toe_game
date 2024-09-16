#include <stdio.h>
#include <stdlib.h>

// Color codes
#define RESET_COLOR "\033[0m"
#define YELLOW "\033[1;33m"
#define NEON_ORANGE "\033[38;5;214m"
#define NEON_BLUE "\033[38;5;45m"
#define GREEN "\033[1;32m"
#define BRIGHT_GREEN "\033[1;92m"
#define RED "\033[1;31m"
#define SALMON_RED "\033[38;5;210m"
#define LIGHT_BLUE "\033[38;2;173;216;230m"
#define FOREST_GREEN "\033[38;2;34;139;34m"

// Function to display the Tic-Tac-Toe board
void  renderTicTacToeBoard(char board[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // If the current cell contains 'X', print it in orange
            if (board[i][j] == 'X')
            {
                printf(NEON_ORANGE " %c " RESET_COLOR, board[i][j]);
            }
            // If the current cell contains 'O', print it in blue
            else if (board[i][j] == 'O')
            {
                printf(NEON_BLUE " %c " RESET_COLOR, board[i][j]);
            }
            // If the cell is empty, print its placeholder number in yellow
            else
            {
                printf(YELLOW " %c " RESET_COLOR, board[i][j]);
            }
            if (j < 2)
            {
                printf("|"); // Sepration between columns
            }
        }
        if (i < 2) // Sepration of rows
        {
            printf("\n---|---|---\n");
        }
    }
    printf("\n\n");
}

// Function to check for a winner or a draw
int determineGameOutcome(char board[3][3])
{
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) // Check each row for three identical values
        {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) // Check each column for three identical values
        {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) // Checking for diagonal 
    {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) //Checking for anti-diagnol
    {
        return 1;
    }
    for (int i = 0; i < 3; i++) // Check for draw or empty cells
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return 0;
            }
        }
    }
    return -1; // Match is draw 
}

// Function to reset the board
void initializeBoard(char board[3][3])
{
    char start = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = start++;
        }
    }
}

// Function to print text in a specified color
void outputColoredText(const char *text, const char *color)
{
    printf("%s%s%s", color, text, RESET_COLOR);
}

// Function to print match results
void announceMatchResult(int winner)
{
    if (winner == 1)
    {
        outputColoredText("Player 1 wins this match!\n", GREEN);
    }
    else
    {
        outputColoredText("Player 2 wins this match!\n", GREEN);
    }
}

// Function to get valid input from the user
int getPlayerMove(char board[3][3], int player)
{
    int choice, row, col;
    char mark = (player == 1) ? 'X' : 'O'; // Player 1 = 'X', Player 2 = 'O'
    if (player == 1)
    {
        outputColoredText("Player 1 (X), enter a number: ", NEON_ORANGE);
    }
    else
    {
        outputColoredText("Player 2 (O), enter a number: ", NEON_BLUE);
    }
    scanf("%d", &choice);

    // Calculate the corresponding row and column
    row = (choice - 1) / 3;
    col = (choice - 1) % 3;


    // Check if the input is valid (not out of bounds and not already occupied)
    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O')
    {
        outputColoredText("Invalid input! Please enter a valid number.\n", RED);
        return getPlayerMove(board, player);
    }

    // Mark the board with the player's symbol ('X' or 'O')
    board[row][col] = mark;
    return choice;
}

// Function to start the game and keep track of results
void runTicTacToeGame()
{
    int player1Wins = 0, player2Wins = 0, draws = 0, totalGames = 0;
    char board[3][3];
    int currentPlayer, result;
    int continueGame = 1;
    while (continueGame)
    {
        initializeBoard(board);
        currentPlayer = 1; // Player 1 always starts
        result = 0;
        totalGames++;
        printf("\nGame %d\n", totalGames);
        while (result == 0)
        {
             renderTicTacToeBoard(board);
            int validMove = getPlayerMove(board, currentPlayer);
            currentPlayer = (currentPlayer % 2) + 1;
            result = determineGameOutcome(board);
        }
         renderTicTacToeBoard(board);
        if (result == 1)
        {
            currentPlayer = (currentPlayer % 2) + 1;
            announceMatchResult(currentPlayer);
            if (currentPlayer == 1)
                player1Wins++;
            else
                player2Wins++;
        }
        else
        {
            outputColoredText("It's a draw!\n", GREEN);
            draws++;
        }
        // Ask if the players want to continue
        printf(LIGHT_BLUE "\nDo you want to play another game? (1 for yes, 0 for no): " RESET_COLOR);
        while (1)
        {
            int result = scanf("%d", &continueGame);
            if (result == 1 && (continueGame == 1 || continueGame == 0))
            {
                break;
            }
            else
            {
                while (getchar() != '\n')
                    ;
                printf(RED "Invalid input! Please enter 1 for yes or 0 for no.\n" RESET_COLOR);
                printf(LIGHT_BLUE "Do you want to play another game? (1 for yes, 0 for no): " RESET_COLOR);
            }
        }
    }

    // Print the summary of the game
    outputColoredText("\nGame Summary:\n", BRIGHT_GREEN);
    printf(SALMON_RED "Total games played: " FOREST_GREEN "%d\n" RESET_COLOR, totalGames);
    printf(SALMON_RED "Player 1 wins: " FOREST_GREEN "%d\n" RESET_COLOR, player1Wins);
    printf(SALMON_RED "Player 2 wins: " FOREST_GREEN "%d\n" RESET_COLOR, player2Wins);
    printf(SALMON_RED "Draws: " FOREST_GREEN "%d\n" RESET_COLOR, draws);
    outputColoredText("Thanks for playing!\n", GREEN);
}

int main()
{
    runTicTacToeGame();
    return 0;
}
