#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char piece;
        cin >> piece;
        int r, c;
        cin >> r >> c;
        if (piece == 'r')
            cout << min(r,c) << endl;
        else if (piece == 'k') {
            if (r*c%2 == 0)
                cout << (r*c)/2 << endl;
            else return (r*c)/2 + 1;
        } else if (piece == 'Q') {
            cout << min(r,c) << endl;
        } else if (piece == 'K') {
            if (r%2 != 0)
                r = r+1;
            if (c%2 != 0)
                c = c+1;
            cout << (r*c)/4 << endl;
        }
    }




}
