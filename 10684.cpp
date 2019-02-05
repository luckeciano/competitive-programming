#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num [10005];
    int x;
    while (cin >> x, x) {
        for (int i = 0; i < x; i++) {
            cin >> num[i];
        }

        int sum = 0;
        int ans = 0;
        for (int i = 0; i < x; i++) {
            sum += num[i];
            ans = max(ans, sum);
            if (sum < 0) sum = 0;
        }
        if (sum <= 0) cout << "Losing streak." << endl;
        else cout << "The maximum winning streak is " << ans << "." << endl;
    }

}
