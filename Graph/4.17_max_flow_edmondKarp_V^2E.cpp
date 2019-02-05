///MAX FLOW APPLICATIONS
    ///MINIMUM CUT:
        ///CUT-SET: Let’s define an s-t cut C = (S-component, T-component) as a partition of V ∈ G such that
        ///source s ∈ S-component and sink t ∈ T-component. Let’s also define a cut-set of C to be the
        ///set {(u, v) ∈ E | u ∈ S-component, v ∈ T-component} such that if all edges in the cut-set
        ///of C are removed, the Max Flow from s to t is 0 (i.e. s and t are disconnected).
        ///The cost of an s-t cut C is defined by the sum of the capacities of the edges in the cut-set of C.
        ///SOLUTION: THE MAX FLOW ITSELF!

    /// MULTIPLE SOURCE/SINK: CREATE A SUPER SOURCE/SINK; CONNECT SUPER SOURCE/SINK SS/ST WITH ALL S/T WITH INFINITE CAPACITY.

    ///VERTEX CAPACITY: SPLIT VERTEX IN TWO VERTICES AND A EDGE BETWEEN THEM. THE WEIGHT OF THE EDGE WILL BE THE WEIGHT OF INITIAL VERTEX




#include <algorithm>
#include <bitset>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef vector<int> vi;

#define MAX_V 40 // enough for sample graph in Figure 4.24/4.25/4.26/UVa 259
#define INF 1000000000

int res[MAX_V][MAX_V], mf, f, s, t;                          // global variables
vi p;
vector<vi> AdjList;

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
  if (v == s) { f = minEdge; return; }  // record minEdge in a global variable f
  else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v])); // recursive
                         res[p[v]][v] -= f; res[v][p[v]] += f; }       // update
}

int main() {
  int V, k, vertex, weight;

  scanf("%d %d %d", &V, &s, &t);

  memset(res, 0, sizeof res);
  AdjList.assign(V, vi());
  for (int i = 0; i < V; i++) {
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d %d", &vertex, &weight);
      res[i][vertex] = weight;
      AdjList[i].push_back(vertex);
    }
  }

  mf = 0;
  while (1) {                     // now a true O(VE^2) Edmonds Karp's algorithm
    f = 0;
    bitset<MAX_V> vis; vis[s] = true;            // we change vi dist to bitset!
    queue<int> q; q.push(s);
    p.assign(MAX_V, -1);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;
      for (int j = 0; j < (int)AdjList[u].size(); j++) {  // we use AdjList here!
        int v = AdjList[u][j];
        if (res[u][v] > 0 && !vis[v])
          vis[v] = true, q.push(v), p[v] = u;
      }
    }
    augment(t, INF);
    if (f == 0) break;
    mf += f;
  }

  printf("%d\n", mf);                              // this is the max flow value

  return 0;
}
