#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int x1, x2, y1, y2;
    int TC; cin >> TC;
    while (TC --) {
        cin >> x1 >> y1;
        string aux;
        double total = 0;
        scanf ("\n");
        while (true) {
            getline (cin, aux);
            if (aux.size() == 0) break;
            istringstream ss(aux);
            ss >> x1 >> y1 >> x2 >> y2;
            total += sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))*(1/20.0)*(1/1000.0);
        }
        total *= 2;
        int hours = int(total);
        int minutes = round((total - int(total))*60.000);
        if (minutes == 60) minutes = 0, hours++;
        cout << hours << ":";
        cout << setfill('0') << setw(2) << minutes << endl;
        if (TC) cout << endl;
    }


}
