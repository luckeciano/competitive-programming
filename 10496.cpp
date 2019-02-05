#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int beepX [12];
int beepY [12];
int memo [11][1 << 11];
int dist[15][15];
int n;

int tsp(int pos, int bitmask) { // bitmask stores the visited coordinates
  if (bitmask == (1 << (n + 1)) - 1)
    return dist[pos][0]; // return trip to close the loop
  if (memo[pos][bitmask] != -1)
    return memo[pos][bitmask];

  int ans = 2000000000;
  for (int nxt = 0; nxt <= n; nxt++) // O(n) here
    if (nxt != pos && !(bitmask & (1 << nxt))) // if coordinate nxt is not visited yet
      ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
  return memo[pos][bitmask] = ans;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int a, b; cin >> a >> b;
        cin >> beepX[0] >> beepY[0];
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> beepX[i] >> beepY[i];
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dist[i][j] = abs(beepX[i] - beepX[j]) + abs(beepY[i] - beepY[j]);
            }
        }

         memset(memo, -1, sizeof memo);
        printf("The shortest path has length %d\n", tsp(0, 1)); // DP-T


    }


}
