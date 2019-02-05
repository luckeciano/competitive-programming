#include <iostream>
#include <algorithm>

using namespace std;

bool compare (char a, char b) {
    if (tolower(a) != tolower(b))
        return tolower(a) <= tolower(b);
    else return a < b;
}

int main () {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string x;
        cin >> x;
        sort(x.begin(), x.end(), compare);
        do {
            cout << x << endl;
        } while (next_permutation(x.begin(), x.end(), compare));
    }

}
