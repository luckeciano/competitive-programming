#include <cstdio>

int main () {
    int t;
    scanf ("%d", &t);
    int bars[25];
    while (t--) {
        int n;
        scanf ("%d", &n);
        int p;
        scanf ("%d", &p);
        for (int i = 0; i < p; i++) {
            scanf ("%d", &bars[i]);
        }
        bool sol = false;
        for (int i = 0; i < (1 << p) && !sol; i++) {
            int sum = 0;
            for (int j = 0; j < p; j++) {
                if (i & (1 << j))
                    sum += bars[j];
            }
            if (sum == n)
                sol = true;
        }
        if (sol) printf ("YES\n");
        else printf ("NO\n");
    }

}
