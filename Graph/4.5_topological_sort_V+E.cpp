#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define UNVISITED 0
#define VISITED 1


typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming

vi ts; // global vector to store the toposort in reverse order
vi dfs_num;
vector<vii> AdjList;
int V; //number of vertices
void dfs2(int u) { // different function name compared to the original dfs

    dfs_num[u] = VISITED;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED)
            dfs2(v.first);
    }

ts.push_back(u); } // that’s it, this is the only change


int main() {
    // inside int main()
    ts.clear();
    dfs_num.assign(V, UNVISITED);
    for (int i = 0; i < V; i++) // this part is the same as finding CCs
        if (dfs_num[i] == UNVISITED)
            dfs2(i);
    // alternative, call: reverse(ts.begin(), ts.end()); first
    for (int i = (int)ts.size() - 1; i >= 0; i--) // read backwards
        printf(" %d", ts[i]);
    printf("\n");


}
