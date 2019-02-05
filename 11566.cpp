#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

int N, x, T, K;
float V[205];
int W[205];
float memo[205][25][3000];


float value(int id, int w, int nDishes) {
  if (nDishes > 2 * (N + 1)) return -1000000;
  if (int(ceil(0.100 * (w + (N + 1)*T)) + w + (N + 1)*T) > (N + 1)*(x)) return -1000000;
  if (id == 2*K) return 0;
  if (memo[id][nDishes][w] != -1.0) return memo[id][nDishes][w];
  return memo[id][nDishes][w] = max(float(value(id + 1, w, nDishes)), V[id] + value(id + 1, w + W[id],  nDishes + 1));
}

int main() {
    while (cin >> N >> x >> T >> K, N || x || T || K) {
        for (int i = 0; i < 2*K; i++)
            for (int j = 0; j <= 2*(N + 1); j++)
                fill (memo[i][j], memo[i][j] + 3000, -1.0);
        for (int i = 0; i < 2*K; i += 2) {
            cin >> W[i];
            W[i + 1] = W[i];
            V[i] = 0;
            for (int j = 0; j < N + 1; j++) {
                int aux; cin >> aux;
                V[i] += aux;
            }
            V[i] /= 1.000*(N + 1);
            V[i + 1] = V[i];
        }

        cout << fixed << setprecision(2) << value (0, 0, 0) << endl;
    }

}
