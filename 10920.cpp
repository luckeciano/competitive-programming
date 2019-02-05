#include <iostream>
#include <cmath>

using namespace std;
int findCount (int P, int &x) {
    int i = 1;

    while (true) {
        int num = i*i;
        if (P < num) {
            i -= 2;
            x--;
            break;
        }
        else {
            i += 2;
            x++;
        }
    }
    return i;

}


int main () {
    int SZ, P;
    cin >> SZ >> P;
    while (!(SZ == 0 && P == 0)) {
        int x = (SZ/2) + 1;
        int y = x;
        int dir;
        int timesTotal;
        int times;
        int cont = findCount (P, x);
        y = x;
        cont *= cont;
        //cout << "this: " << cont << " " << x << endl;
        for (int i = cont; i < P; i++) {

            //cout << x << "~" << y << endl;
            if (x == y && sqrt(i) == (int)sqrt(i) && int(sqrt(i))%2 != 0) {

                y++;
                dir = 0; //left
                timesTotal = sqrt(i) + 1;
                //cout << "cu " << timesTotal << endl;
                times = sqrt(i);
            }
            else {
                if (dir == 0) {
                    x--;
                    times--;
                    if (times == 0) {
                        dir = 1;
                        times = timesTotal;
                    }
                } else if (dir == 1) {
                    y--;
                    times--;
                    if (times == 0) {
                        dir = 2;
                        times = timesTotal;
                    }
                } else if (dir == 2) {
                    x++;
                    times--;
                    if (times == 0) {
                        dir = 3;
                        times = timesTotal;
                    }
                } else if (dir == 3) {
                    y++;
                    times--;
                    if (times == 0) {
                        dir = 3;
                        times = timesTotal;
                    }
                }
            }




        }
        cout << "Line = " << y  << ", column = " << x << "." << endl;
        cin >> SZ >> P;

    }


}
