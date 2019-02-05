#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, d;
        cin >> s;
        cin >> d;
        float x = (s + d)/2.0;
        float y = (s - d)/2.0;
        if ( y >= 0 && x == (int)x && y == (int)y )
            cout << (int)x << " " << (int)y << endl;
        else cout << "impossible" << endl;


    }

}
