#include <iostream>
#include <map>

using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        int N;
        cin >> N;
        map<int, int> occ;
        int maxSize = 0;
        int first = 1;
        for (int i = 1; i <= N; i++) {
            int a;
            cin >> a;
            if (occ.find(a) == occ.end()) {
                occ[a] = i;
            } else {
                if (first <= occ[a]) {
                    int sizeNow = i - first ;
                    first = occ[a] +  1;
                    if (sizeNow > maxSize)
                        maxSize = sizeNow;
                }
                occ[a] = i;

            }
        }
        if (N - first + 1 > maxSize)
            maxSize = N - first + 1;
        cout << maxSize << endl;




    }



}
