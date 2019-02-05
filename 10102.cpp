#include <iostream>
#include <cmath>

using namespace std;

int main () {
    int N;
    char mapa[700][700];
    while (cin >> N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> mapa[i][j];
            }
        }

        int minMaxDist = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (mapa[i][j] == '1') {
                    int minDist = 99999;
                    for (int k = 0; k < N; k++) {
                        for (int l = 0; l < N; l++) {
                            if (mapa[k][l] == '3') {
                                int dist = abs(i - k) + abs(j - l);
                                if (dist  < minDist)
                                    minDist = dist;
                            }
                        }
                    }
                    if (minDist > minMaxDist)
                        minMaxDist = minDist;
                }
            }
        }
        cout << minMaxDist << endl;

    }




}
