#include <iostream>
#include <cstring>
#include <fstream>
#define INF 100000000
using namespace std;
int N, K;
long long grid [80][80];
long long memo [77][77][7][4];
bool memb[77][77][7][4];
long long maxPath (int r, int c, int k, int stat){
    if (r == N - 1 && c == N - 1 && k >= 0) return grid[N - 1][N - 1];

    if (k < 0) return -INF;

    if (memb[r][c][k][stat]) return memo[r][c][k][stat];
    long long ans = -INF;
    if (r + 1 < N ) {
        if (grid[r+1][c] < 0) {
            if (maxPath(r + 1, c, k - 1, 0 ) != -INF )
                ans = max(ans, maxPath(r + 1, c, k - 1, 0));
        }
        else {
            if (maxPath(r + 1, c, k, 0) != -INF)
                ans = max (ans, maxPath(r+ 1,c, k, 0));
        }
    }
    if (c - 1 >= 0 && (stat == 0 || stat == 1)) {
        if (grid[r][c - 1] < 0) {
            if (maxPath(r, c - 1, k - 1, 1)  != -INF)
                ans = max (ans, maxPath(r, c - 1, k - 1, 1));
        }
        else {
            if (maxPath(r, c - 1, k, 1) != -INF)
                ans = max (ans, maxPath(r, c - 1, k, 1));
        }
    }
    if (c + 1 < N && (stat == 0 || stat == 2)) {
        if (grid[r][c + 1] < 0) {
            if (maxPath(r, c + 1, k - 1,2) != -INF)
                ans = max (ans, maxPath(r, c + 1, k - 1, 2));
        }
        else  {
            if (maxPath(r, c + 1, k, 2) != -INF)
                ans = max (ans, maxPath(r, c + 1, k , 2));
        }
    }
    memb[r][c][k][stat] = true;
    if (ans == -INF);
    else ans += grid[r][c];
    return memo[r][c][k][stat] = ans;


}

int main() {
    ofstream myf ("10913.txt");
    int cont = 0;
    while (cin >> N >> K, N || K) {
        cont++;
        memset (memb, false, sizeof memb);
        for (int i = 0; i < N; i++) {
            for (int j =0 ; j < N; j++) {
                cin >> grid[i][j];
            }
        }
        long long ans;
        if (grid[0][0] < 0)
            ans  = maxPath(0, 0, K - 1, 0);
        else ans = maxPath(0, 0, K, 0);
        //long long ans = maxPath (0, 0, K, 0);
        cout << "Case " << cont << ": ";
        myf << "Case " << cont << ": ";
        if (ans ==  -INF) {
            cout << "impossible" << endl;
            myf << "impossible" << endl;
        }
        else {
            cout << ans << endl;
            myf << ans << endl;
        }
    }


}
