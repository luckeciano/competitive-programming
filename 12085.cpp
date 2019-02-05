#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
void output (vector <int> subs) {
        stringstream ss;
        ss << subs[0];
        string low = ss.str();
        stringstream ss2;
        ss2 << subs[subs.size() - 1];
        string high = ss2.str();
        int pont = 0;
        cout << "0";
        while (low[pont] == high[pont]) {
            cout << low[pont];
            pont++;
        }
        for (int t = pont; t < low.size(); t++)
            cout << low[t];
        cout << "-";
        for (int t = pont; t < high.size(); t++)
            cout << high[t];
        cout << endl;
}

int main () {
    int N;
    cin >> N;
    int cont = 0;
    while (N!= 0) {
        cont++;
        cout << "Case " << cont << ":" << endl;
        vector<int> subs;
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            if (subs.size() == 0)
                subs.push_back(num);
            else {
                if (subs[subs.size() - 1] == num - 1)
                    subs.push_back(num);
                else if (subs.size() == 1) {
                    cout << "0";
                    cout << subs[0] << endl;
                    subs.clear();
                    subs.push_back(num);
                }
                else {
                    output(subs);
                    subs.clear();
                    subs.push_back(num);
                }
            }

        }
        if (subs.size() == 1) {
            cout << "0";
            cout << subs[0] << endl;
        }
        else if (subs.size() != 0) {
            output(subs);
             subs.clear();
        }
        cout << endl;
        cin >> N;
    }



}
