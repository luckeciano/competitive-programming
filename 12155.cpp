#include <iostream>
#include <cmath>
using namespace std;
char get (int n, int x, int y) {
    x %= 2*n - 1;
    y %= 2*n - 1;
    int dx = abs (n - 1 - x);
    int dy = abs (n - 1 - y);

    if (dx + dy >= n) return '.';

    return (dx + dy)%26 + 'a';

}


int main() {
    int cont  =0 ;
    int N, x1, y1, x2, y2;
    while (cin >> N >> x1 >> y1 >> x2 >> y2, N) {
        cont++;
        cout << "Case " << cont << ":" << endl;

        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                cout << get(N, i, j);
            }
            cout << endl;
        }
    }
}
