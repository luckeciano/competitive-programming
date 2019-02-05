#include <iostream>
#include <vector>
#include <fstream>
#define INF 0x3f3f3f3f
using namespace std;

typedef vector<long long> vi;
typedef pair<long long, long long> ii;
 vector<vector<pair<long long, long long> > > AdjList;
void buildCycle (long long u, vi &visited, vi &dist) {
        dist[u] = -INF;
        visited[u] = 1;
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (visited[v.first] == -1)
                buildCycle(v.first, visited, dist);
        }


}

int main() {
    //ofstream myf ("10449.txt");
    int n, r, a, b, q, x;
    vector<long long> j;

    int cont = 0;
    while (cin >> n) {
        cont ++;
        j.clear();
        AdjList.clear();
        AdjList.resize(n);
        j.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> j[i];
        }
        cin >> r;
        for (int i = 0; i < r; i++) {
            cin >> a >> b;
            AdjList[a - 1].push_back(make_pair(b - 1, (j[b - 1] - j[a - 1]) * (j[b - 1] - j[a - 1]) * (j[b - 1] - j[a - 1])));
        }
        vi dist(n, INF);
        vector<bool> hasNegativeCycle (n, false);
        if (n > 0) {
         dist[0] = 0;
            for (int i = 0; i < n - 1; i++) { // relax all E edges V-1 times
                for (int u = 0; u < n; u++) {// these two loops = O(E), overall O(VE)
                    for (int j = 0; j < (int)AdjList[u].size(); j++) {
                        ii v = AdjList[u][j]; // record SP spanning here if needed
                        if (dist[u] != INF)
                            dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax
                    }
                }
            }

            // after running the O(VE) Bellman Ford’s algorithm shown above

            for (int u = 0; u < n; u++) // one more pass to check
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (dist[v.first] > dist[u] + v.second && dist[u] != INF)  { // if this is still possible
                    dist[v.first] = -INF; // then negative cycle exists!
                }
            }

        }


        cin >> q;
        cout << "Set #" << cont << endl;
     //   myf <<  "Set #" << cont << endl;
        for (int i = 0; i < q; i++) {
            cin >> x;
            if (dist[x - 1] >= 3 && dist[x - 1] != INF)  {
                cout << dist[x - 1] << endl;
               //myf << dist[x - 1] << endl;
            }
            else {
                cout << "?" << endl;
               // myf << "?" << endl;
            }
        }
    }


}
