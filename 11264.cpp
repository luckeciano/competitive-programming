#include <cstdio>

using namespace std;

int main() {
    int coins[1005];
    int TC;
    scanf ("%d", &TC);
    while (TC--){
        int n;
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf ("%d", &coins[i]);
        }
        int cont = 0;
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            if (sum + coins[i] < coins[i + 1]) {
                cont++;
                sum += coins[i];
            }
        }
        cont++;
        printf ("%d\n", cont);
    }



}
