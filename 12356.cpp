#include <cstdio>

int main () {
    int S, B;
    scanf ("%d %d", &S, &B);
    int sL [100005];
    int sR [100005];
    while (!(B == 0 && S == 0)) {
        for (int i = 1; i <= S; i++) {
            sL[i] = i - 1;
            sR[i] = i + 1;
        }
        sR[S] = -1;
        sL[1] = -1;
        for (int i = 0; i < B; i++) {
            int L, R;
            scanf("%d %d", &L, &R);
            if (sR[R] != -1)
                sL[sR[R]] = sL[L];
            if (sL[L] != -1)
                printf ("%d", sL[L]);
            else printf ("*");

            printf (" ");
            if (sL[L] != -1)
                sR[sL[L]] = sR[R];
            if (sR[R] != -1)
                printf ("%d", sR[R]);
            else printf ("*");

            printf ("\n");

        }

        printf ("-\n");
        scanf ("%d %d", &S, &B);


    }


}
