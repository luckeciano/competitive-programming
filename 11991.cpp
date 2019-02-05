#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main () {
    int n, m;
    while (cin >> n >> m) {
        map <int, vector<int> > num;
        for (int i = 0; i < n; i++) {
            int aux; cin >> aux;
            if (num.find(aux) != num.end())
                num[aux].push_back(i+1);
            else {
                vector<int> k;
                k.push_back(i+1);
                num[aux] = k;
            }
        }

        for (int i = 0; i < m; i++) {
            int occ, x;
            cin >> occ >> x;
            if (num.find(x) == num.end()) cout << 0 << endl;
            else if (num[x].size() < occ) cout << 0 << endl;
            else
                cout << num[x][occ - 1] << endl;
        }
    }

}
