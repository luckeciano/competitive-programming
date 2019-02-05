#include <iostream>
#include <vector>

using namespace std;

vector<int> dfs_num, dfs_low, S, visited;
vector<vector<int> > AdjList;
int dfsNumberCounter, numSCC;
int N, M, a, b, P;


void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    S.push_back(u); // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == -1)
        tarjanSCC(v);
        if (visited[v]) // condition for update
        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
        ++numSCC;
        //printf("SCC %d:", ++numSCC); // this part is done after recursion
        bool first = true;
        while (1) {
            int k = S.back(); S.pop_back(); visited[k] = 0;
            if (u == k) break;
        }
    }
}


int main() {
    while (cin >> N >> M , N || M) {
        AdjList.clear();
        AdjList.resize(N);
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> P;
            AdjList[a - 1].push_back(b - 1);
            if ( P == 2) AdjList[b - 1].push_back(a - 1);
        }

        dfs_num.assign(N, -1); dfs_low.assign(N, 0); visited.assign(N, 0);
        dfsNumberCounter = numSCC = 0;
        for (int i = 0; i < N; i++)
            if (dfs_num[i] == -1)
                tarjanSCC(i);

        if (numSCC == 1) cout << 1 << endl;
        else cout << 0 << endl;

    }


}
