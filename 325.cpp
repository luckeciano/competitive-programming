#include <iostream>
#include <regex>

using namespace std;

int main() {
    regex r("[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)");
    string expr;
    while (cin >> expr, expr != "*") {
        if (regex_match(expr, r)) {
            cout << expr << " is legal." << endl;
        } else cout << expr << " is illegal." << endl;
    }



}
