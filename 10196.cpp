#include <iostream>
#include <cstdio>

using namespace std;
int bKingX, bKingY, wKingX, wKingY;
char board[8][8];

int checkBlackPawn (int i,int j) {
    int checkStatus = 0;
    if (j - 1 >= 0 && i + 1 < 8) {
        if (board[i+1][j-1] == 'K')
            checkStatus = 2;
    }
    if (j + 1 < 8 && i + 1 < 8) {
        if (board [i+1][j+1] == 'K')
            checkStatus = 2;
    }
    return checkStatus;

}

int checkWhitePawn(int i,int j) {
    int checkStatus = 0;
    if (j - 1 >= 0 && i - 1 >= 0) {
        if (board[i-1][j-1] == 'k')
            checkStatus = 1;
    }
    if (j + 1 < 8 && i - 1 >=  0) {
        if (board [i-1][j+1] == 'k')
            checkStatus = 1;
    }
    return checkStatus;
}

int checkRook (char piece, int i, int j) {
    int checkStatus = 0;
    if (piece == 'r') {
        for (int x = i + 1; x < 8; x++) {
            if (board[x][j] == 'K')
                checkStatus = 2;
            else if (board[x][j] != '.')
                break;
        }
        for (int x = i - 1; x >= 0; x--) {
            if (board[x][j] == 'K')
                checkStatus = 2;
            else if (board[x][j] != '.')
                break;
        }
        for (int y = j + 1; y < 8; y++) {
            if (board[i][y] == 'K')
                checkStatus = 2;
            else if (board[i][y] != '.')
                break;
        }
        for (int y = j - 1; y >= 0; y--) {
            if (board[i][y] == 'K')
                checkStatus = 2;
            else if (board[i][y] != '.')
                break;
        }
    }
    else {
        for (int x = i + 1; x < 8; x++) {
            if (board[x][j] == 'k')
                checkStatus = 1;
            else if (board[x][j] != '.')
                break;
        }
        for (int x = i - 1; x >= 0; x--) {
            if (board[x][j] == 'k')
                checkStatus = 1;
            else if (board[x][j] != '.')
                break;
        }
        for (int y = j + 1; y < 8; y++) {
            if (board[i][y] == 'k')
                checkStatus = 1;
            else if (board[i][y] != '.')
                break;
        }
        for (int y = j - 1; y >= 0; y--) {
            if (board[i][y] == 'k')
                checkStatus = 1;
            else if (board[i][y] != '.')
                break;
        }

    }

    return checkStatus;



}

int checkBishop (char piece, int i , int j) {
    int checkStatus = 0;
    if (piece == 'b') {
        for (int x = i + 1, y = j + 1; x < 8 && y < 8; x++, y++) {
            if (board[x][y] == 'K')
                checkStatus = 2;
            else if (board[x][y] != '.')
                break;
        }
        for (int x = i + 1, y = j - 1; x < 8 && y >= 0; x++, y--) {
            if (board[x][y] == 'K')
                checkStatus = 2;
            else if (board[x][y] != '.')
                break;
        }
        for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--) {
            if (board[x][y] == 'K')
                checkStatus = 2;
            else if (board[x][y] != '.')
                break;
        }
        for (int x = i - 1, y = j + 1; x >= 0 && y < 8; x--, y++) {
            if (board[x][y] == 'K')
                checkStatus = 2;
            else if (board[x][y] != '.')
                break;
        }

    }
    else {
        for (int x = i + 1, y = j + 1; x < 8 && y < 8; x++, y++) {
            if (board[x][y] == 'k')
                checkStatus = 1;
            else if (board[x][y] != '.')
                break;
        }
        for (int x = i + 1, y = j - 1; x < 8 && y >= 0; x++, y--) {
            if (board[x][y] == 'k')
                checkStatus = 1;
            else if (board[x][y] != '.')
                break;
        }
        for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--) {
            if (board[x][y] == 'k')
                checkStatus = 1;
            else if (board[x][y] != '.')
                break;
        }
        for (int x = i - 1, y = j + 1; x >= 0 && y < 8; x--, y++) {
            if (board[x][y] == 'k')
                checkStatus = 1;
            else if (board[x][y] != '.')
                break;
        }

    }

    return checkStatus;

}

int checkQueen(int i, int j) {
    int checkStatus = 0;
    if (board[i][j] == 'q') {
        checkStatus = checkRook('r', i, j);
        if (checkStatus == 0) {
            checkStatus = checkBishop('b', i, j);
        }
    }
    else {
        checkStatus = checkRook('R', i, j);
        if (checkStatus == 0) {
            checkStatus = checkBishop('B', i, j);
        }
    }

    return checkStatus;
}

