#include <iostream>
#include <vector>

using namespace std;

bool can (int k, vector<int> rungs) {
    int actual = 0;
    for (int i = 0; i < rungs.size(); i++) {
        if (rungs[i] - actual > k) return false;
        else if (rungs[i] - actual == k) {
            k--; actual = rungs[i];
        } else actual = rungs[i];
    }
    if (k >= 0) return true;
    else return false;

}


int main () {
    int T;
    cin >> T;
    int caseC = 0;
    int n;
    vector<int> rungs;
    while (T--) {
        caseC++;
        rungs.clear();
        cin >> n;
        int aux;
        int hi = 0;
        int lo = 1;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            if (aux > hi) hi = aux;
            rungs.push_back(aux);
        }
        int mid = hi - 1;
        int best = hi + 1;
        while (hi >= lo){
            mid = (hi + lo)/2;
            if (can(mid, rungs)) {
                best = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }

        cout << "Case " << caseC << ": ";
        cout << best << endl;



    }


}
