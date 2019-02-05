#include <iostream>

using namespace std;

char board [8][8];

void updateBlackPawn(int i, int j) {
    if (i+1 < 8 && j - 1 >= 0) {
        if (board[i+1][j-1] == '.')
            board[i+1][j-1] = 'x';

    }
    if (i + 1 < 8 && j + 1 < 8) {
        if (board[i+1][j+1] == '.')
            board[i+1][j+1] = 'x';
    }

}
void updateWhitePawn(int i,int  j) {

    if (j - 1 >= 0 && i - 1 >=0) {
        if (board[i-1][j-1] == '.')
            board[i-1][j-1] = 'x';
    }

    if (j + 1 < 8 && i - 1 >= 0) {
        if (board[i-1][j+1] == '.')
            board[i-1][j+1] = 'x';
    }

}

void updateRookie (int i, int j) {
    for (int x = i + 1; x < 8; x++) {
            if (board[x][j] == '.')
                board[x][j] = 'x';
            else if (board[x][j] != '.' && board[x][j] != 'x')
                break;
        }
        for (int x = i - 1; x >= 0; x--) {
            if (board[x][j] == '.')
                board[x][j] = 'x';
            else if (board[x][j] != '.' && board[x][j] != 'x')
                break;
        }
        for (int y = j + 1; y < 8; y++) {
            if (board[i][y] == '.')
                board[i][y] = 'x';
            else if (board[i][y] != '.' && board[i][y] != 'x')
                break;
        }
        for (int y = j - 1; y >= 0; y--) {
            if (board[i][y] == '.')
                board[i][y] = 'x';
            else if (board[i][y] != '.' && board[i][y] != 'x')
                break;
        }


}

void updateKnight(int i, int j) {
    if (i - 2 >= 0 && j - 1 >= 0){
            if (board[i-2][j-1] == '.')
                board[i-2][j-1] = 'x';
        }
        if (i - 2 >= 0 && j + 1 < 8){
            if (board[i-2][j+1] == '.')
                board[i-2][j+1] = 'x';
        }
        if (i - 1 >= 0 && j + 2 < 8){
            if (board[i-1][j+2] == '.')
                board[i-1][j+2] = 'x';
        }
        if (i - 1 >= 0 && j - 2 >= 0){
            if (board[i-1][j-2] == '.')
                board[i-1][j-2] = 'x';
        }
        if (i + 2 < 8  && j - 1 >= 0){
            if (board[i+2][j-1] == '.')
                board[i+2][j-1] = 'x';
        }
        if (i + 2 < 8 && j + 1 < 8){
            if (board[i+2][j+1] == '.')
                board[i+2][j+1] = 'x';
        }
        if (i + 1 < 8 && j + 2 < 8){
            if (board[i+1][j+2] == '.')
                board[i+1][j+2] = 'x';
        }
        if (i + 1 < 8 && j - 2 >= 0){
            if (board[i+1][j-2] == '.')
                board[i+1][j-2] = 'x';
        }

}

void updateBishop(int i, int j) {
        for (int x = i + 1, y = j + 1; x < 8 && y < 8; x++, y++) {
            if (board[x][y] == '.')
                board[x][y] = 'x';
            else if (board[x][y] != '.' && board[x][y] != 'x')
                break;
        }
        for (int x = i + 1, y = j - 1; x < 8 && y >= 0; x++, y--) {
            if (board[x][y] == '.')
                board[x][y] = 'x';
            else if (board[x][y] != '.' && board[x][y] != 'x')
                break;
        }
        for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--) {
            if (board[x][y] == '.')
                board[x][y] = 'x';
            else if (board[x][y] != '.' && board[x][y] != 'x')
                break;
        }
        for (int x = i - 1, y = j + 1; x >= 0 && y < 8; x--, y++) {
            if (board[x][y] == '.')
                board[x][y] = 'x';
            else if (board[x][y] != '.' && board[x][y] != 'x')
                break;
        }

}

void updateQueen(int i, int j) {
    updateRookie(i, j);
    updateBishop(i, j);
}

void updateKing (int i,int j) {
    if (i + 1 < 8 && j + 1 < 8) {
            if (board[i + 1][j + 1] == '.')
                board[i + 1][j + 1] = 'x';
        }
        if (i < 8 && j + 1 < 8) {
            if (board[i][j + 1] == '.')
                board[i][j + 1] = 'x';
        }
        if (i -1 >= 0 && j + 1 < 8) {
            if (board[i - 1][j + 1] == '.')
                board[i - 1][j + 1] = 'x';
        }
        if (i - 1 >= 0 && j  < 8) {
            if (board[i - 1][j] == '.')
                board[i - 1][j] = 'x';
        }
        if (i + 1 < 8 && j < 8) {
            if (board[i + 1][j] == '.')
                board[i + 1][j] = 'x';
        }
        if (i + 1 < 8 && j - 1 >= 0) {
            if (board[i + 1][j - 1] == '.')
                board[i + 1][j - 1] = 'x';
        }
        if (i < 8 && j - 1 >= 0) {
            if (board[i][j - 1] == '.')
                board[i][j - 1] = 'x';
        }
        if (i - 1 >= 0 && j - 1 >= 0) {
            if (board[i - 1][j - 1] == '.')
                board[i - 1][j - 1] = 'x';
        }


}
void printBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}
int main() {
    char aux;

    while (cin >> aux) {
        int cont = 0;
        if (aux >= '1' && aux <= '8') {
            int num = aux - 48;
            for (int i = 0; i < num; i++) {
                board[0][i + cont] = '.';
            }
            cont = num;
        } else {
            board[0][0] = aux;
            cont++;
        }
        int t = 0;
        if (cont == 8) {
            cin >> aux;
            t = 1;
            cont = 0;
        }
        for (int i = t; i < 8; i++) {

            cin >> aux;
            while (cont <= 7) {
               // printBoard();
                if (aux >= '1' && aux <= '8'){
                    int num = aux - 48;
                    for (int j = 0; j < num; j++) {
                        board[i][j + cont] = '.';
                    }
                    cont += num;
                }
                else if (aux != '/') {
                    board[i][cont] = aux;
                    cont++;
                }
                if (cont <= 7) {
                    cin >> aux;
                }
            }
            if (i != 7)
                cin >> aux;
            cont = 0;
        }
        //printBoard();
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'p')
                    updateBlackPawn(i, j);
                else if (board[i][j] == 'P')
                    updateWhitePawn(i,j);
                else if (board[i][j] == 'r' || board[i][j] == 'R')
                    updateRookie(i,j);
                else if (board[i][j] == 'n' || board[i][j] == 'N')
                    updateKnight(i,j);
                else if (board[i][j] == 'b' || board[i][j] == 'B')
                    updateBishop(i,j);
                else if (board[i][j] == 'q' || board[i][j] == 'Q')
                    updateQueen(i,j);
                else if (board[i][j] == 'k' || board[i][j] == 'K')
                    updateKing(i,j);
            }
        }
        printBoard();
        int finalScore = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == '.')
                    finalScore++;
            }
        }
        cout << finalScore << endl;

    }


}
