#include <iostream>
#include <cstring>
using namespace std;

#define INF 10000000

int N, memo[305][305];
int conv[50], inf[50];
int S;

int change(int con, int info) {
    if (con*con + info*info == S*S) return 0;
    if (con*con + info*info - S*S > 0) return INF;

    if (memo[con][info] != -1) return memo[con][info];
    int me = 100000000;
    for (int i = 0; i < N; i++) {
        me = min (me, change(con + conv[i], info + inf[i]));
    }
    return memo[con][info] = 1 + me;

}


int main() {
    int TC;
    cin >> TC;
    while (TC --) {
        memset(memo, -1, sizeof memo);
        cin >> N >> S;
        for (int i =0; i < N; i++) {
            cin >> conv[i] >> inf[i];
        }
        int x = change(0,0);
        if (x >= INF) cout << "not possible" << endl;
        else cout << x << endl;



    }





}
