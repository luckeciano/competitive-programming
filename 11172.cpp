#include <stdio.h>

int main() {
    int cont;
    scanf ("%d", &cont);
    for (int i = 0; i < cont; i++) {
        int a , b;
        scanf ("%d %d", &a, &b);
        if (a > b)
            printf (">\n");
        else if (a < b)
            printf ("<\n");
        else printf ("=\n");
    }

    return 0;

}
