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
  // BFS routine
  // inside int main() -- we do not use recursion, thus we do not need to create separate function!
  vi dist(V, 1000000000); dist[s] = 0;      // distance to source is 0 (default)
  queue<int> q; q.push(s);                                  // start from source
  int layer = -1;                             // for our output printing purpose
  bool isBipartite = true;       // addition of one boolean flag, initially true

  while (!q.empty()) {
    int u = q.front(); q.pop();                        // queue: layer by layer!
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      ii v = AdjList[u][j];                           // for each neighbors of u
      if (dist[v.first] == 1000000000) {
        dist[v.first] = dist[u] + 1;                  // v unvisited + reachable
        q.push(v.first);                              // enqueue v for next step
      }
      else if ((dist[v.first] % 2) == (dist[u] % 2))              // same parity
        isBipartite = false;
  } }


}
