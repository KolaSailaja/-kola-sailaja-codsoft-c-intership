#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the tic-tac-toe board
void printBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

// Function to check if a player has won
bool checkWinner(vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Function to play the tic-tac-toe game
void playTicTacToe() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    
    while (true) {
        cout << "Current board:" << endl;
        printBoard(board);
        
        int row, col;
        cout << "Player " << currentPlayer << ", enter row (0-2): ";
        cin >> row;
        cout << "Player " << currentPlayer << ", enter column (0-2): ";
        cin >> col;
        
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Please try again." << endl;
            continue;
        }
        
        board[row][col] = currentPlayer;
        
        if (checkWinner(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        
        bool isBoardFull = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    isBoardFull = false;
                    break;
                }
            }
            if (!isBoardFull) break;
        }
        
        if (isBoardFull) {
            cout << "It's a tie!" << endl;
            break;
        }
        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    cout << "Let's play Tic-Tac-Toe!" << endl;
    playTicTacToe();
    return 0;
}

