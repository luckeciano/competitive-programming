#include <iostream>
#include <set>

using namespace std;

int main () {
    int N;
    cin >> N;
    while (N != 0) {
        multiset<int> bills;
        long long amount = 0;
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            for (int j = 0; j < a; j++){
                int aux;
                cin >> aux;
                bills.insert(aux);
            }
            amount += *bills.rbegin() - *bills.begin();
            bills.erase(bills.begin());
            bills.erase(prev(bills.end()));
        }
        cout << amount << endl;
        cin >> N;
    }




}
