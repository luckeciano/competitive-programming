#include <cstdio>
#include <iostream>

using namespace std;

int road[105][105];
int T;
int R, C, N, M;
int even, odd;
int W;

void dfs(int i, int j) {
    int reach = 0;
    road[i][j] = 1;
    if (i + M < R && j + N < C && road[i + M][j + N] != -1) {
        reach++;
        if (road[i + M][j + N] == 0)
            dfs (i + M, j + N);
    }

    if (N != 0 && i + M < R && j - N >= 0 && road[i + M][j - N] != -1) {
        reach++;
        if (road[i + M][j - N] == 0)
            dfs (i + M, j - N);
    }


    if (M != 0 && i - M >= 0 && j + N < C && road[i - M][j + N] != -1) {
        reach++;
        if (road[i - M][j + N] == 0)
            dfs (i - M, j + N);
    }


    if (M != 0 && N != 0 && i - M >= 0 && j - N >= 0 && road[i - M][j - N] != -1) {
        reach++;
        if (road[i - M][j - N] == 0)
            dfs (i - M, j - N);
    }
    if (M != N) {

        if (i + N < R && j + M < C && road[i + N][j + M] != -1) {
            reach++;
            if (road[i + N][j + M] == 0)
                dfs (i + N, j + M);
        }


        if ( M != 0 && i + N < R && j - M >= 0 && road[i + N][j - M] != -1) {
            reach++;
            if (road[i + N][j - M] == 0)
                dfs (i + N, j - M);
        }

        if ( N != 0 && i - N >= 0 && j + M < C && road[i - N][j + M] != -1) {
            reach++;
            if (road[i - N][j + M] == 0)
                dfs (i - N, j + M);
        }


        if ( N != 0 && M != 0 && i - N >= 0 && j - M >= 0 && road[i - N][j - M] != -1) {
            reach++;
            if (road[i - N][j - M] == 0)
                dfs (i - N, j - M);
        }
    }

    if (reach%2 == 0) even++;
    else odd++;


}

int main() {
    scanf ("%d", &T);
    for (int q = 0; q < T; q++) {
        scanf ("%d %d %d %d", &R, &C, &N, &M);
        for (int i = 0 ; i < R; i++) {
            for (int j = 0; j < C; j++) {
                road[i][j] = 0;
            }
        }
        scanf ("%d", &W);
        for (int i = 0; i < W; i++) {
            int x, y;
            scanf ("%d %d", &x, &y);
            road[x][y] = -1;
        }
        odd = 0;
        even = 0;
        dfs(0, 0);
        printf ("Case %d: %d %d\n", q + 1, even, odd);



    }



}
