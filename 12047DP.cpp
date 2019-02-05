#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int N, M, s, t, p, a, b, c;
vector<vector<pair<int, int> > > AdjList;
int memo[10005][10005];
int maxPath (int s, int t, int p, int val, int maxEdge) {
    if (val > p) return -1;

    if (s == t) return maxEdge;

    if (memo[s][t] != -2) return memo[s][t];
    int ans = -1;
    for (int j = 0; j < (int)AdjList[s].size(); j++) {
        ans = max (ans, maxPath(AdjList[s][j].first, t, p, val + AdjList[s][j].second, max(maxEdge, AdjList[s][j].second)));
    }

    return memo[s][t] = ans;
}



int main() {
    int TC; cin >> TC;
    ofstream myf ("eitalu.txt");

    while (TC--) {
        AdjList.clear();
        cin >> N >> M >> s >> t >> p;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                memo[i][j] = -2;
        AdjList.resize(N);
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c;
            AdjList[a - 1].push_back(make_pair(b-1, c));
        }

        cout << maxPath (s - 1, t - 1 , p, 0, -1) << endl;
        myf << maxPath (s - 1, t - 1 , p, 0, -1) << endl;
    }


}
