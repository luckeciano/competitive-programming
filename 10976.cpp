#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main () {
    int k;
    while (cin >> k) {
        double a; int b;
        int nF = k + 1;
        b = k + 1;
        a = (1.00000000000000*k * b)/(1.000000000000*(b - k));
        int cont = 0;
        while (a >= nF && a >= b) {
            if (a == (int) a)
            {
                cont++;
            }
            b++;
            a = (1.000000000000000000*k * b)/(b - k);
        }
        cout << cont << endl;
        nF = k + 1;
        b = k + 1;
        a = (1.0*k * b)/(1.0*(b - k));
         while (a >= nF && a >= b) {
            if (a == (int) a)
            {
               cout << "1/" << k << " = 1/" << (int)a << " + 1/" << b << endl;

            }
            b++;
            a = (1.0*k * b)/(b - k);
        }

    }



}
