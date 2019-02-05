#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    int x;
    vector<int> n;
    while ((cin >> x)) {
        n.push_back(x);
        sort(n.begin(), n.end());
        if (n.size()%2 != 0)
            cout << n[n.size()/2] << endl;
        else cout << (n[n.size()/2-1] + n[n.size()/2])/2 << endl;
    }


}
