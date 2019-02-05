#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int V, a, b;
vector<vector<int> > AdjList;
int main() {
    while (cin >> V, V) {
        AdjList.clear();
        AdjList.resize(V);
        while (cin >> a >> b, a || b) {
            AdjList[a-1].push_back(b-1);
            AdjList[b-1].push_back(a-1);
        }

        queue<int> q;
        q.push(0);
        vector<int> color(V, 10000000); color[0] = 0;
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
        if (!isBipartite) cout << "NO" << endl;
        else cout << "YES" << endl;
    }


}
