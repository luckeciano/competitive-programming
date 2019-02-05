#include <queue>
#include <vector>
#define INF 100000000


using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;

int V; //number of vertices
int s; //source vertex

vector<vii> AdjList;

int main() {
    // inside int main()
    queue<int> q; q.push(s);
    vi color(V, INF); color[s] = 0;
    bool isBipartite = true; // addition of one boolean flag, initially true
    while (!q.empty() & isBipartite) { // similar to the original BFS routine
        int u = q.front(); q.pop();
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (color[v.first] == INF) { // but, instead of recording distance,
                color[v.first] = 1 - color[u]; // we just record two colors {0, 1}
                q.push(v.first); }
            else if (color[v.first] == color[u]) { // u & v.first has same color
                isBipartite = false; break; } } } // we have a coloring conflict



}
