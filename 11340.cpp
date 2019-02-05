#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int letters;
        cin >> letters;
        int price [1000] = {0};
        for (int j = 0; j < letters; j++) {
            unsigned char aux; int p;
            cin >> aux >> p;
            price[aux + 256] = p;
        }
        int lines;
        cin >> lines;
        long double value = 0.000;
        scanf ("\n");
        for (int j = 0; j < lines; j++) {
            string auxS;
            getline (cin, auxS);
            for (int k = 0; k < auxS.size(); k++) {
               // cout << int(auxS[k] + 256) << endl;
                value += price[auxS[k] + 256];
            }
        }
        value /= 100.00000;
        printf("%.2Lf$\n", value);



    }


}
