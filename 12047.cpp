#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

int N, M, s, t, p, a, b, c;
vi dijkstra (vector<vector<pair<int, int> > > AdjList, int s) {
    vi dist(N, INF); dist[s] = 0; // INF = 1B to avoid overflow
    priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
    while (!pq.empty()) { // main loop
        ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
        int d = front.first, u = front.second;
        if (d > dist[u]) continue; // this is a very important check
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j]; // all outgoing edges from u
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second; // relax operation
                pq.push(ii(dist[v.first], v.first));
    } } }

    return dist;
}

int main () {
    int TC; cin >> TC;
    //ofstream myf ("eitalu.txt");
    vector<vector<pair<int,int> > > AdjList, RevAdjList;
    vector<pair<int, pair<int, int> > > EdgeList;
    while (TC--) {
        AdjList.clear();
        RevAdjList.clear();
        EdgeList.clear();
        cin >> N >> M >> s >> t >> p;
        AdjList.resize(N);
        RevAdjList.resize(N);
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c;
            AdjList[a - 1].push_back(make_pair(b-1, c));
            RevAdjList[b - 1].push_back(make_pair(a - 1, c));
            EdgeList.push_back(make_pair(a-1, make_pair(b-1, c)));
        }
        vi dist = dijkstra(AdjList, s - 1);
        vi revDist = dijkstra(RevAdjList, t - 1);
        int maxEdge = -1;
        for (int i = 0; i < M; i++) {
            if (dist[EdgeList[i].first] + revDist[EdgeList[i].second.first] + EdgeList[i].second.second <= p &&
                EdgeList[i].second.second > maxEdge) {
                    maxEdge = EdgeList[i].second.second;
                }
        }
        cout << maxEdge << endl;
        //myf << maxEdge << endl;

    }




}
