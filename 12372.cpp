#include <cstdio>

int main() {
    int T;
    scanf ("%d", &T);
    int a, b, c;
    for (int i = 0; i < T; i++) {
        scanf ("%d %d %d", &a, &b, &c);
        if (a <= 20 && b <= 20 && c <= 20)
            printf ("Case %d: good\n", i+1);
        else printf ("Case %d: bad\n", i+1);
    }
}
