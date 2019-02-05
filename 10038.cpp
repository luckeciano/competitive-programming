#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    while ((cin >> n)) {

        vector<int> numb;
        vector<bool> dif;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            numb.push_back(x);
            dif.push_back(false);
        }
        dif[0] = true;
        for (int i = 0; i < numb.size() - 1; i++) {
            int j = abs(numb[i + 1] - numb[i]);
            //cout << j << " ";
            dif[j] = true;
        }
        //cout << endl;
        bool jolly = true;
        for (int i = 0; i < dif.size(); i++) {
            if (dif[i] == false)
                jolly = false;
        }

        if (jolly) cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
    }


}
