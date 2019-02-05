#include <iostream>
#include <vector>

using namespace std;

void backtrack (int s, int d, vector<int> months, int i, int  &maxValue, int earnings[]) {
    if (i == 12)
        return;
    int sum = 0;

    for (int k = 0; k < 12; k++) {
        if (months[k] == 0) sum += s;
        else sum -= d;
    }
    for (int k = 0; k < 8; k++) {
        earnings[k] = 0;
        for (int j = k; j < k + 5; j++ ){
            if (months[j] == 0) earnings[k] += s;
            else earnings[k] -= d;
        }
        if (earnings[k] >= 0) return;
    }

    if (sum > maxValue)
        maxValue = sum;

    backtrack (s, d, months, i + 1, maxValue, earnings);
    if (i + 1 < 12) months[i + 1] = 0;
    backtrack (s, d, months, i + 1, maxValue, earnings);



}




int solve (int s, int d, vector<int> months) {
    int maxValue = -9999999;
    int earnings[8];
    backtrack (s, d, months, 0, maxValue, earnings);
    months[0] = 0;
    backtrack (s, d, months, 0, maxValue, earnings);

    return maxValue;
}


int main () {
    int s, d;
    vector<int> months;
    months.resize(12);
    while (cin >> s >> d) {
        for (int i = 0; i < 12; i++) {
            months[i] = 1;
        }
        //0 is s, 1 is d
        int maxV = solve (s, d, months);
        if (maxV >= 0 ) cout << maxV << endl;
        else cout << "Deficit" << endl;
    }



}
