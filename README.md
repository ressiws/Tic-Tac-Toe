<h1 align="center">Tic-Tac-Toe Game</h1>

![](https://img.shields.io/github/issues/ressiws/Tic-Tac-Toe?style=for-the-badge)
![](https://img.shields.io/github/stars/ressiws/Tic-Tac-Toe?style=for-the-badge)
![](https://img.shields.io/github/license/ressiws/Tic-Tac-Toe?style=for-the-badge)

This repository contains a command-line implementation of the classic Tic Tac Toe game in C++. The game features a player-versus-AI mode where the player competes against an AI opponent.

## 🎈 Prerequisites

- Install the latest version of [Visual Studio](https://developer.microsoft.com/en-us/windows/downloads) (the free community edition is sufficient).
    - Install the optional "C++ Universal Windows Platform tools" component.
    - install the latest Windows (10/11) SDK.

## 🔧 Features

- Player vs AI: Play against an AI opponent that employs a minimax algorithm to make strategic moves.
- Restart Game: After each game conclusion (win, lose, or tie), players have the option to restart the game for another round.
- Turn Order Adjustment: After a loss, the game ensures that the player who lost gets to start the next game, allowing them to play first.

## 🌠 How to Play

- Clone repository using
    ```
    git clone https://github.com/ressiws/Tic-Tac-Toe/
    ```
- Open [Tic-Tac-Toe.sln](/Tic-Tac-Toe.sln) in Visual Studio to build and run the Tic-Tac-Toe game.

#

> [!NOTE]
> If any zero-day issue arises while using this project, we recommend that the user experiencing the problem open an issue in this product's GitHub repository to seek further assistance.

#

## 📢 Code Structure

- `tictactoe.h` and `tictactoe.cpp` Contains the implementation of the Tic Tac Toe game logic, including the board, player moves, AI moves using the minimax algorithm, win/loss checks, restart functionality, and console-based UI.

## 📚 To-Do list
- [ ] **Implement UI:** Develop a user interface to enhance the game's visual experience.
- [ ] **Add Difficulty Levels:** Introduce options for players to choose the AI's intelligence level (e.g., Easy, Medium, Hard).
- [ ] **Add Linux Support:** Ensure compatibility and functionality for the game on linux systems.

## 💭 Contribution

Contributions to enhance the game functionalities, improve the user interface, optimize algorithms, or any other enhancements are highly encouraged! Feel free to fork the repository, implement your changes, and submit a pull request.

## 📊 Copyright and Licencing

Copyright © 2022-2023 [ressiws](https://github.com/ressiws) swisser.project@gmail.com 
This project is under the [GNU v3.0 Licence](./LICENSE)
