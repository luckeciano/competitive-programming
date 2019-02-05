#include <cstdio>
#include <cstring>

int memo[105][105];

int ways (int n, int K) {
    if (K == 1) return 1;

    if (memo[n][K] != -1) return memo[n][K];

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += ways (n - i, K - 1);
    }
    ans = ans%1000000;
    return memo[n][K] = ans;

}


int main() {
    int n, K;
    memset(memo, -1, sizeof memo);
    while (scanf ("%d %d", &n, &K), n || K) {
        printf ("%d\n", ways(n, K));
    }


}
