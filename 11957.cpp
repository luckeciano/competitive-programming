#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int memo[105][105];
int N;
char grid[105][105];
long long ways (int x, int y) {
    if (x == 0) return 1;

    if (memo[x][y] != -1) return memo[x][y];
    long long ans = 0;
    if (x - 1 >= 0 && y - 1 >= 0 && grid[x-1][y-1] == '.')
        ans += ways (x - 1, y - 1)%1000007;
    else if (x - 2 >= 0 && y - 2 >= 0 && grid[x - 1][y - 1] == 'B' && grid[x - 2][y - 2] == '.')
        ans += ways (x - 2, y - 2)%1000007;

    if (x - 1 >= 0 && y + 1 < N && grid[x - 1][y+1] == '.')
        ans += ways (x - 1, y + 1)%1000007;
    else if (x - 2 >= 0 && y + 2 < N && grid[x - 1][y + 1] == 'B' && grid[x - 2][y + 2] == '.')
        ans += ways (x - 2, y + 2)%1000007;

    return memo[x][y] = ans%1000007;

}
int xW, yW;

int main() {
   // ofstream myf ("11957.txt");
    int T; cin >> T;
    int cont = 0;
    while (T--) {
        memset(memo, -1, sizeof memo);
        cont++;
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'W') {
                    xW = i; yW = j;
                }
            }
        }
        cout << "Case " << cont << ": ";
        cout << ways (xW, yW)%1000007 << endl;
        //myf << "Case " << cont << ": ";
        //myf << ways (xW, yW)%1000007 << endl;

    }


}
