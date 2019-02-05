#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
#define INF 1000000
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
int n, w, a, b;
vector<vector<pair<int,int> > > AdjList;
bool checkPath (int a, int b, vi &visited) {
    visited[a] = 1;
    if (a == b) return true;
    bool ans = false;
    for (int j = 0; j < AdjList[a].size(); j++) {
        ii v = AdjList[a][j];
        if (visited[v.first] == -1) {
            ans = ans || checkPath(v.first, b, visited);
        }
    }

    return ans;




}

int main() {
  //  ofstream myf ("10557.txt");
    while (cin >> n, n != -1) {
        AdjList.clear();
        AdjList.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> w;
            cin >> a;
            for (int j = 0; j < a; j++) {
                cin >> b;
                AdjList[i].push_back(make_pair(b - 1, -w));
            }
        }
        int energy = 0;
        vi dist(n, INF); dist[0] = 0;
        for (int i = 0; i < n - 1; i++) { // relax all E edges V-1 times
            for (int u = 0; u < n; u++) { // these two loops = O(E), overall O(VE)
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                    ii v = AdjList[u][j]; // record SP spanning here if needed
                    if (dist[v.first] > dist[u] + v.second && dist[u] + v.second < 100) {
                        dist[v.first] = dist[u] + v.second;
                    }
                }
            }
        }
                // after running the O(VE) Bellman Ford’s algorithm shown above
        bool hasNegativeCycle = false;
        for (int u = 0; u < n; u++) {// one more pass to check
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (dist[v.first] > dist[u] + v.second && dist[u] + v.second < 100) { // if this is still possible
                    vi visited (n, -1);
                    bool isOk;
                    isOk = checkPath(0, v.first, visited);
                    for (int i = 0; i < n; i++) visited [i] = -1;
                    bool isOk2 = checkPath (v.first, n - 1, visited);
                    if (isOk && isOk2) hasNegativeCycle = true;
                }
            }
        }
        bool winnable = true;

        if (dist[n - 1] < 100 || hasNegativeCycle) {
            cout << "winnable" << endl;
            //myf << "winnable" << endl;
        } else { cout << "hopeless" << endl;
            //myf << "hopeless" << endl;
        }
    }



}
