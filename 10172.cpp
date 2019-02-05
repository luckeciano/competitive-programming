#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool isEmptyQueues (queue <int>  B[], int N) {
    for (int i = 0; i < N; i++) {
        if (!B[i].empty()) return false;
    }

    return true;

}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int N, S, Q;
        scanf ("%d %d %d", &N, &S, &Q);
        queue<int>  B [101];
        stack<int> cargo;
        for (int i = 0; i < N; i++) {
            int cx;
            scanf ("%d", &cx);
            for (int j = 0; j < cx; j++) {
                int aux;
                scanf ("%d", &aux);
                B[i].push(aux);
            }
        }
        int time = -2;
        int turn = -1;
        int it = 0;
        while  (!(isEmptyQueues(B, N) && cargo.empty())) {

            time += 2;
            turn = (turn+1)%N;
            while (!cargo.empty()) {
                if (cargo.top() == turn + 1) {
                    cargo.pop();
                    //cout << "pop!" << endl;
                    time++;
                } else if (B[turn].size() < Q){
                    int m = cargo.top();
                    B[turn].push(m);
                    cargo.pop();
                    time++;
                } else break;
            }
            while (!(B[turn].empty() || cargo.size() == S)) {
                int m = B[turn].front();
                cargo.push(m);
                B[turn].pop();
                time++;
            }
        }
        printf ("%d\n", time);




    }


}
