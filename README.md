# Tic-Tac-Toe Game in C

## **Situation**

The goal was to develop a simple yet interactive Tic-Tac-Toe game in C, with a command-line interface featuring color-coded outputs for a better visual experience. The game should allow two players to take turns, handle invalid inputs, track the number of games, wins, and draws, and provide a summary of results after each session.

## **Task**

1. **Design the Game Logic**: Implement the core mechanics of Tic-Tac-Toe, including board rendering, player moves, win/draw conditions, and result announcements.
2. **Add Color Coding**: Use ANSI escape codes to color-code the game board and output messages, enhancing user interaction.
3. **Handle Multiple Games**: Allow players to play multiple rounds, keep track of wins and draws, and display a summary at the end.
4. **User Input Validation**: Ensure user inputs are valid and prompt for re-entry if needed.

## **Action**

1. **Board Rendering**:
   - The board is displayed with cells color-coded based on the player's move and empty cells.
   - `renderTicTacToeBoard` function prints the board with appropriate colors for 'X', 'O', and empty cells.

2. **Game Outcome Determination**:
   - The `determineGameOutcome` function checks rows, columns, and diagonals for a winning combination and verifies if the game is a draw.

3. **Player Moves**:
   - The `getPlayerMove` function handles player inputs, validates them, and updates the board accordingly.

4. **Game Initialization**:
   - The `initializeBoard` function sets up the board with numbers 1-9 as placeholders.

5. **Game Loop**:
   - The `runTicTacToeGame` function manages the main game loop, keeps track of player scores, handles multiple rounds, and provides game summaries.

6. **Color Output**:
   - The `outputColoredText` function is used to print text in various colors to make the game more engaging.

## **Result**

- The Tic-Tac-Toe game successfully implements the classic game mechanics with enhanced visual feedback using color coding.
- Players can play multiple rounds, with results and statistics displayed at the end.
- The game handles invalid inputs gracefully, ensuring a smooth user experience.
