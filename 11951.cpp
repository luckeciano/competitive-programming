#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int TC;
    scanf ("%d", &TC);
    int A[105][105];
    int cont = 0;
    while (TC--){
        cont++;
        int N, M;
        long long K;
        scanf ("%d %d %lld", &N, &M, &K);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf ("%d", &A[i][j]);
                if (j > 0) A[i][j] += A[i][j - 1];

            }
        }

        long long minSubRect = 0;
        long long maxSpace = 0;
        for (int a = 0; a < M; a++) {
            for (int b = a; b < M; b++) {
                for (int iRow = 0; iRow < N; iRow++) {
                    long long subRect = 0;
                    long long space = 0;
                    for (int row = iRow; row < N; row ++) {
                        if (a > 0) subRect += A[row][b] - A[row][a - 1];
                        else subRect += A[row][b];

                        space += (b - a) + 1;
                       // cout << space << " " << subRect << endl;
                        if (subRect > K) break;
                        if (space > maxSpace) {
                            maxSpace = space;
                            minSubRect = subRect;
                        } else if (space == maxSpace && subRect < minSubRect) {
                                minSubRect = subRect;
                        }
                    }
                }
            }
        }
        printf ("Case #%d: %lld %lld\n", cont, maxSpace, minSubRect);


    }


}
