#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> AdjList;
int R, C;
int shortestPath(int a, int b) {
    vector<int> dist(AdjList.size(), 10000000);
    dist[a] = 0;
    queue<int> q; q.push(a);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            int v = AdjList[u][j];
            if (dist[v] == 10000000) {
                dist[v] = dist[u] + 1;
                q.push(v);
        } } }
    int ans = min(dist[b], min(dist[b + R*C], min(dist[b + 2*R*C], dist[b + 3*R*C])));
    return ans;
}
int grid[205][205];

int main() {
    while (cin >> R >> C, R || C) {
        AdjList.clear();
        for (int i = 0; i < R + 1; i++) {
            for (int j = 0; j < C + 1; j++) {
                grid[i][j] = 0;
                if (i == 0 || i == R || j == 0 || j == C)
                    grid[i][j] = 1;
            }
        }
        int aux;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j ++) {
                cin >> aux;
                if (aux == 1) {
                    grid[i][j] = 1;
                    grid[i + 1][j] = 1;
                    grid[i][j + 1] = 1;
                    grid[i + 1][j + 1] = 1;
                }
            }
        }
        R++; C++;
        /*for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }*/

        int iR, iC, fR, fC;
        cin >> iR >> iC >> fR >> fC;
        string ori;
        cin >> ori;

        AdjList.resize(4*R * C);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 0) {
                //go
                    //north
                    if (i - 1 >= 0 && grid[i-1][j] == 0)
                        AdjList[i*C + j].push_back((i - 1)* C + j);
                    if (i - 2 >= 0 && grid[i - 1][j] == 0 && grid[i - 2][j] == 0)
                        AdjList[i*C + j].push_back((i - 2)*C + j);
                    if (i - 3 >= 0 && grid[i - 1][j] == 0 && grid[i - 2][j] == 0 && grid[i - 3][j] == 0)
                        AdjList[i*C + j].push_back((i - 3)*C + j);
                    //south
                    if (i + 1 < R && grid[i+1][j] == 0)
                        AdjList[R*C + (i*C + j)].push_back(R*C + (i + 1)* C + j);
                    if (i + 2 < R && grid[i + 1][j] == 0 && grid[i + 2][j] == 0)
                        AdjList[R*C + (i*C + j)].push_back(R*C + (i + 2)*C + j);
                    if (i + 3 < R && grid[i + 1][j] == 0 && grid[i + 2][j] == 0 && grid[i + 3][j] == 0)
                        AdjList[R*C + (i*C + j)].push_back(R*C + (i + 3)*C + j);
                    //west
                    if (j - 1 >= 0 && grid[i][j-1] == 0)
                        AdjList[2*R*C + (i*C + j)].push_back(2*R*C + (i)* C + j - 1);
                    if (j - 2 >= 0 && grid[i][j-1] == 0 && grid[i][j - 2] == 0)
                        AdjList[2*R*C + (i*C + j)].push_back(2*R*C + (i)* C + j - 2);
                    if (j - 3 >= 0 && grid[i][j-1] == 0 && grid[i][j - 2] == 0 && grid[i][j - 3] == 0)
                        AdjList[2*R*C + (i*C + j)].push_back(2*R*C + (i)* C + j - 3);

                    //east
                    if (j + 1 < C  && grid[i][j+1] == 0)
                        AdjList[3*R*C + (i*C + j)].push_back(3*R*C + (i)* C + j + 1);
                    if (j + 2 < C  && grid[i][j+1] == 0 && grid[i][j + 2] == 0)
                        AdjList[3*R*C + (i*C + j)].push_back(3*R*C + (i)* C + j + 2);
                    if (j + 3 < C && grid[i][j+1] == 0 && grid[i][j + 2] == 0 && grid[i][j + 3] == 0)
                        AdjList[3*R*C + (i*C + j)].push_back(3*R*C + (i)* C + j + 3);

                //turn
                        //1 -- 3
                    AdjList[i*C + j].push_back(2*R*C + (i*C + j));
                    AdjList[2*R*C + (i*C + j)].push_back((i*C + j));
                        //1 -- 4
                    AdjList[i*C + j].push_back(3*R*C + (i*C + j));
                    AdjList[3*R*C + (i*C + j)].push_back((i*C + j));
                        //2 -- 3
                    AdjList[R*C + (i*C + j)].push_back(2*R*C + (i*C + j));
                    AdjList[2*R*C + (i*C + j)].push_back(R*C + (i*C + j));
                        //2 -- 4
                    AdjList[R*C + (i*C + j)].push_back(3*R*C + (i*C + j));
                    AdjList[3*R*C + (i*C + j)].push_back(R*C + (i*C + j));

                }
            }
        }/*
        cout << "edges from 0 NORTH" << endl;
        for (int i = 0; i < AdjList[6*C + 8].size(); i++) {
            int k = AdjList[6*C + 8][i];
            cout << k/C << " " << k%C << endl;
        }
         cout << "edges from 0 SOUTH" << endl;
        for (int i = 0; i < AdjList[6*C + 8 + R*C].size(); i++) {
            int k = AdjList[6*C + 8 + R*C][i];
            cout << k/C << " " << k%C << endl;
        }
         cout << "edges from 0 WEST" << endl;
        for (int i = 0; i < AdjList[6*C + 8+ 2*R*C].size(); i++) {
            int k = AdjList[6*C + 8 + 2*R*C][i];
            cout << k/C << " " << k%C << endl;
        }
         cout << "edges from 0 EAST" << endl;
        for (int i = 0; i < AdjList[6*C + 8 + 3*R*C].size(); i++) {
            int k = AdjList[6*C + 8 + 3*R*C][i];
            cout << k/C << " " << k%C << endl;
        }*/

        int start = iR*C + iC;
        if (ori == "south") start += R*C;
        else if (ori == "west") start += 2*R*C;
        else if (ori == "east") start += 3*R*C;
        int endV = fR*C + fC;

        int res = shortestPath(start, endV);
        if (res == 10000000) cout << -1 << endl;
        else cout << res << endl;
    }




}
