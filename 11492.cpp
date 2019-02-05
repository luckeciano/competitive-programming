#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
#include <string>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
int M;
vector<pair<string, pair<string, string> > > EdgeList;
vector<vector<pair<int,int> > > AdjList;
string start, last, a, b, w;
int dijkstra (int s) {
    vi dist(M, INF); dist[s] = EdgeList[s].first.size(); // INF = 1B to avoid overflow
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
    int ans = INF;
    for (int i = 0; i < M; i++) {
        if (EdgeList[i].second.first == last || EdgeList[i].second.second == last) {
            ans = min (ans, dist[i]);
        }
    }
    return ans;

}

int main() {
    while (cin >> M, M) {
        EdgeList.clear();
        AdjList.clear();
        AdjList.resize(M);
        cin >> start >> last;
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> w;
            pair<string, pair<string, string> > edge;
            edge.first = w; edge.second.first = a; edge.second.second = b;
            EdgeList.push_back(edge);
        }

        for (int i = 0; i < M; i++) {
            for (int j = i + 1; j < M; j++) {
                if (EdgeList[i].second.first == EdgeList[j].second.first ||
                    EdgeList[i].second.second == EdgeList[j].second.first ||
                    EdgeList[i].second.first == EdgeList[j].second.second ||
                    EdgeList[i].second.second == EdgeList[j].second.second) {
                        if (EdgeList[i].first[0] != EdgeList[j].first[0]) {
                            AdjList[i].push_back(make_pair(j, EdgeList[j].first.size()));
                            AdjList[j].push_back(make_pair(i, EdgeList[i].first.size()));
                        }


                    }
            }
        }
        int ans = INF;
        for (int i = 0; i < M; i++) {
            if (EdgeList[i].second.first == start || EdgeList[i].second.second == start) {
                ans = min (ans, dijkstra (i));
            }
        }

        if (ans == INF) cout << "impossivel" << endl;
        else cout << ans << endl;
    }


}
