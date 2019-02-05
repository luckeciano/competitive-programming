#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int L;
    scanf ("%d", &L);
    int numbers[1005];
    int testCase = 0;
    while (L != 0) {
        testCase++;
        for (int i = 0 ; i < L; i++) {
            scanf ("%d", &numbers[i]);
        }

        sort (numbers, numbers + L);
        int Q; scanf ("%d", &Q);
        printf ("Case %d:\n", testCase);
        for (int i = 0; i < Q; i++) {
            int S;
            scanf ("%d", &S);
            int closestSum = 999999;
            for (int j = 0; j < L; j++) {
                for (int k = j + 1; k < L; k++) {
                    if (abs(numbers[j] + numbers[k] - S) < abs(closestSum - S))
                        closestSum = abs(numbers[j] + numbers[k]);
                }
            }
            printf ("Closest sum to %d is %d.\n", S, closestSum);
        }

        scanf ("%d", &L);
    }



}
