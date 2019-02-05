#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string name[10005];
    int low[10005], high[10005];
    int T;
    scanf ("%d", &T);
    while (T--) {
        int D; scanf ("%d", &D);
        for (int i = 0; i < D; i++){
            string aux; cin >> aux;
            name[i] = aux;
            scanf ("%d %d",&low[i], &high[i]);
        }
        int Q; scanf ("%d", &Q);
        while (Q--) {
            int k; scanf ("%d", &k);
            bool found = false;
            bool undet = false;
            string car = "";
            for (int i = 0; i < D && !undet; i++) {
                if (k >= low[i] && k <= high[i]) {
                    if (!found) {
                        found = true;
                        car = name[i];
                    }
                    else undet = true;
                }
            }
            if (undet || !found) printf ("UNDETERMINED\n");
            else cout << car << endl;
        }
        if (T != 0) cout << endl;
    }

}
