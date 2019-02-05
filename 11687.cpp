#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string x;
    cin >> x;
    while (x != "END") {
        int cont = 1;
        if (x != "1") {
            int curr = x.size();
            int prev = -1;
            while (curr != prev) {
                prev = curr;
                stringstream ss;
                ss << prev;
                string aux = ss.str();
                curr = aux.size();
                cont ++;
            }
        }
        cout << cont << endl;
        cin >> x;
    }
    return 0;
}
