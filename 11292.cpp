#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    int heads[20005];
    int k [20005];
    while(cin >> n >> m, n || m) {
        for (int i = 0; i < n; i++) {
            cin >> heads[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> k[i];
        }
        sort (heads, heads + n);
        sort (k, k + m);
        int p = 0;
        bool doomed = false;
        int gold = 0;
        bool found;
        for (int i = 0; i < n && !doomed; i++) {
            found = false;
            while (!found && p < m) {
                if (k[p] >= heads[i]) {
                    gold += k[p];
                    found = true;
                }
                p++;
            }
            if (!found) doomed = true;
        }
        if (doomed) cout << "Loowater is doomed!" << endl;
        else cout << gold << endl;
    }


}
