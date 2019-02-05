#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

float f (int p, int q, int r, int s, int t, int u, float x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;

}

int main() {
    int p, q, r, s, t, u;
    double eps = 1e-15;
    while (cin >> p >> q >> r >> s >> t >> u) {
        double high = 1.0000000000000000000000000;
        double low = 0.00000100000000000000000000;
        double mid = high;
        while (fabs(high - low) > eps) {
            mid = (high + low)/2;
            if (f(p, q, r, s, t, u, mid) > 0) low = mid;
            else high = mid;
        }
        if (fabs(f(p,q,r,s,t,u,mid)) > 0.001) cout << "No solution" << endl;
        else cout << fixed << setprecision(4) << mid << endl;


    }


}
