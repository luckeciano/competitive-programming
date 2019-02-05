#include <iostream>
#include <queue>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n, m;
        cin >> n >> m;
        n = 100*n;
        queue<int> carsR;
        queue<int> carsL;
        for (int i = 0; i < m; i++) {
            int l; string side;
            cin >> l >> side;
            if (side == "left")
                carsL.push(l);
            else carsR.push(l);
        }

        int ferrySide = 0; //0 is left
        int turnRiver = 0;
        while (!(carsL.empty() && carsR.empty())) {
            int capacity = 0;
            bool hasCar = false;
            if (ferrySide == 0) {
                while (!carsL.empty() && capacity + carsL.front() <= n) {
                    capacity += carsL.front();
                    carsL.pop();
                    hasCar = true;
                    ferrySide = 1;
                }

                if (hasCar) turnRiver++;
                else {
                    while (!carsR.empty() && capacity + carsR.front() <= n) {

                        capacity += carsR.front();
                        carsR.pop();
                        hasCar = true;
                    }
                    if (hasCar) turnRiver += 2;
                }

            }
            else {

                while (!carsR.empty() && capacity + carsR.front() <= n) {

                    capacity += carsR.front();
                    carsR.pop();
                    hasCar = true;
                    ferrySide = 0;
                }

                if (hasCar) turnRiver++;
                else {
                    while (!carsL.empty() && capacity + carsL.front() <= n) {

                        capacity += carsL.front();
                        carsL.pop();
                        hasCar = true;
                    }

                    if (hasCar) turnRiver += 2;
                }


            }
        }

        cout << turnRiver << endl;



    }


}
