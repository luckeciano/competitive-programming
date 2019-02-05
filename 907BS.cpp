#include <iostream>
#define INF 10000000
using namespace std;

int N, K;
int pos[605], walk[605];
bool check (int x) {
    int y = x, camp = 0;
    for (int i = 0; i < N + 1; i++) {
        int dif = pos[i + 1] - pos[i];
        if (y >= dif) y-=dif;
        else {
            camp++;
            y = x - dif;
        }
        if (camp > K || y < 0) return false;
    }
    return true;

}

int main() {
    while (cin >> N >> K) {
        for (int i = 1; i < N + 2; i++)
            cin >> walk[i];

        pos[0] = 0;
        for (int i = 1; i < N + 2; i++)
            pos[i] = walk[i] + pos[i - 1];

        int left = pos[0]; int right = pos[N + 1];

        int dist = INF;
        while (left <= right) {
            int mid = (left + right)/2;
            if (check(mid)) dist = min (dist, mid), right = mid - 1;
            else left = mid + 1;
        }
        cout << dist << endl;
    }

}
