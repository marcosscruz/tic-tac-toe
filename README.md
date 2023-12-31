# Tic-Tac-Toe Implementations in Different Programming Languages

This repository contains simple implementations of the classic Tic-Tac-Toe (or Noughts and Crosses) game in various programming languages, including C++, Java, Python, and JavaScript. The goal is to showcase how the same game can be created in different languages, enabling a comparison between them.

## Implementations

To date, only the C++ language has been implemented "tic-tac-toe", the other languages will be implemented gradually.

<div>
### C++

- [Tic-Tac-Toe in C++](cpp/tic-tac-toe.cpp): C++ implementation of Tic-Tac-Toe, where two players can play on the same computer.

    - **Two-Player Mode**: Players can take turns to make their moves on the game board.
    - **AI Opponent**: The computer opponent uses a simple algorithm to make its moves. It evaluates the game board to find the best available move.
    - **Player Switching**: The game automatically alternates between Player 1 (X) and Player 2 (O) after each valid move.
    - **Winning Conditions**: The implementation checks for victory conditions, where a player wins by filling three consecutive spaces horizontally, vertically, or diagonally with their symbol.
    - **Draw Detection**: The game also detects when the board is full, resulting in a draw if neither player wins.
    - **Play Again Option**: After the end of a match, players can choose to play another game without restarting the program.

- **Attention:** this C++ implementation only works on the Windows operating system.

### JavaScript

- [Tic-Tac-Toe in JavaScript](javascript/): JavaScript implementation of Tic-Tac-Toe that can be run in web browsers.

    - **Two-Player Mode**: Players can take turns to make their moves on the game board.
    - **AI Opponent**: The computer opponent uses a simple algorithm to make its moves. It evaluates the game board to find the best available move.
    - **Player Switching**: The game automatically alternates between Player 1 (X) and Player 2 (O) after each valid move.
    - **Winning Conditions**: The implementation checks for victory conditions, where a player wins by filling three consecutive spaces horizontally, vertically, or diagonally with their symbol.
    - **Draw Detection**: The game also detects when the board is full, resulting in a draw if neither player wins.
    - **Play Again Option**: After the end of a match, players can choose to play another game without restarting the program.

- **Attention:** This JavaScript implementation can be run in web browsers.

<!-- ### Java

- [Tic-Tac-Toe in Java](java/TicTacToe.java): Java implementation of Tic-Tac-Toe with a simple graphical interface. -->

### Python

- [Tic-Tac-Toe in Python](python/tic-tac-toe.py): Python implementation of Tic-Tac-Toe using a graphical user interface (GUI).

    - **Graphical User Interface**: The game utilizes Tkinter to create a simple GUI, where players can make their moves by clicking on the interactive buttons.

    - **Two Game Modes**:
        - **Player vs. Player (PvP)**: Two human players take turns to make their moves on the 3x3 game board.
        - **Player vs. AI (PvAI)**: <!-- A single player can challenge the computer AI opponent. The AI uses a basic algorithm to determine its moves, providing a challenging experience. --> <span style="color:red">not yet implemented</span>


    - **Player Turn Switching**: The game alternates between Player 1 (X) and Player 2 (O) in PvP mode. In PvAI mode, the player is always "X", and the AI is "O".

    - **Move Validation**: The game ensures that a player cannot make a move on an already occupied space.

    - **Winning Conditions**: Victory is achieved by filling three consecutive spaces horizontally, vertically, or diagonally with the player's symbol.

    - **Draw Detection**: The game detects when the board is full and declares a draw if neither player achieves victory.

    - **Game Restart Option**: After the end of each game, a message box appears to announce the result (win/defeat/draw), thus clearing the board and restarting the game.

</div>

## How to Run

Each implementation of Tic-Tac-Toe has its own execution instructions. You can find specific details in the directories of each language mentioned above. Make sure to have the appropriate development environment set up for the respective language.

## Tic Tac Toe Variation

This variation of the game consists of a larger 3x3 board with other smaller boards of the same size within each cell of the larger board. I still need to formulate this idea further.

## Contributions

You are welcome to contribute more implementations in other languages or improve the existing ones. Follow the contribution guidelines and open a pull request to share your implementations.

## License

This project is licensed under the MIT License. Please see the [LICENSE](LICENSE) file for details.

## Credits

This project was inspired by the idea of demonstrating how a simple application can be created in multiple programming languages. We appreciate the open-source community for their contributions.
