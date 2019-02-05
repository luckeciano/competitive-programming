#include <iostream>
#include <cstring>
#define INF 10000000
using namespace std;

int di [] = {-1, 0, 0, 1};
int dj [] = {0, 1, -1, 0};
int xA, yA;
int N, n;
pair<int, int> memo[12][12][28][105];
char grid[12][12];
pair<int, int> shortestPath (int r, int c, int cur, int len) {
    if (r < 0 || r > N || c < 0 || c > N) return make_pair (INF, 0);
    if (grid[r][c] != '.' && grid[r][c] != cur + 'A') return make_pair(INF, 0);
    if (cur ==  n - 1 && grid[r][c] == cur + 'A') {
        return make_pair(len, 1);
    }
    if (memo[r][c][cur][len] != make_pair(-1, -1)) return memo[r][c][cur][len];
    if (grid[r][c] == cur + 'A') cur++;
    pair<int, int> ans = make_pair(INF, 0);
    for (int i = 0; i < 4; i++) {
        if (ans.first > shortestPath(r + di[i], c + dj[i], cur, len + 1).first){
            ans.first = shortestPath(r + di[i], c + dj[i], cur, len + 1).first;
            ans.second = shortestPath(r + di[i], c + dj[i], cur, len + 1).second;
        }
    }

    return memo[r][c][cur][len] = ans;
}

int main() {
    int cont = 0;
    while (cin >> N, N) {
        cont++;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 28; k++) {
                    for (int t = 0; t < 105; t++)
                        memo[i][j][k][i] = make_pair(-1, -1);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'A') {
                    xA = i; yA = j;
                }
                if (grid[i][j] >= 'A' && grid[i][j] <= 'Z')
                    n++;
            }
        }
        cout << "Case " << cont << ": ";
        pair <int, int> ans = shortestPath(xA, yA, 0, 0);
        if (ans.first == INF) cout << "Impossible" << endl;
        else cout << ans.first << " " << ans.second << endl;
    }


}
