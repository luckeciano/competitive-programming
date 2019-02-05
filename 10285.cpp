#include <iostream>
#include <cstring>
using namespace std;
int memo[105][105];
int grid[105][105];
int R, C;
int longestPath (int a, int b) {
    if (memo[a][b] != -1) return memo[a][b];
    int ans = 0;
    if (a - 1 >= 0 && grid[a - 1][b] < grid[a][b]) {
        ans = max(ans, longestPath(a - 1, b) + 1);
    }
    if (b - 1 >= 0 && grid[a][b - 1] < grid[a][b]) {
        ans = max(ans, longestPath(a, b - 1) + 1);
    }
    if (a + 1 < R && grid[a + 1][b] < grid[a][b]) {
        ans = max(ans, longestPath(a + 1, b) + 1);
    }
    if (b + 1 < C && grid[a][b + 1] < grid[a][b]) {
        ans = max(ans, longestPath(a, b + 1) + 1);
    }
    return memo[a][b] = ans;

}

int main() {
    int TC; cin >> TC;
    string name;
    while (TC --) {
        memset(memo, -1, sizeof memo);
        cin >> name >> R >> C;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> grid[i][j];
            }
        }

        int res = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                res = max (res, longestPath(i, j));
            }
        }

        cout << name << ": " << res + 1 << endl;
    }


}
