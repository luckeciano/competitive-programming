#include <cstdio>
#include <vector>

using namespace std;
vector<vector<int> > graph;
int visited[105];
int n, m; int a, b;

vector<int>  ts; // global vector to store the toposort in reverse order
void dfs2(int u) { // different function name compared to the original dfs
    visited[u] = 1;
    for (int j = 0; j < (int)graph[u].size(); j++) {
        int v = graph[u][j];
        if (visited[v] == 0)
            dfs2(v);
    }
    ts.push_back(u); } // that’s it, this is the only change




int main() {
    while (scanf ("%d %d", &n, &m), m || n) {
        graph.resize(n);
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            scanf ("%d %d", &a, &b);
            graph[a - 1].push_back(b - 1);
        }
        ts.clear();
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs2(i);
            }
        }

        for (int i = ts.size() - 1; i >= 0; i--) {
            printf ("%d", ts[i] + 1);
            if (i != 0) printf (" ");
        }
        printf ("\n");



    }



}
