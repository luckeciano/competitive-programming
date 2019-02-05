#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int bags[10005];
    while (N) {
        for (int i = 0; i < N; i++) {
            cin >> bags[i];
        }
        sort(bags, bags + N);

        int maxRep = 1;
        int rep = 1;
        for (int i = 1; i < N; i++) {
            if (bags[i] == bags[i - 1]) {
                rep++;
                if (rep > maxRep)
                    maxRep = rep;
            }
            else rep = 1;
        }
        cout << maxRep << endl;

        for (int i = 0; i < maxRep; i++) {
            bool first = true;
            for (int j = i; j < N; j += maxRep) {
                if (first) first = false;
                else cout << " ";
                cout << bags[j];
            }
            cout << endl;
        }



        cin >> N;
        if (N) cout << endl;
    }



}
