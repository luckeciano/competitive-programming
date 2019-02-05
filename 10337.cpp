#include <iostream>
#include <cstring>

using namespace std;

int memo[1005][11];
int wind [1005][1005];
int n;

int fuel (int K, int H) {

    if (K == n && H == 0) return 0;
    else if (K == n) return 1000000;

    if (memo[K][H] != -1) return memo[K][H];
    int ans = 10000000;
    ans =  min(ans, fuel(K + 1, H) + 30 - wind[K][H]);
    if (H + 1 <= 9)
        ans = min (ans, fuel (K + 1, H + 1) + 60 - wind[K][H]);
    if (H - 1 >= 0)
        ans = min (ans, fuel (K + 1, H - 1) + 20 - wind[K][H]);

    return memo[K][H] = ans;
}


int main() {
    int TC;
    cin >> TC;
    while (TC--){
        memset (memo, -1, sizeof memo);
        cin >> n;
        n = n/100;
        for (int i = 9; i >= 0 ; i--) {
            for (int j = 0; j < n; j++) {
                cin >> wind [j][i];
            }
        }

        cout << fuel (0, 0) << endl;
        cout << endl;
    }


}
