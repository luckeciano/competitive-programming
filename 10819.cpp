#include <iostream>
#include <cstring>


using namespace std;

int V[105], W[105];
int memo[105][10205];
int M, N;

int value(int id, int w) {
  if (id == N && M < 2200 && M > 2000 && M - w > M - 200 && M - w <= 2000) return -1000000;
  if (id == N || w == 0) return 0;
  if (memo[id][w] != -1) return memo[id][w];
  if (W[id] > w)         return memo[id][w] = value(id + 1, w);
  return memo[id][w] = max(value(id + 1, w), V[id] + value(id + 1, w - W[id]));
}



int main() {

    while (cin >> M >> N) {
        memset(memo, -1, sizeof memo);
        for (int i =0; i < N ; i++) {
            cin >> W[i] >> V[i];
        }
        if (M > 1800) M += 200;
        cout << value (0, M) << endl;
    }



}
