#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
vector<vector<pair<int,int> > > AdjList;
int N, E, T, a, b, w, nEdges;
int dijkstra(int s, int f) {
      // Dijkstra routine
  vi dist(N, INF); dist[s] = 0;                    // INF = 1B to avoid overflow
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
                             // ^to sort the pairs by increasing distance from s
  while (!pq.empty()) {                                             // main loop
    ii front = pq.top(); pq.pop();     // greedy: pick shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d > dist[u]) continue;   // this check is important, see the explanation
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      ii v = AdjList[u][j];                       // all outgoing edges from u
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second;                 // relax operation
        pq.push(ii(dist[v.first], v.first));
  } } }

  return dist[f];
}

int main () {
    int TC; cin >> TC;
    while (TC --) {
        AdjList.clear();
        cin >> N >> E >> T;
        cin >> nEdges;
        AdjList.resize(N);
        for (int i = 0; i < nEdges; i++) {
            cin >> a >> b >> w;
            AdjList[a - 1].push_back(make_pair(b-1, w));
        }
        int mice = 0;
        for (int i = 0; i < N; i++) {
            int t = dijkstra(i, E - 1);
            if ( t <= T) mice++;
        }

        cout << mice << endl;
        if (TC != 0) cout << endl;
    }


}
