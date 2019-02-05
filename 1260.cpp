#include <iostream>
#include <vector>

using namespace std;

int main () {
    int TC;
    cin >> TC;
    while (TC--) {
        int L;
        cin >> L;
        vector<int> prev;
        int cont = 0;
        for (int i = 0; i < L; i++) {
            int x; cin >> x;
            for (int j = 0; j < prev.size(); j++) {
                if (x >= prev[j])
                    cont++;
            }
            prev.push_back(x);

        }
        cout << cont << endl;

    }


}
