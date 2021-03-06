#include <iostream>
#include <queue>
#include <vector>

#define INF 10000000
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair <int, int> > vii;
vector<vii> AdjList;

int main() {
    int V; //Number of vertex
    int s; //source vertex
    // inside int main()---no recursion
    vi d(V, INF); d[s] = 0; // distance from source s to s is 0
    queue<int> q; q.push(s); // start from source

    while (!q.empty()) {
        int u = q.front(); q.pop(); // queue: layer by layer!
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j]; // for each neighbor of u
        if (d[v.first] == INF) { // if v.first is unvisited + reachable
            d[v.first] = d[u] + 1; // make d[v.first] != INF to flag it
            q.push(v.first); // enqueue v.first for the next iteration
    } } }




}
