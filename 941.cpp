#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int TC; cin >> TC;
    string str; int N;
    while (TC--) {
        cin >> str;
        cin >> N;
        N %= str.size();
        sort(str.begin(), str.end());
        for (int i = 0; i < N; i++)
        {
            next_permutation(str.begin(), str.end());
        }
        cout << str << endl;


    }

}
