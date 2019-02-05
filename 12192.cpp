#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int N, M;
    int f [501][501];
    while (scanf ("%d %d", &N, &M), N || M) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf ("%d", &f[i][j]);
            }
        }

        int Q; scanf("%d", &Q);
        for (int i = 0; i < Q; i++) {
            int l, h;
            scanf ("%d %d", &l, &h);
            int maxCont = 0;

            for (int j = 0; j < N; j++) {
                int cont = 0;
                int *x = lower_bound(f[j], f[j] + M, l);
                if (x - f[j] < M && f[j][x-f[j]] <= h && f[j][x-f[j]] >= l) {
                    cont++;
                    int line = j + 1;
                    int colum = x - f[j] + 1;
                    int val = f[line][colum];
                    while (line < N && colum < M && val <= h) {
                        cont++;
                        line++; colum++;
                        val = f[line][colum];
                    }
                }
                if (cont > maxCont) {
                    maxCont = cont;
                }
            }
            cout << maxCont << endl;
        }
        cout << "-" << endl;

    }


}
