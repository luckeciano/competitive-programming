#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main () {
    int f;
    cin >> f;
    int fr [15];
    int rear [15];
    float drive [105];
    while (f != 0) {
        int r;
        cin >> r;
        for (int i = 0; i < f; i++) {
            scanf ("%d", &fr[i]);
        }
        for (int j = 0; j < r; j++) {
            scanf ("%d", &rear[j]);
        }
        int cont = 0;
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < r; j++) {
                drive[cont] = (1.0*rear[j])/(1.0*fr[i]);
                cont++;
            }
        }
        sort (drive, drive + cont);
        float maxSpreed = 0;
        for (int i = 1; i < cont; i++) {
            if (drive[i]/drive[i - 1] > maxSpreed)
                maxSpreed = drive[i]/drive[i-1];
        }
        printf ("%.2f\n", maxSpreed);
        cin >> f;

    }



}
