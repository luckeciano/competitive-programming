#include <cstdio>

using namespace std;


int main() {
    int TC;
    scanf ("%d", &TC);
    char field [105];
    bool covered[105];
    int cont = 0;
    while (TC--) {
        cont ++;
        int N;
        int sc = 0;
        scanf ("%d", &N);
        scanf ("\n");
        for (int i = 0; i < N; i++) {
            scanf ("%c", &field[i]);
            covered[i] = false;
        }
        for (int i = 1; i < N; i++) {
            if (field[i - 1] == '.' && !covered[i - 1]) {
                sc++;
                covered[i - 1] = true;
                covered[i] = true;
                if (i + 1 <= N)
                    covered [i + 1] = true;
            }
        }
        if (!covered[N - 1] && field[N - 1] == '.') sc++;
        printf ("Case %d: %d\n", cont, sc);

    }

}

