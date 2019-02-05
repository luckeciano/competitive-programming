#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, l, a, b;
int TC, V, e, g;
int white, black;
vector<vector<int> > AdjList;
vector<int> visited;
bool checkBipartite (int t) {
        queue<int> q;
        q.push(t);
        visited[t] = 1;
        vector<int> color(V, 10000000); color[t] = 0;
        white++;
        bool isBipartite = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            visited[u] = 1;
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                visited[v] = 1;

                if (color[v] == 10000000) {
                    color[v] = 1 - color[u];
                    if (color[v] == 0) white++;
                    else black++;
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    isBipartite = false;
                }
            }
        }
    return isBipartite;
}

int main() {
    cin >> TC;
    while (TC--) {
        cin >> V >> e;
        AdjList.clear();
        visited.clear();
        AdjList.resize(V);
        for (int i = 0; i < V; i++) {
            visited.push_back(0);
        }
        for (int i = 0; i < e; i++) {
            cin >> a >> b;
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }

        g = 0;
        for (int i = 0; i < V; i++) {
            white = 0; black = 0;
            if (visited[i] == 0 && g >= 0) {
                if (checkBipartite(i)) {
                    if (white == 1 && black == 0)
                        g++;
                    else g += min(white, black);
                } else g = -1;
            }
        }

        if (g <= 0) cout << -1 << endl;
        else cout << g << endl;
    }


}
