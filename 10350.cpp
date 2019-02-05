#include <iostream>
#include <cstring>
using namespace std;
#define INF 10000000
int n, m;
int memo[20][130];
int grid[20][20][130];
int shortestPath (int j, int k) {
    if (k == n - 1) return 0;

    if (memo[j][k] != -1) return memo[j][k];

    int ans = INF;
    for (int t = 0; t < m; t++) {
       ans = min (ans, shortestPath(t, k + 1) + grid[j][t][k]);
    }

    return memo[j][k] = ans;


}

int main() {
    string name;
    while (cin >> name) {
        memset(memo, -1, sizeof memo);
        cin >> n >> m;
        for (int k = 0; k < n - 1; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> grid[i][j][k];
                }
            }
        }

        int ans = INF;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ans = min (ans, shortestPath(j, 0));
            }
        }
        cout << name << endl;
        cout <<  ans + 2*(n-1) << endl;
    }



}
