#include <stdio.h>
#include <math.h>

int main() {
    int cont;
    scanf ("%d", &cont);
    for (int i = 0; i < cont; i++) {
        int a, b;
        scanf ("%d %d", &a, &b);
        printf ("%d\n", (a/3)*(b/3) );
    }
    return 0;


}
