#include <stdio.h>

int main() {
    int cont;
    scanf ("%d", &cont);
    for (int i = 0; i < cont; i++) {
        int stores;
        scanf ("%d", &stores);
        int nearest =  1000000000;
        int furthest = -1000000000;
        for (int i = 0; i < stores; i++) {
            int nextStore;
            scanf ("%d", &nextStore);
            if (nextStore < nearest)
                nearest = nextStore;
            if (nextStore > furthest)
                furthest = nextStore;
        }
        printf ("%d\n",2*(furthest - nearest));
    }
}
