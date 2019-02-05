#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000
using namespace std;

int R, C, r, a, b, n;
int grid[1005][1005];
int shortestPath(int iR, int iC, int fR, int fC) {
    vector<int> dist(R*C, INF); dist[iR*C + iC] = 0; // distance from source s to s is 0
    queue<int> q; q.push(iR*C + iC);
     while (!q.empty() && q.front() != fR*C + fC) {

        int u = q.front(); q.pop() ; int thisR = u/C; int thisC = u%C;
        if (thisR - 1 >= 0 && grid[thisR-1][thisC] != 1 && dist[(thisR - 1)*C + thisC] == INF) {
                dist[(thisR - 1)*C + thisC] = dist[thisR*C + thisC] + 1;
                q.push((thisR - 1)*C + thisC);
        }

        if (thisC - 1 >= 0 && grid[thisR][thisC - 1] != 1 && dist[(thisR)*C + thisC - 1] == INF) {
                dist[(thisR)*C + thisC - 1] = dist[thisR*C + thisC] + 1;
                q.push((thisR)*C + thisC - 1);
        }

        if (thisC + 1 < C && grid[thisR][thisC + 1] != 1 &&  dist[(thisR)*C + thisC + 1] == INF) {
                dist[(thisR)*C + thisC + 1] = dist[thisR*C + thisC] + 1;
                q.push((thisR)*C + thisC + 1);
        }

        if (thisR + 1 < R  && grid[thisR+1][thisC] != 1 &&  dist[(thisR + 1)*C + thisC] == INF) {
                dist[(thisR + 1)*C + thisC] = dist[thisR*C + thisC] + 1;
                q.push((thisR + 1)*C + thisC);
        }


    }
    return dist[fR*C + fC];


}


int main() {
    while (cin >> R >> C, R || C) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++)
                grid[i][j] = 0;
        }
        cin >> r;
        for (int i = 0; i < r; i++) {
            cin >> a >> n;
            for (int j = 0; j < n; j++) {
                cin >> b;
                grid[a][b] = 1;
            }
        }

        int iR, iC, fR, fC;
        cin >> iR >> iC;
        cin >> fR >> fC;

        cout << shortestPath(iR, iC, fR, fC) << endl;
    }


}
