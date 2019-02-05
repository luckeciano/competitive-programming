#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int pol[25];
    int TC;
    scanf ("%d", &TC);
    while (TC--) {
        int x;
        int cont; scanf ("%d", &cont);
        for (int i = 0; i <= cont; i++) {
            scanf ("%d", &x);
            pol[i] = x;
        }
        int d; scanf ("%d", &d);
        int k; scanf ("%d", &k);
        int m = 0; bool found = false;
        int c = 0;
        while (!found) {
            c++;
            if ((m + c)*d < k)
                m += c;
            else found = true;
        }
        long long result = 0;
        for (int i = 0; i <= cont; i++)
            result += pol[i] * pow(c, i);
        printf ("%lld\n", result);


    }


}
