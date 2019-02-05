#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 10000000
using namespace std;
int N, k, a;
vector<vector<int> > AdjList;
vector<int> vMinMax, vMaxMax;
int main() {
    while (cin >> N) {
        vMinMax.clear();
        vMaxMax.clear();
        AdjList.clear();
        AdjList.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> k;
            for (int j = 0; j < k; j++) {
                cin >> a;
                AdjList[i].push_back(a-1);
                //AdjList[a - 1].push_back(i);
            }
        }
            int nodeA, nodeB;
            int maxDist = 0; int node = 0;
            vector<int> distA(N, INF); distA[0] = 0; // distance from source s to s is 0
            queue<int> q; q.push(0);
            //vector<int> p; // addition: the predecessor/parent vector
            while (!q.empty()) {
            int u = q.front(); q.pop();
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (distA[v] == INF) {
                    distA[v] = distA[u] + 1;
                    if (distA[v] > maxDist) {
                        maxDist = distA[v];
                        nodeA = v;
                    }
                    q.push(v);
            } } }



            vector<int> distB(N, INF);
            distB[nodeA] = 0;
            maxDist = 0;
            q.push(nodeA);
            while (!q.empty()) {
            int u = q.front(); q.pop();
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (distB[v] == INF) {
                    distB[v] = distB[u] + 1;
                    if (distB[v] > maxDist) {
                        maxDist = distB[v];
                        nodeB = v;
                        //vMaxMax.clear();
                        //vMaxMax.push_back(v + 1);
                    } //else if (distB[v] == maxDist) vMaxMax.push_back(v + 1);
                    q.push(v);
            } } }

            vector<int> dist(N, INF);
            dist[nodeB] = 0;
            q.push(nodeB);
            while (!q.empty()) {
            int u = q.front(); q.pop();
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
            } } }


            int midDist = distB[nodeB]/2;
            for (int i = 0; i < N; i++) {
                if (dist[i] == midDist && distB[i] == midDist ||
                    dist[i] == midDist && distB[i] == midDist + 1 ||
                    dist[i] == midDist + 1 && distB[i] == midDist)
                    vMinMax.push_back(i + 1);
            }
            maxDist = 0;
            for (int i = 0; i < vMinMax.size(); i++) {

                int k = vMinMax[i] - 1;
                vector<int> dist(N, INF);
                dist[k] = 0;
                q.push(k);
                while (!q.empty()) {
                int u = q.front(); q.pop();
                    for (int j = 0; j < (int)AdjList[u].size(); j++) {
                    int v = AdjList[u][j];
                    if (dist[v] == INF) {
                        dist[v] = dist[u] + 1;
                        if (dist[v] > maxDist) {
                            maxDist = dist[v]; vMaxMax.clear();
                            vMaxMax.push_back(v + 1);
                        } else if (dist[v] == maxDist) vMaxMax.push_back(v + 1);
                        q.push(v);
                } } }

            }

            //if (dist[node]%2 == 0) midDist++;




        sort(vMaxMax.begin(), vMaxMax.end());
        cout << "Best Roots  :";
        for (int i = 0; i < vMinMax.size(); i++) {
            cout << " " << vMinMax[i];
        } cout << endl;
        cout << "Worst Roots :";
        for (int i = 0; i < vMaxMax.size(); i++) {
            cout << " " << vMaxMax[i];
        } cout << endl;
    }



}
