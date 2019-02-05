#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int f;
        cin >> f;
        int sum = 0;
        for (int i = 0; i < f; i++) {
            int a, b ,c;
            cin >> a >> b >> c;
            sum += a*c;
        }
        cout << sum << endl;
    }
}
