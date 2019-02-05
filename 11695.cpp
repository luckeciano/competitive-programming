#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define INF 100000000
using namespace std;
int N;
vector<vector<int> > AdjList;
pair <int, int> edge;
int newPath (int a, int b) {

    int nodeA = a; int nodeB = a;
        int maxDist = 0; int node = a;
        vector<int> distA(N, INF); distA[a] = 0; // distance from source s to s is 0
        queue<int> q; q.push(a);
        //vector<int> p; // addition: the predecessor/parent vector
        while (!q.empty()) {
        int u = q.front(); q.pop();
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (v == b) continue;
                if (distA[v] == INF) {
                    distA[v] = distA[u] + 1;
                    if (distA[v] > maxDist) {
                        maxDist = distA[v];
                        nodeA = v;
                    }
                    q.push(v);
        } } }


        //from nodeA, lets get the diameter
         vector<int> distB(N, INF);
            distB[nodeA] = 0;
            maxDist = 0;
            q.push(nodeA);
            while (!q.empty()) {
            int u = q.front(); q.pop();

                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (v == b) continue;
                if (distB[v] == INF) {
                    distB[v] = distB[u] + 1;
                    if (distB[v] > maxDist) {
                        maxDist = distB[v];
                        nodeB = v;
                    }
                    q.push(v);
            } } }

        vector<int> dist(N, INF);
            dist[nodeB] = 0;
            q.push(nodeB);
            while (!q.empty()) {
            int u = q.front(); q.pop();

                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (v == b) continue;
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
            } } }

         int diameterOne = distB[nodeB];
         int midDist = distB[nodeB]/2;
         vector<int> vMinMaxU;
        for (int i = 0; i < N; i++) {
            if (dist[i] == midDist && distB[i] == midDist ||
                dist[i] == midDist && distB[i] == midDist + 1 ||
                dist[i] == midDist + 1 && distB[i] == midDist)
                vMinMaxU.push_back(i);
        }
        nodeA = b; nodeB = b;
        maxDist = 0; node = b;
        distA.assign(N, INF); distA[b] = 0; // distance from source s to s is 0
        q; q.push(b);
        //vector<int> p; // addition: the predecessor/parent vector
        while (!q.empty()) {
        int u = q.front(); q.pop();

            for (int j = 0; j < (int)AdjList[u].size(); j++) {
            int v = AdjList[u][j];
            if (v == a) continue;
            if (distA[v] == INF) {
                distA[v] = distA[u] + 1;
                if (distA[v] > maxDist) {
                    maxDist = distA[v];
                    nodeA = v;
                }
                q.push(v);
        } } }

        //from nodeA, lets get the diameter

            distB.assign(N, INF);
            distB[nodeA] = 0;
            maxDist = 0;
            q.push(nodeA);
            while (!q.empty()) {
            int u = q.front(); q.pop();

                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (v == a) continue;
                if (distB[v] == INF) {
                    distB[v] = distB[u] + 1;
                    if (distB[v] > maxDist) {
                        maxDist = distB[v];
                        nodeB = v;
                    }
                    q.push(v);
            } } }

            dist.assign(N, INF);
            dist[nodeB] = 0;
            q.push(nodeB);
            while (!q.empty()) {

            int u = q.front(); q.pop();

                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (v == a) continue;
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
            } } }



         int diameterTwo = distB[nodeB];
         midDist = distB[nodeB]/2;
         vector<int> vMinMaxV;
        for (int i = 0; i < N; i++) {
            if (dist[i] == midDist && distB[i] == midDist ||
                dist[i] == midDist && distB[i] == midDist + 1 ||
                dist[i] == midDist + 1 && distB[i] == midDist)
                vMinMaxV.push_back(i);
        }
        //cout << diameterOne << " " << diameterTwo << endl;
        //cout << endl;
        edge = make_pair(vMinMaxU[0], vMinMaxV[0]);
        return max(int(ceil(diameterOne/2.0) + ceil(diameterTwo/2.0) + 1), max (diameterOne, diameterTwo));

}


int main() {
    int TC; cin >> TC;
    int a, b;
    while (TC-- ){
        cin >> N;
        AdjList.clear();
        AdjList.resize(N);
        for (int i = 0; i < N - 1; i++) {
            cin >> a >> b;
            AdjList[a - 1].push_back(b - 1);
            AdjList[b - 1].push_back(a - 1);
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

        //from nodeA, lets get the diameter

         vector<int> distB(N, INF);
            distB[nodeA] = 0;
            maxDist = 0;
            q.push(nodeA);
            vector<int> p; p.resize(N);
            while (!q.empty()) {
            int u = q.front(); q.pop();
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (distB[v] == INF) {
                    distB[v] = distB[u] + 1;
                    p[v] = u;
                    if (distB[v] > maxDist) {
                        maxDist = distB[v];

                        nodeB = v;
                    }
                    q.push(v);
            } } }

            //from nodeB to nodeA, we have longest path
            int minPath = INF;
            pair<int, int> edgeMin, newEdge;
            int x = nodeB;
            /*while (x != nodeA) {
                cout << x << " ";
                x = p[x];
            }
            cout << nodeA << endl;
            cout << endl;*/
            //x = nodeB;
            while (1) {

                int k = newPath(x, p[x]);
                if (k <= minPath) {
                    minPath = k;
                    edgeMin = make_pair(x, p[x]);
                    newEdge = edge;
                }
                if (x == nodeA) break;
                x = p[x];
            }

            cout << minPath << endl;
            cout << edgeMin.first + 1 << " " << edgeMin.second + 1 << endl;
            cout << newEdge.first + 1 << " " << newEdge.second + 1 << endl;


    }


}
