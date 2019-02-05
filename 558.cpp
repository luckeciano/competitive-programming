#include <iostream>
#include <vector>
#define INF 100000
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
    int TC;
    cin >> TC;
    int n, m, a, b, c;
    vector<vector<pair<int, int> > > AdjList;
    while (TC--) {
        cin >> n >> m;
        AdjList.clear();
        AdjList.resize(n);
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            AdjList[a].push_back(make_pair(b, c));
        }

        vi dist(n, INF); dist[0] = 0;
        for (int i = 0; i < n - 1; i++) // relax all E edges V-1 times
            for (int u = 0; u < n; u++) // these two loops = O(E), overall O(VE)
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                    ii v = AdjList[u][j]; // record SP spanning here if needed
                    dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax
                }

                // after running the O(VE) Bellman Ford’s algorithm shown above
        bool hasNegativeCycle = false;
        for (int u = 0; u < n; u++) // one more pass to check
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (dist[v.first] > dist[u] + v.second) // if this is still possible
                    hasNegativeCycle = true; // then negative cycle exists!
            }
        if (hasNegativeCycle) cout << "possible" << endl;
        else cout << "not possible" << endl;
    }


}
