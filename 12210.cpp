#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int b, s;
    int bage[10005];
    int sage[10005];
    bool smar[10005];
    int cont = 0;
    while (cin >> b >> s, b || s) {
        cont++;
        for (int i = 0; i < b; i++) {
            cin >> bage[i];
        }
        for (int i = 0; i < s; i++) {
            cin >> sage[i];
            smar[i] = false;
        }
        sort(bage, bage + b);
        sort(sage, sage + s);
        int p = s - 1;
        cout << "Case " << cont << ": ";
        if (b <= s) cout << 0 << endl;
        else cout << b - s << " " << bage[0] << endl;


    }



}
