#include <iostream>
#include <cstring>
#define INF 10000000
using namespace std;

int N, K;
int walk [607];
int memo[607][320][1000];
int minMax (int u, int v, int sum) {
    if (v > K) return INF;
    if (u == N && v == K) return sum;
    if (u == N && v != K) return INF;
    if (memo[u][v][sum] != -1) return memo[u][v][sum];
    int a = minMax(u + 1, v, sum + walk[u]);
    int b = max(sum, minMax(u + 1, v + 1, walk[u]));
    return memo[u][v][sum] = min(a,b);
}


int main() {
    while (cin >> N >> K) {
        memset(memo, -1, sizeof memo);
        for (int i = 0; i <= N; i++) {
            cin >> walk[i];
        }
        cout << minMax(0, 0, 0) << endl;
    }


}
