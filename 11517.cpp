#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;
#define MAX_C 0

int V, N;

int coinValue [105];

int memoValue[105][10005];
int memoCoin [105][10005];
void res (int id, int value, int nCoins, int &val,int &coins) {
    //cout << "State: " << id << " " << value + MAX_C << " " << nCoins << endl;
    //cout << value + MAX_C << endl;
    if (value == 0) {
        if (val == V) {
            if (nCoins < coins)
                coins = nCoins;
        }
        else {
            val = V;
            coins = nCoins;
        }
        memoValue[id][value + MAX_C] = val;
        memoCoin[id][value + MAX_C] = coins;
        return;
    }
    if (value < 0) {
        if (abs(value) < abs(val - V)){
           val = V + abs(value);
           coins = nCoins;
        }
        else if (abs(value) == abs (val - V) && nCoins < coins) {
            coins = nCoins;
        }
        memoValue[id][value + MAX_C] = val;
        memoCoin[id][value + MAX_C] = coins;
        return;
    }
    if (id == N) {
        return;
    }
    if (!(memoValue[id][value + MAX_C] == -1 && memoValue[id][value + MAX_C] == -1)) {
        if (abs(memoValue[id][value + MAX_C] - V) < abs(val - V)){
            val = memoValue[id][value + MAX_C];
            coins = memoCoin[id][value + MAX_C];
        }
        else if (abs(memoValue[id][value + MAX_C] - V) == abs(val - V) &&  memoCoin[id][value + MAX_C] < coins) {
            val = memoValue[id][value + MAX_C];
            coins = memoCoin[id][value + MAX_C];
        }
        return;
    }

    res(id + 1, value, nCoins, val, coins);
    res(id + 1, value - coinValue[id], nCoins + 1,  val, coins);
    return;

}


int main() {
   // ofstream myf;
    //myf.open ("lulu.txt");
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> V;
        cin >> N;
        for (int i = 0; i < N; i++) {
            scanf ("%d", &coinValue[i]);
            memset(memoValue[i], -1, sizeof memoValue[i]);
            memset(memoCoin[i], -1, sizeof memoCoin[i]);
        }
        int val = 100000, coins = 10000;
        res(0, V, 0, val, coins);
        printf ("%d %d\n", val, coins);
        //myf << val << " " << coins << endl;
    }





}
