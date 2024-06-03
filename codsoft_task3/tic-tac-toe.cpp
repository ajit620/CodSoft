#include <iostream>

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    std::cout << "Current board state:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        if (i < 2) std::cout << "\n---------\n";
    }
    std::cout << "\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

int checkWinner() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;

    return 0;
}

bool isDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}

void game() {
    std::cout << "Player 1, choose your marker (X/O): ";
    char markerP1;
    std::cin >> markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;
    char markerP2 = (markerP1 == 'X') ? 'O' : 'X';

    drawBoard();
    int winner = 0;

    for (int i = 0; i < 9; ++i) {
        std::cout << "It's player " << currentPlayer << "'s turn. Enter your slot: ";
        int slot;
        std::cin >> slot;

        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            std::cout << "Invalid slot! Try again.\n";
            --i;
            continue;
        }

        drawBoard();
        winner = checkWinner();
        if (winner != 0) {
            std::cout << "Player " << winner << " wins!\n";
            break;
        }

        if (isDraw()) {
            std::cout << "The game is a draw!\n";
            break;
        }

        switchPlayer();
    }
}

int main() {
    char playAgain;
    do {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = '1' + i * 3 + j;

        game();
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}
