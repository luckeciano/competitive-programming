#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000

using namespace std;

int shortestPath(int L, int U, vector<int> button) {
    vector<int> dist (10000, INF);
    queue<int> q; q.push(L); dist[L] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < button.size(); i++) {
            if (dist[(button[i] + u)%10000] == INF) {
                dist[(button[i] + u)%10000] = dist[u] + 1;
                q.push((button[i] + u)%10000);
            }
        }
    }

    return dist[U];
}
int L, U , R, aux;
int main() {
    vector<int> button;
    int cont = 0;
    while (cin >> L >> U >> R, L || U || R){
        cont++;
        button.clear();
        for (int i = 0; i < R; i++) {
            cin >> aux;
            button.push_back(aux);
        }

        cout << "Case " << cont << ": ";
        int ans = shortestPath(L, U, button);
        if (ans == INF)
            cout << "Permanently Locked" << endl;
        else cout << ans << endl;
    }

}
