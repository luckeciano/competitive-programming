#include <iostream>
#include <cmath>
using namespace std;

int ways (int level) {
    bool isLeaf = true;
    string str; int toIf = 1;
    while (cin >> str, str != "ELSE") {
        if (str == "IF") {
            isLeaf = false;
            toIf *= ways(level + 1);
        }
    }
    int toElse = 1;
    //here, str == ELSE
    isLeaf = true;
    while (cin >> str, str != "END_IF") {
        if (str == "IF") {
            isLeaf = false;
            toElse *= ways (level + 1);
        }
    }
    //if (isLeaf) res++;
    return toIf + toElse;

}

int main() {
    int N; cin >> N;
    while (N--) {
        string str;
        int res = 1;
        while (cin >> str, str != "ENDPROGRAM") {

            if (str == "IF") {
                res *= ways(0);

            }

            if (str == "ELSE") {
                res *= ways(0);
            }
        }
        cout << res << endl;
    }



}
