#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, l, a, b;
vector<vector<int> > AdjList;
int main() {
    while (cin >> N, N) {
        AdjList.clear();
        AdjList.resize(N);
        cin >> l;
        for (int i = 0; i < l; i++) {
            cin >> a >> b;
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }
        queue<int> q;
        q.push(0);
        vector<int> color(N, 10000000); color[0] = 0;
        bool isBipartite = true;
        while (!q.empty() && isBipartite) {
            int u = q.front(); q.pop();
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (color[v] == 10000000) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    isBipartite = false;
                    break;
                }
            }
        }
        if (!isBipartite) cout << "NOT BICOLORABLE." << endl;
        else cout << "BICOLORABLE." << endl;
    }



}
