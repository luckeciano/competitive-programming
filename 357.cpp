#include <iostream>
#include <cstring>

using namespace std;


int N = 5, coinValue[5] = {1, 5, 10, 25, 50};
long long memo[6][30005];

long long ways(int type, int value) {
  if (value == 0)              return 1;
  if (value < 0 || type == N)  return 0;
  if (memo[type][value] != -1) return memo[type][value];
  return memo[type][value] = ways(type + 1, value) + ways(type, value - coinValue[type]);
}


int main() {
    memset(memo, -1, sizeof memo); // we only need to initialize this once
    int x;
    while (cin >> x) {
        long long way = ways(0, x);
        if (way > 1)
            cout << "There are " << ways (0, x) << " ways to produce " << x << " cents change." << endl;
        else cout << "There is only 1 way to produce " << x << " cents change." << endl;
    }

}
