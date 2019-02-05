#include <iostream>
#include <cstring>
using namespace std;

int memo[205][15][50];
long long W[205];
int N, Q, D, M;
#define MAX_D 20
int checkSet (int w) {
    if (w % D == 0) return 1;
    else return 0;
}

int value(int id, int remB, int w) {
  //cout << "State: " << id << " " << remB << " " << w << endl;
  if (remB == 0) return checkSet(w);
  else if (id == N) return 0;
  if (memo[id][remB][w + MAX_D] != -1) return memo[id][remB][w + MAX_D];
  return memo[id][remB][w + MAX_D] = value(id + 1, remB,  w) + value(id + 1, remB - 1, (w + W[id])%D);
}



int main() {
    int cont = 0;
    while (cin >> N >> Q, N || Q) {

        cont ++;
        for (int i =0; i < N; i++)
            cin >> W[i];
        cout << "SET " << cont << ":" << endl;
        for (int i = 0; i < Q; i++) {
            memset(memo, -1, sizeof memo);
            cin >> D >> M;
            cout << "QUERY " << i + 1 << ": " << value (0,M,0) << endl;
        }


    }



}
