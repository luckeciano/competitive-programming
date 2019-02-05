#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int A[105][105];
    int N;
    scanf ("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf ("%d", &A[i][j]);
            if (j > 0) A[i][j] += A[i][j - 1];
        }
    }
    int maxSubRect = -127*100*100;
    for (int a = 0; a < N; a++) {
        for (int b = a; b < N; b ++) {
            int subRect = 0;
            for (int row = 0; row < N; row ++) {
                if (a > 0) subRect += A[row][b] - A[row][a - 1];
                else subRect += A[row][b];

                if (subRect < 0) subRect = 0;
                maxSubRect = max(maxSubRect, subRect);
            }
        }
    }

    printf ("%d\n", maxSubRect);



}
