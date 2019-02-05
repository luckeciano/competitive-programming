#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int main() {
    int cont = 0;
    int a, b; char sig; string res;
    while (scanf ("%d%c%d=", &a, &sig, &b) != EOF) {
        cin >> res;
        if (res == "?") continue;
        stringstream ss(res);
        int result; ss >> result;
        if (sig == '+' && a + b == result) cont++;
        else if (sig == '-' && a - b == result) cont++;
    }
    cout << cont << endl;


}
