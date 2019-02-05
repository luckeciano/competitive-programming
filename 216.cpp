#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    float dist[10][10];
    int cityX[10];
    int cityY[10];
    int N;
    int cont = 0;
    while (cin >> N, N) {
        cont++;
        for (int i = 0; i < N; i++) {
            cin >> cityX[i] >> cityY[i];
        }
        for (int i =0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = 16.0 + sqrt(1.0*(cityX[i] - cityX[j])*(cityX[i] - cityX[j]) + 1.0*(cityY[i] - cityY[j])*(cityY[i] - cityY[j]));
            }
        }
        vector<int> conn;
        vector<int> minPerm;
        float dists = 0;
        float minDist = 1000000000;
        bool noWay;
        for (int i = 0; i < N; i++)
            conn.push_back(i);
        do {

            dists = 0;

            for (int i = 0; i < N - 1; i++)
                dists += dist[conn[i]][conn[i + 1]];
                if (dists < minDist) {
                    minDist = dists;
                    minPerm = conn;
                }


        } while (next_permutation(conn.begin(), conn.end()));

        cout << "**********************************************************" << endl;
        cout << "Network #" << cont << endl;
        for (int i = 0; i < N - 1; i++) {
                cout << "Cable requirement to connect (" << cityX[minPerm[i]] << "," << cityY[minPerm[i]] <<") to (" << cityX[minPerm[i + 1]] << ","
            << cityY[minPerm[i + 1]] << ") is " << fixed << setprecision(2) << dist[minPerm[i]][minPerm[i + 1]] << " feet." << endl;
        }
        cout << "Number of feet of cable required is " << fixed << setprecision(2) << minDist << "." << endl;


    }


}
