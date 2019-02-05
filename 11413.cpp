#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int maxCapacity, vector<int> c, int m) {
    int counter = 1;
    int bottle = 0;
    for (int i = 0; i < c.size(); i++) {
        if (c[i] > maxCapacity) return false;
        else if (bottle + c[i] > maxCapacity) {
            counter++;
            bottle = c[i];
        } else bottle += c[i];
    }
    if (counter <= m) return true;
    else return false;

}


int main() {
    int n, m;
    vector<int> c;
    while (cin >> n >> m) {
        c.clear();
        int aux;
        int hi = 0;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            hi += aux;
            c.push_back(aux);
        }

        int lo = 1;
        int mid = hi;
        int best = hi + 1;
        while (hi >= lo) {
            mid = (hi+lo)/2;
            if (check(mid, c, m)) {
                hi = mid - 1;
                best = mid;
            }
            else lo = mid + 1;
        }
        cout << best << endl;
    }



}
