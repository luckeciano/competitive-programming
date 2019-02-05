#include <iostream>
#include <vector>
#define INF 10000000
using namespace std;
int n, k;
char A, B, C, D;
int yMatrix[35][35], mMatrix[35][35];
int main() {
    while (cin >> n, n) {
        for (int i = 0; i < 30; i++)
            for (int j = 0; j < 30; j++) {
                yMatrix[i][j] = INF;
                mMatrix[i][j] = INF;
            }
        for (int i = 0; i < n; i++) {
            cin >> A >> B >> C >> D >> k;
            if (A == 'Y') {
                yMatrix[C - 'A'][D - 'A'] = k;
                if (B == 'B')
                    yMatrix[D - 'A'][C - 'A'] = k;
            }
            else {
                mMatrix[C - 'A'][D - 'A'] = k;
                if (B == 'B')
                    mMatrix[D - 'A'][C - 'A'] = k;
            }
        }
        for (int i = 0; i < 30; i++) {
            yMatrix[i][i] = 0;
            mMatrix[i][i] = 0;
        }

        for (int k = 0; k < 30; k++) // remember that loop order is k->i->j
            for (int i = 0; i < 30; i++)
                for (int j = 0; j < 30; j++) {
                    yMatrix[i][j] = min(yMatrix[i][j], yMatrix[i][k] + yMatrix[k][j]);
                    mMatrix[i][j] = min(mMatrix[i][j], mMatrix[i][k] + mMatrix[k][j]);
                }
        cin >> A >> B;
        int x = A - 'A'; int y = B - 'A';
        vector<int> minPoint;
        int minDist = INF;
        for (int i = 0; i < 30; i++) {
            if (yMatrix[x][i] + mMatrix[y][i] < minDist) {
                minPoint.clear();
                minDist = yMatrix[x][i] + mMatrix[y][i];
                minPoint.push_back(i) ;
            }
            else if (yMatrix[x][i] + mMatrix[y][i] == minDist)
                minPoint.push_back(i);
        }
        if (minDist == INF) cout << "You will never meet." << endl;
        else {
            cout << minDist;
            for (int i = 0; i < minPoint.size(); i++) {
                cout << " " << (char)(minPoint[i] + 'A');
            }
            cout << endl;
        }

    }


}
