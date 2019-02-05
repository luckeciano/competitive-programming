#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <set>
#define INF 1000000
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
vector<vector<pair<int,int> > > AdjList;
int n, k;
int dijkstra(int s, int f) {
      // Dijkstra routine
  vi dist(100*n, INF); dist[s] = 0;                    // INF = 1B to avoid overflow
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
    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min (ans, dist[100*i + f]);
    }
  return ans;
}


vector<int> t;
vector<set<int> > elevator;
int aux;
int main() {
    while (cin >> n >> k) {
        t.clear();
        t.resize(n);
        elevator.clear();
        elevator.resize(n);
        AdjList.clear();
        AdjList.resize(100*n);
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }

        for (int i = 0; i < n; i++) {
            scanf ("\n");
            while (cin.peek() != '\n') {
                cin >> aux;
                elevator[i].insert(aux);
            }
        }
        set<int>::iterator it1, it2;
        for (int i = 0; i < n; i++) {

            for (it1 = elevator[i].begin(); it1 != elevator[i].end(); it1++) {
                for (it2 = next(it1); it2 != elevator[i].end(); it2 ++) {
                    AdjList[100*i + *it1].push_back(make_pair(100*i + *it2,t[i] * (*it2 - *it1)));
                    AdjList[100*i + *it2].push_back(make_pair(100*i + *it1, t[i] * (*it2 - *it1)));
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (it1 = elevator[i].begin(); it1 != elevator[i].end(); it1++) {
                    if (elevator[j].find(*it1) != elevator[j].end()) {
                        AdjList[100*i + *it1].push_back(make_pair(100*j + *it1, 60));
                        AdjList[100*j + *it1].push_back(make_pair(100*i + *it1, 60));
                    }
                }
            }
        }

       /* for (int i = 0; i < 100; i++) {
            cout << "node " << i << endl;
            for (int j =0 ; j < AdjList[i].size(); j++) {
                cout << AdjList[i][j].first << " ";
            }
            cout << endl;
        }*/
        int ans = INF;
        for (int i = 0; i < n; i++) {
            ans = min (ans, dijkstra(100*i, k));
        }
        if (ans == INF) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;



    }


}
