#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    scanf ("%d", &t);
    int donation = 0;
    for (int i = 0; i < t; i++) {
        string operation;
        cin >> operation;
        if (operation == "donate")
        {
            int value;
            cin >> value;
            donation += value;
        }
        else printf ("%d\n", donation);
    }
}
