#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int L;
    cin >> L;
    while (L != 0) {
        int D = -1;
        int R = -1;
        int minDist = 999999;
        for (int i = 0; i < L; i++) {
            char x;
            cin >> x;
            if (x == 'D')
                D = i;
            else if (x == 'R')
                R = i;
            else if (x == 'Z') {
                minDist = 0;
            }

            if (D != -1 && R != -1) {
                if (abs(D-R) < minDist)
                    minDist = abs(D-R);
            }
        }
        cout << minDist << endl;
        cin >> L;

    }

}
