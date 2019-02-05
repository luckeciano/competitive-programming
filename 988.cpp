#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int memo[50];
vector<vector<int> > AdjList;
int n,b;
int ways (int k) {
    if (AdjList[k].size() == 0) return 1;
    if (memo[k] != -1) return memo[k];
    int ans = 0;
    for (int i = 0; i < AdjList[k].size(); i++) {
        ans += ways (AdjList[k][i]);
    }
    return memo[k] = ans;

}

int main() {
    int cont = 0;
    while (cin >> n) {
        if (cont) cout << endl;
        cont++;
        memset(memo, -1, sizeof memo);
        AdjList.clear();
        AdjList.resize(n);
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                cin >> b;
                AdjList[i].push_back(b);
            }
        }
        cout << ways(0) << endl;
    }



}
