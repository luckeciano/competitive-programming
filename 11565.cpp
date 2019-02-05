#include <cstdio>

using namespace std;

int main() {
    int N;
    scanf ("%d", &N);
    while (N--){
        int A, B, C;
        scanf ("%d %d %d", &A, &B, &C);
        bool sol = false;
        for (int i = -100; i <= 100 && !sol; i++) {
            if (i*i <= C ) {
                for (int j = - 100; j <= 200 && !sol; j++) {
                    if (i!=j && i*i + j*j <= C) {
                        for (int k = -100; k <= 100 && !sol; k++) {
                            if (i!= k && j!= k && i + j + k == A && i*j*k == B && i*i + j*j + k*k == C && !sol) {
                                printf ("%d %d %d\n", i, j, k);
                                sol = true;
                            }
                        }
                    }
                }
            }
        }
        if (!sol) printf ("No solution.\n");


    }


}
