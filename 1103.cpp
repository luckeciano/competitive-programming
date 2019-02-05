#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char mes [805][805];

int H, W;
string res;
string inst;
int white;
int dr[] = {1,0,-1, 0}; // trick to explore an implicit 2D grid
int dc[] = {0,1, 0,-1}; // S,SE,E,NE,N,NW,W,SW neighbors
int minRow, minC, maxRow, maxC;
void floodfill(int r, int c, char c1, char c2, int R, int C) { // returns the size of CC
    if (r < 0 || r >= R || c < 0 || c >= C) return; // outside grid


    if (mes[r][c] == '0' && c1 == '1')  {
        white++;
        floodfill (r, c, '0', '.', R, C);
    }
    if (mes[r][c] != c1) return; // does not have color c1
    mes[r][c] = c2; // now recolors vertex (r, c) to c2 to avoid cycling!
    for (int d = 0; d < 4; d++)
        floodfill(r + dr[d], c + dc[d], c1, c2, R, C);
}

string hexToBin (char hex) {
    string x;
   // cout << hex << endl;

        if (hex == '0')  x = "0000";
        if (hex == '1') x = "0001";
        if (hex == '2') x = "0010";
        if (hex == '3') x =  "0011";
        if (hex == '4') x =  "0100";
        if (hex == '5') x =  "0101";
        if (hex == '6') x =  "0110";
        if (hex == '7') x =  "0111";
        if (hex == '8') x =  "1000";
        if (hex == '9') x =  "1001";
        if (hex == 'a') x =  "1010";
        if (hex == 'b') x =  "1011";
        if (hex == 'c') x =  "1100";
        if (hex == 'd') x = "1101";
        if (hex == 'e') x =  "1110";
        if (hex == 'f') x = "1111";

    return x;
}


int main() {
    int cont = 0;
    string aux;
    while (scanf ("%d %d", &H, &W), H || W) {
        cont++;
        res.clear();
        for (int i = 0; i < H; i++) {

            cin >> inst;
            for (int k = 0; k < inst.size(); k++) {
                aux = hexToBin(inst[k]);
                //cout << aux << endl;
                for (int t = 0; t < 4; t++)
                    mes[i][4*k + t] = aux[t];
            }

        }



        for (int i = 0; i < 4*W; i++) {
            if (mes[0][i] == '0')
                floodfill(0, i, '0', '.', H, 4*W);
            if (mes[H - 1][i] == '0')
                floodfill(H - 1, i, '0', '.', H, 4*W);
        }

        for (int j = 0; j < H; j++) {
            if (mes[j][0] == '0')
                floodfill(j, 0, '0', '.', H, 4*W);
            if (mes[j][4*W - 1] == '0')
                floodfill(j, 4*W - 1, '0', '.', H, 4*W);
        }
/*
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < 4*W; j++)
                cout << mes[i][j];
            cout << endl;
        }*/


        for (int i = 0; i < H; i++) {
            for (int j = 0; j < 4*W; j++) {
                //cout << i << "  " << j << endl;

                if (mes[i][j] == '1') {
                    white = 0;
                    floodfill (i, j, '1', '.', H, 4*W);
                    if (white == 1)
                        res.push_back('A');
                    else if (white == 3)
                        res.push_back ('J');
                    else if (white == 5)
                        res.push_back('D');
                    else if (white == 4)
                        res.push_back('S');
                    else if (white == 0)
                        res.push_back('W');
                    else if (white == 2)
                        res.push_back ('K');

                }

            }
        }



        sort (res.begin(), res.end());
        cout << "Case " << cont << ": " << res << endl;

    }




}
