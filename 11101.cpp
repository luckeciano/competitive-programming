#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define INF 10000000
using namespace std;
int R, C, m1, m2;
int shortestPath(vector<pair<int, int> > source , set<int> dest) {
    vector<int> dist(R*C, INF); queue<int> q; // distance from source s to s is 0
    for (int i = 0; i < source.size(); i++) {
        int u = source[i].first*C + source[i].second;
        dist[u] = 0;
        q.push(u);
    }
    int reach = 0;
     while (!q.empty() && reach != dest.size()) {

        int u = q.front(); q.pop() ; int thisR = u/C; int thisC = u%C;
        if (thisR - 1 >= 0 && dist[(thisR - 1)*C + thisC] == INF) {
                dist[(thisR - 1)*C + thisC] = dist[thisR*C + thisC] + 1;
                if (dest.find((thisR - 1)*C + thisC) != dest.end()) reach++;
                q.push((thisR - 1)*C + thisC);
        }

        if (thisC - 1 >= 0 &&  dist[(thisR)*C + thisC - 1] == INF) {
                if (dest.find((thisR)*C + thisC - 1) != dest.end()) reach++;
                dist[(thisR)*C + thisC - 1] = dist[thisR*C + thisC] + 1;
                q.push((thisR)*C + thisC - 1);
        }

        if (thisC + 1 < C  &&  dist[(thisR)*C + thisC + 1] == INF) {
                dist[(thisR)*C + thisC + 1] = dist[thisR*C + thisC] + 1;
                if (dest.find((thisR)*C + thisC + 1) != dest.end()) reach++;
                q.push((thisR)*C + thisC + 1);
        }

        if (thisR + 1 < R  &&   dist[(thisR + 1)*C + thisC] == INF) {
                dist[(thisR + 1)*C + thisC] = dist[thisR*C + thisC] + 1;
                if (dest.find((thisR + 1)*C + thisC) != dest.end()) reach++;
                q.push((thisR + 1)*C + thisC);
        }


    }
    int ans = INF;
    set<int>::iterator it;
    for (it = dest.begin(); it != dest.end(); it++) {
        int u = *it;
        ans = min(ans, dist[u]);
    }
    return ans;


}
int a, b;

int main() {
    R = 2001; C = 2001;
    vector<pair<int,int> > source;
    set<int> dest;
    while (cin >> m1, m1) {
        source.clear();
        dest.clear();
        for (int i = 0; i < m1; i++) {
            cin >> a >> b;
            source.push_back(make_pair(a, b));
        }
        cin >> m2;
        for (int i  =0 ; i < m2; i++) {
            cin >> a >> b;
            //dest.push_back(make_pair(a,b));
            dest.insert(a*C + b);
        }

        int ans = shortestPath(source, dest);


        cout << ans << endl;
    }


}
