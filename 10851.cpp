#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;


int main() {
    int TC; cin >> TC;
    vector<string> txt;
    vector<int> sum;
    while (TC--) {
        txt.clear();
        string aux;
        scanf ("\n");
        while(true) {
            getline(cin, aux);
            if (aux.size() == 0) break;
            txt.push_back(aux);
        }
        int M = txt[0].size() - 2;
        sum.clear(); sum.assign(M + 1, 0);
        for (int i = 0; i <= M; i++) {
            for (int j = 1; j <= 8; j++) {
                if (txt[j][i] != '/') sum[i] += (1 << (j - 1));
            }
        }
        for (int i = 1; i <= M; i++) {
            cout << char(sum[i]);
        }
        cout << endl;

    }

}
