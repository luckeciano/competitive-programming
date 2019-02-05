#include <iostream>

using namespace std;

char grid[25][25];
int M, N;
int x, y;
char aux;

int dr[] = {1,0,-1, 0}; // trick to explore an implicit 2D grid
int dc[] = {0,1, 0,-1}; // S,SE,E,NE,N,NW,W,SW neighbors
int floodfill(int r, int c, char c1, char c2, int R, int C) { // returns the size of CC
    if (r < 0 || r >= R || c < 0 || c >= C) return 0; // outside grid
    if (grid[r][c] != c1) return 0; // does not have color c1
    int ans = 1; // adds 1 to ans because vertex (r, c) has c1 as its color
    if (x == r && y == c) ans -= 100000000;
    grid[r][c] = c2; // now recolors vertex (r, c) to c2 to avoid cycling!
    for (int d = 0; d < 4; d++) {
        int k = r + dr[d]; int u = c + dc[d];
        if (u >= C) u = u%C;
        else if (u < 0) u = u + C;
        ans += floodfill(k, u, c1, c2, R, C);
    }
    return ans; // the code is neat due to dr[] and dc[]
}


int main() {
    while (cin >> M >> N) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> aux; grid[i][j] = aux;
            }
        }

        cin >> x >> y;
        char land = grid[x][y];
       // cout << land << endl;
        int maxLands = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == land) {
                    int nLands = floodfill(i, j, land, '.', M, N);
                    if (nLands > maxLands)
                        maxLands = nLands;
                }
            }
        }/*
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)
                cout << grid[i][j];
            cout << endl;
        }*/

        cout << maxLands << endl;
    }
}
