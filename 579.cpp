#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int h, m;
    scanf ("%d:%d", &h,&m);
    while (!(h == 0 && m == 0)) {
        float angle = fabs(30*h - 5.5*m);
        if (angle > 180) angle = 360.000 - angle;
        printf ("%.3f\n", angle);
        scanf ("%d:%d", &h, &m);
    }



}
