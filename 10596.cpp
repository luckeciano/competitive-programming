#include <iostream>
#include <vector>
using namespace std;
vector<int> visited;
vector<vector<int> > AdjList;
void dfs (int u) {
    visited[u] = 1;
    for (int i = 0; i < AdjList[u].size(); i++) {
        int v = AdjList[u][i];
        if (visited[v] == 0)
            dfs(v);
    }

}

int main() {
    int N, R, a, b;
    vector<int> nodes;
    while (cin >> N >> R) {
        nodes.clear();
        nodes.assign(N, 0);
        AdjList.clear(); AdjList.resize(N);
        for (int i = 0; i < R; i++) {
            cin >> a >> b;

            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
            nodes[a]++; nodes[b]++;

        }
        bool eulerian = true;
        if (R == 0) eulerian = false;
        for (int i = 0; i < N && eulerian; i++) {
            if (nodes[i]%2 != 0) eulerian = false;
        }
        if (eulerian) {
            int comp = 0;
            visited.assign(N, 0);
            for (int j = 0; j < N && eulerian; j++) {
                if (visited[j] == 0 && AdjList[j].size() != 0) {
                    comp++;
                    dfs(j);
                }
                if (comp > 1) eulerian = false;
            }
        }
        if (eulerian) cout << "Possible" << endl;
        else cout << "Not Possible" << endl;
    }

}