int checkKnight(int i, int j) {
    int checkStatus = 0;
    if (board[i][j] == 'n') {
        if (i - 2 >= 0 && j - 1 >= 0){
            if (board[i-2][j-1] == 'K')
                checkStatus = 2;
        }
        if (i - 2 >= 0 && j + 1 < 8){
            if (board[i-2][j+1] == 'K')
                checkStatus = 2;
        }
        if (i - 1 >= 0 && j + 2 < 8){
            if (board[i-1][j+2] == 'K')
                checkStatus = 2;
        }
        if (i - 1 >= 0 && j - 2 >= 0){
            if (board[i-1][j-2] == 'K')
                checkStatus = 2;
        }
        if (i + 2 < 8  && j - 1 >= 0){
            if (board[i+2][j-1] == 'K')
                checkStatus = 2;
        }
        if (i + 2 < 8 && j + 1 < 8){
            if (board[i+2][j+1] == 'K')
                checkStatus = 2;
        }
        if (i + 1 < 8 && j + 2 < 8){
            if (board[i+1][j+2] == 'K')
                checkStatus = 2;
        }
        if (i + 1 < 8 && j - 2 >= 0){
            if (board[i+1][j-2] == 'K')
                checkStatus = 2;
        }

    }
    else {

        if (i - 2 >= 0 && j - 1 >= 0){
            if (board[i-2][j-1] == 'k')
                checkStatus = 1;
        }
        if (i - 2 >= 0 && j + 1 < 8){
            if (board[i-2][j+1] == 'k')
                checkStatus = 1;
        }
        if (i - 1 >= 0 && j + 2 < 8){
            if (board[i-1][j+2] == 'k')
                checkStatus = 1;
        }
        if (i - 1 >= 0 && j - 2 >= 0){
            if (board[i-1][j-2] == 'k')
                checkStatus = 1;
        }
        if (i + 2 < 8  && j - 1 >= 0){
            if (board[i+2][j-1] == 'k')
                checkStatus = 1;
        }
        if (i + 2 < 8 && j + 1 < 8){
            if (board[i+2][j+1] == 'k')
                checkStatus = 1;
        }
        if (i + 1 < 8 && j + 2 < 8){
            if (board[i+1][j+2] == 'k')
                checkStatus = 1;
        }
        if (i + 1 < 8 && j - 2 >= 0){
            if (board[i+1][j-2] == 'k')
                checkStatus = 1;
        }

    }
    return checkStatus;

}

int checkKing (int i, int j) {
    int checkStatus = 0;
    if (board[i][j] == 'k') {
        if (i + 1 < 8 && j + 1 < 8) {
            if (board[i + 1][j + 1] == 'K')
                checkStatus = 2;
        }
        if (i < 8 && j + 1 < 8) {
            if (board[i][j + 1] == 'K')
                checkStatus = 2;
        }
        if (i -1 >= 0 && j + 1 < 8) {
            if (board[i - 1][j + 1] == 'K')
                checkStatus = 2;
        }
        if (i - 1 >= 0 && j  < 8) {
            if (board[i - 1][j] == 'K')
                checkStatus = 2;
        }
        if (i + 1 < 8 && j < 8) {
            if (board[i + 1][j] == 'K')
                checkStatus = 2;
        }
        if (i + 1 < 8 && j - 1 >= 0) {
            if (board[i + 1][j - 1] == 'K')
                checkStatus = 2;
        }
        if (i < 8 && j - 1 >= 0) {
            if (board[i][j - 1] == 'K')
                checkStatus = 2;
        }
        if (i - 1 >= 0 && j - 1 >= 0) {
            if (board[i - 1][j - 1] == 'K')
                checkStatus = 2;
        }

    }
    else {
        if (i + 1 < 8 && j + 1 < 8) {
            if (board[i + 1][j + 1] == 'k')
                checkStatus = 1;
        }
        if (i < 8 && j + 1 < 8) {
            if (board[i][j + 1] == 'k')
                checkStatus = 1;
        }
        if (i -1 >= 0 && j + 1 < 8) {
            if (board[i - 1][j + 1] == 'k')
                checkStatus = 1;
        }
        if (i - 1 >= 0 && j  < 8) {
            if (board[i - 1][j] == 'k')
                checkStatus = 1;
        }
        if (i + 1 < 8 && j < 8) {
            if (board[i + 1][j] == 'k')
                checkStatus = 1;
        }
        if (i + 1 < 8 && j - 1 >= 0) {
            if (board[i + 1][j - 1] == 'k')
                checkStatus = 1;
        }
        if (i < 8 && j - 1 >= 0) {
            if (board[i][j - 1] == 'k')
                checkStatus = 1;
        }
        if (i - 1 >= 0 && j - 1 >= 0) {
            if (board[i - 1][j - 1] == 'j')
                checkStatus = 1;
        }

    }

    return checkStatus;

}
int main() {
    bool isGame = true;
    int cont = 0;
    while (isGame) {
        cont ++;

        isGame = false;

        for (int i = 0; i < 8; i++) {
            for (int j =0; j < 8; j++) {
                char aux;
                cin >> board[i][j];
                if (board[i][j] != '.')
                    isGame = true;
                if (board[i][j] == 'k') {
                    bKingX = i;
                    bKingY = j;
                }
                if (board[i][j] == 'K') {
                    wKingX = i;
                    wKingY = j;
                }


            }
        }
        if (!isGame) break;
        int checkStatus = 0;
        for (int i = 0; i < 8 && checkStatus == 0; i ++) {
            for (int j = 0; j < 8 && checkStatus == 0; j++) {
                if (board[i][j] == 'p')
                    checkStatus = checkBlackPawn(i, j);
                else if (board[i][j] == 'P')
                    checkStatus = checkWhitePawn(i, j);
                else if (board[i][j] == 'r' || board[i][j] == 'R')
                    checkStatus = checkRook(board[i][j], i, j);
                else if (board[i][j] == 'b' || board[i][j] == 'B')
                    checkStatus = checkBishop(board[i][j], i, j);
                else if (board[i][j] == 'q' || board[i][j] == 'Q')
                    checkStatus = checkQueen(i, j);
                else if (board[i][j] == 'n' || board[i][j] == 'N')
                    checkStatus = checkKnight(i,j);
                else if (board[i][j] == 'k' || board[i][j] == 'K')
                    checkStatus = checkKing(i, j);
            }
        }
        cout << "Game #" << cont << ": ";
        if (checkStatus == 0)
            cout << "no king is in check." << endl;
        else if (checkStatus == 1)
            cout << "black king is in check." << endl;
        else if (checkStatus == 2)
            cout << "white king is in check." << endl;

        scanf ("\n");


    }



}
