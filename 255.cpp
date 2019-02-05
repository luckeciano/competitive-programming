#include <iostream>

using namespace std;
int board [8][8];
void calculateKingMoves(int x, int y) {
    if (x - 1 >= 0)
            board[x - 1][y] = 1;
    if (x + 1 < 8)
        board[x + 1][y] = 1;
    if (y - 1 >= 0)
        board[x][y - 1] = 1;
    if (y + 1 < 8)
        board[x][y + 1] = 1;
}

void calculateQueenMoves(int x, int y) {
    for (int i = x; i < 8; i++) {
        if (board[i][y] == 0)
            board[i][y] = 2;
        else if (board[i][y] == 1)
            board[i][y] = 3;
        else if (board[i][y] == 5)
            break;
    }
    for (int i = x; i >= 0; i--) {
        if (board[i][y] == 0)
            board[i][y] = 2;
        else if (board[i][y] == 1)
            board[i][y] = 3;
        else if (board[i][y] == 5)
            break;
    }
    for (int j = y; j < 8; j++) {
        if (board[x][j] == 0)
            board[x][j] = 2;
        else if (board[x][j] == 1)
            board[x][j] = 3;
        else if (board[x][j] == 5)
            break;
    }
    for (int j = y; j >= 0; j--) {
        if (board[x][j] == 0)
            board[x][j] = 2;
        else if (board[x][j] == 1)
            board[x][j] = 3;
        else if (board[x][j] == 5)
            break;
    }
}
void zeroBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j ++) {
            board[i][j] = 0;
        }
    }


}
void printBoard() {
     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j ++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    int aux;
    while (cin >> aux) {
        zeroBoard();
        int kingX; int kingY;
        kingX = aux/8;
        kingY = aux%8;
        board[kingX][kingY] = 5; //king
        calculateKingMoves(kingX, kingY);
        cin >> aux;
        int queenX = aux/8;
        int queenY = aux%8;
        if (board[queenX][queenY] == 5) {
            cout << "Illegal state" << endl;
            cin >> aux;
        }
        else {
            board[queenX][queenY] = 4; //queen
            calculateQueenMoves(queenX, queenY);
            //printBoard();
            cin >> aux;
            int requiredX, requiredY;
            requiredX = aux/8; requiredY = aux%8;
            if (board[requiredX][requiredY] == 0 || board[requiredX][requiredY] == 1 || board[requiredX][requiredY] == 5
                || board[requiredX][requiredY] == 4)
                cout << "Illegal move" << endl;
            else if (board[requiredX][requiredY] == 3)
                cout << "Move not allowed" << endl;
            else if (board[requiredX][requiredY] == 2) {
                zeroBoard();
                board[kingX][kingY] = 5;
                calculateKingMoves(kingX, kingY);
                board[requiredX][requiredY] = 4;
                calculateQueenMoves(requiredX, requiredY);
                bool continueMove = false;
                if (kingX - 1 >= 0) {
                    if (board[kingX-1][kingY] == 1)
                        continueMove = true;
                }if (kingX + 1 < 8) {
                    if (board[kingX+1][kingY] == 1)
                        continueMove = true;
                } if (kingY - 1 >= 0) {
                    if (board[kingX][kingY - 1] == 1)
                        continueMove = true;
                } if (kingY + 1 < 8) {
                    if (board[kingX][kingY + 1] == 1)
                        continueMove = true;
                }

                if (continueMove) cout << "Continue" << endl;
                else cout << "Stop" << endl;
            }
        }
    }


}
