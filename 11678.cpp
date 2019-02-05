#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    map <int, int> cardsA, cardsB, uniao;
    while (A != 0 && B != 0) {
        for (int i = 0; i < A; i++) {
            int num;
            cin >> num;
            cardsA[num] = 1;
        }
        for (int i = 0; i < B; i++) {
            int num;
            cin >> num;
            if (cardsA.find(num) != cardsA.end()) {
                uniao[num] = 1;
            }
            cardsB[num] = 1;
        }
        int maxTrade = min(abs(cardsA.size() - uniao.size()), abs(cardsB.size() - uniao.size()));
        cout << maxTrade << endl;
        cin >> A >> B;
        cardsA.clear(); cardsB.clear();
        uniao.clear();
    }


}
