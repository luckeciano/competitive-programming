#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int cont;
    scanf ("%d", &cont);
    for (int i = 0; i < cont; i++) {
        vector<int> val;
        int a, b, c;
        scanf ("%d %d %d", &a,&b,&c);
        val.push_back(a);
        val.push_back(b);
        val.push_back(c);
        sort(val.begin(), val.end());
        printf ("Case %d: %d\n",i+1, val[1]);

    }
}
