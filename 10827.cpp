#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int TC;
    scanf ("%d", &TC);
    int matrix [80][80];
    int A [160][160];
    while (TC --) {
        int N;
        scanf ("%d", &N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf ("%d", &matrix[i][j]);
                A[i][j] = matrix[i][j];
                if (j > 0) A[i][j] += A[i][j - 1];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j + N] = matrix[i][j];
                A[i][j + N] += A[i][j + N - 1];
            }
        }

        int maxSubRect = -100*150*75;
        for (int a = 0; a < N; a++) {
            for (int b = a; b - a < N; b ++) {

                for (int row = 0; row < N; row ++) {
                    int subRect = 0;
                    for (int fRow = row; fRow - row < N; fRow++) {
                        if (a > 0) subRect += A[fRow%N][b] - A[fRow%N][(a - 1)];
                        else subRect += A[fRow%N][b];

                        //if (subRect < 0) subRect = 0;
                        maxSubRect = max(maxSubRect, subRect);
                    }
                }
            }
        }
        printf ("%d\n", maxSubRect);
    }


}
