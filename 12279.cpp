#include <cstdio>

int main() {
    int cont;
    scanf ("%d", &cont);
    int i = 0;
    while (cont != 0) {
        i++;
        int total = 0;
        for (int i = 0; i < cont; i++) {
            int num;
            scanf ("%d", &num);
            if (num == 0) total --;
            else total++;
        }
        printf ("Case %d: %d\n", i, total);
        scanf("%d",&cont);
    }

}
