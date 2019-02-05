#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
vector<vector<pair<int,int> > > AdjList;
int N, M;

int dijkstra (int s, int w) {
    vi dist(N*M, INF); dist[s] = w; // INF = 1B to avoid overflow
    priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(w, s));
    while (!pq.empty()) { // main loop
        ii frontE = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
        int d = frontE.first, u = frontE.second;
        if (d > dist[u]) continue; // this is a very important check
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j]; // all outgoing edges from u
            if (dist[u] + v.second < dist[v.first]) {
            dist[v.first] = dist[u] + v.second; // relax operation
            pq.push(ii(dist[v.first], v.first));
    } } }
    return dist[N*M - 1];
}

int grid[1005][1005];

int main() {
    int TC; cin >> TC;
    while (TC--) {
        AdjList.clear();
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> grid[i][j];
            }
        }
        AdjList.resize(N*M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (i - 1 >= 0)
                    AdjList[i*M + j].push_back(make_pair((i-1)*M + j, grid[i-1][j]));
                if (j - 1 >= 0)
                    AdjList[i*M + j].push_back(make_pair((i)*M + j - 1, grid[i][j-1]));
                if (i + 1 < N)
                    AdjList[i*M + j].push_back(make_pair((i+1)*M + j, grid[i+1][j]));
                if (j + 1 < M)
                    AdjList[i*M + j].push_back(make_pair((i)*M + j + 1, grid[i][j+1]));
            }
        }

        cout << dijkstra (0, grid[0][0]) << endl;

    }




}
