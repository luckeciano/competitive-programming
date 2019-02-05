#include <iostream>

using namespace std;

int main() {
   int L;

   cin >> L;
   while ( L != 0) {
        string curr, next;
        curr = "+x";

        for (int i = 0; i < L - 1; i++) {
            cin >> next;
            if (next != "No") {
                if (curr[1] == 'x') {
                    if (curr [0] == '+')
                        curr = next;
                    else if (curr[0] == '-') {
                        curr[1] = next[1];
                        if (next [0] == '+')
                            curr[0] = '-';
                        else curr[0] = '+';
                    }
                }
                else {
                    if (curr == next) curr = "-x";
                    else if (curr[1] == next[1] && curr[0] != next[0]) curr = "+x";
                }
            }
        }

        cout << curr << endl;
        cin >> L;
   }


}
