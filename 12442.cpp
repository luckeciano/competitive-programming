#include <cstdio>
#include <vector>

using namespace std;


int F, N, a, b;
int graph[50005];
int visited[50005];
int explored [50005];
int elem, maxF;
int cas = 0;
void dfs (int i) {
    visited[i] = 1;
    explored[i] = 1;
    F++;
    if (visited[graph[i]] == 0) {
        dfs(graph[i]);
    }
}

int main () {
    int T; scanf ("%d", &T);
    while (T--) {
        cas++;
        scanf ("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf ("%d %d", &a, &b);
            graph[a - 1] = b - 1;
        }
        maxF = -1;
        for (int i = 0; i < N; i++) {
            explored[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            if (explored[i] == 0) {
                for (int j = 0; j < N; j++)
                    visited[j] = 0;
                F = 0;
                dfs(i);

                if (maxF < F) {
                    maxF = F;
                    elem = i + 1;
                }
            }
        }

        printf ("Case %d: %d\n", cas, elem);
    }




}
