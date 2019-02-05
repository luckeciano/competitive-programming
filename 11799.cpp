#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int main () {
    int T;
    scanf ("%d\n", &T);
    for (int i = 0; i < T; i++) {
        int velClown = 0;
        string vel;
        getline (cin, vel);
        int val = 0;
        for (int i = 0; i < vel.size(); i++) {
            if (vel[i] != ' ') {
                val = 10*val + vel[i] - 48;
            }
            if (vel[i] == ' ' || i == vel.size() - 1){
                if (val > velClown)
                    velClown = val;
                val = 0;
            }
        }
        cout << "Case " << i + 1 << ": " << velClown << endl;
    }

}
