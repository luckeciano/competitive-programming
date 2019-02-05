#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dfs_low, dfs_num, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;
vector<vector<int> > AdjList;
vector<int> visited;
int N, m, a, b;
vector<pair<int, int> > res;
int pidgeon;
bool compare(pair<int, int> a, pair<int, int>  b) {
    if (a.first != b.first) {
        return a.first >= b.first;
    } else if (a.second != b.second) {
        return a.second <= b.second;
    }
    return true;

}

void dfs(int u) {
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (visited[v] == 0)
            dfs(v);
    }
}

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == -1) { // a tree edge
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++; // special case if u is a root

            articulationPointAndBridge(v);

            if (dfs_low[v] >= dfs_num[u]) // for articulation point
                articulation_vertex[u] = true; // store this information first
            if (dfs_low[v] > dfs_num[u]) { // for bridge
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
        }
        else if (v != dfs_parent[u]) // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update dfs_low[u]
    }
}



int main() {
    while (cin >> N >> m, N || m) {
        AdjList.clear();
        AdjList.resize(N);
        while (cin >> a >> b, !(a == -1 && b == -1)) {
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }

        dfsNumberCounter = 0; dfs_num.assign(N, -1); dfs_low.assign(N, 0);
        dfs_parent.assign(N, 0); articulation_vertex.assign(N, 0);
        for (int i = 0; i < N; i++) {
            if (dfs_num[i] == -1) {
                dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1); } // special case
        }
        res.clear();
        for (int i = 0; i < N; i++) {
            if (articulation_vertex[i]) {
                pidgeon = 0;
                visited.assign(N, 0);
                visited[i] = 1;
                for (int k = 0; k < N; k++) {
                    if (visited[k] == 0) {
                        pidgeon++;
                        dfs(k);
                    }
                }
                res.push_back(make_pair(pidgeon, i));
            } else res.push_back(make_pair(1, i));
        }

        sort(res.begin(), res.end(), compare);
        for (int i = 0; i < m; i++) {
            cout << res[i].second << " " << res[i].first << endl;
        }
        cout << endl;

    }



}
