#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int t;
    scanf ("%d", &t);
    int table[8][8];

    int a[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int b[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    while (t--) {

        int n;
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf ("%d", &table[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            a[i] = i;
            b[i] = i;
        }
        int minSum = 9999999;
        do {
            bool used[8] = {false};
            for (int i = 0; i < n; i++) {
                int minLose = 999999;
                for (int j = 0; j < n; j++) {
                    if (!used[j] && table[a[i]][j] < minLose) {
                        minLose = table[a[i]][j];
                        b[i] = j;
                    }
                }
                used[b[i]] = true;
            }
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += table[a[i]][b[i]];
            }
            if (sum < minSum)
                minSum = sum;

        } while (next_permutation(a, a + n));

        printf ("%d\n", minSum);
    }




}
