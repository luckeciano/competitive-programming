#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

short hamming (short i, short j) {
    short dist = 0;
    short val = i^j;
    while (val) {
        dist++;
        val &= val - 1;
    }

    return dist;

}


int main () {
    int N;
    while (cin >> N) {
        int pot[330000];
        int num = pow(2, N);
        for (int i = 0; i < num; i++) {
            pot[i] = 0;
        }
        int maxP = 0;
        for (int i = 0; i < num; i++) {
            int a;
            cin >> a;
            for (int j = 0; j < num; j++) {
                if (hamming (i, j) == 1) {
                    pot[j] += a;
                }
            }
        }

        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                if (pot[i] + pot[j] > maxP && hamming(i,j) == 1)
                    maxP = pot[i] + pot[j];
            }
        }
        cout << maxP <<  endl;

    }





}
