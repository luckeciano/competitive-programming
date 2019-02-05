#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>
#define INF 10000000
using namespace std;
vector<int> visited;
int memo [30];
int w [30];

vector<vector<int> > AdjList;
int pert (int i) {
    visited[i] = 1;
    if (AdjList[i].size() == 0) return w[i];

    if (memo[i] != -1) return memo[i];

    int ans = 0;
    for (int j = 0; j < AdjList[i].size(); j++) {
        ans = max (ans,  w[i] + pert(AdjList[i][j]));
    }

    return memo[i] = ans;
}


int main() {
    int TC; cin >> TC;
    int N = 27;
    string aux;
    while (TC--) {
        memset(w, 0, sizeof w);
        AdjList.clear();
        AdjList.resize(N);
        scanf ("\n");
        while (1) {
            getline(cin, aux);
            if (aux.size() == 0) break;
            string num = "";
            int cont = 2;
            while (aux[cont] != ' ' && cont < aux.size()) {
                num.push_back(aux[cont]);
                cont++;
            }
            stringstream ss(num);
            int node; ss >> node;
            w[aux[0] - 'A'] = node;
            cont += 1;
            for (; cont < aux.size(); cont++) {
                AdjList[aux[cont] - 'A'].push_back(aux[0] - 'A');
                //cout << aux[cont] << "~" << aux[0] << endl;
            }
        }

        visited.assign (N, -1);
        memset(memo, -1, sizeof memo);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (visited[i] == -1) {
                ans = max (ans, pert(i));
            }
        }

        cout << ans << endl;
        if (TC != 0) cout << endl;
    }



}
