#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, d, r;
    int day[10005];
    int night[10005];
    while (scanf ("%d %d %d", &n, &d, &r), n || d || r)  {
        for (int i = 0; i < n; i++) {
            scanf ("%d", &day[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf ("%d", &night[i]);
        }
        sort (day, day + n);
        sort (night, night + n);
        int ot = 0;
        for (int i = 0; i < n; i++) {
            if (day[i] + night[n - i - 1] - d > 0)
                ot += day[i] + night[n - i - 1] - d;
        }
        ot *= r;
        printf ("%d\n", ot);

    }



}
