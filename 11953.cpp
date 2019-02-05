#include <iostream>

using namespace std;
char grid [105][105];
int N; char aux;

int dr[] = {1,0,-1, 0}; // trick to explore an implicit 2D grid
int dc[] = {0,1, 0,-1}; // S,SE,E,NE,N,NW,W,SW neighbors
int floodfill(int r, int c, int R, int C) { // returns the size of CC
    if (r < 0 || r >= R || c < 0 || c >= C) return 0; // outside grid
    if (grid[r][c] == '.') return 0; // does not have color c1
    int ans = 0;
    if (grid[r][c] == 'x') ans = 1;
    grid[r][c] = '.'; // now recolors vertex (r, c) to c2 to avoid cycling!
    for (int d = 0; d < 4; d++)
    ans += floodfill(r + dr[d], c + dc[d], R, C);
    return ans; // the code is neat due to dr[] and dc[]
}

int main() {
        int TC;
        cin >> TC;
        int cont = 0;
        while (TC --) {
            cont++;
            cin >> N;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cin >> aux; grid[i][j] = aux;
                }
            }
            int alive = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (grid[i][j] == '@' || grid[i][j] == 'x') {
                        int ans = floodfill(i, j, N, N);
                        if (ans > 0) alive++;
                    }
                }
            }
            cout << "Case " << cont << ": " << alive << endl;
        }

}
