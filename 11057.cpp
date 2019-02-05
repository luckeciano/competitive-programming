#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int books [10005];
    int N;
    while (cin >> N) {
        for (int i = 0; i < N; i++) {
            scanf ("%d", &books[i]);
        }
        sort(books, books + N);
        int total;
        scanf ("%d", &total);
        int first, second, finalF, finalS;
        int minSpread = 10000000;
        for (int i = 0; i < N; i++) {
            first = books[i];
            second = *lower_bound(books + i + 1, books + N, total - first);
            if (second + first == total &&  second - first < minSpread) {
                minSpread = second - first;
                finalF = first;
                finalS = second;
            }
        }
        cout << "Peter should buy books whose prices are " << finalF << " and " << finalS << "." << endl;
        scanf ("\n");
        cout << endl;
    }
}
