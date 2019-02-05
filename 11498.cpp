#include <cstdio>

int main() {
    int K;
    scanf ("%d",&K);
    while (K != 0) {
        int x, y, divisionX, divisionY;
        scanf ("%d %d", &divisionX, &divisionY);
        for (int i = 0; i < K; i++) {
            scanf ("%d %d", &x,&y);
            if (x - divisionX == 0 || y - divisionY == 0)
                printf ("divisa\n");
            else if (x - divisionX > 0) {
                if (y - divisionY > 0)
                    printf ("NE\n");
                else printf ("SE\n");
            }
            else if (x - divisionX < 0) {
                if (y - divisionY > 0)
                    printf ("NO\n");
                else printf ("SO\n");
            }
        }
        scanf ("%d", &K);
    }
    return 0;

}
