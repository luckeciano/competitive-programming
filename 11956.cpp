#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int arr[100] = {0};
        int pointer = 0;
        char commands [100001];
        cin >> commands;
        for (int cont = 0; commands[cont]; cont++) {
            if (commands[cont] == '.');
            else if (commands[cont] == '>')
                pointer = (pointer+1)%100;
            else if (commands[cont] == '<') {
                if (pointer == 0)
                    pointer = 99;
                else pointer--;
            }
            else if (commands[cont] == '+')
                arr[pointer] = (arr[pointer]+1)%256;
            else if (commands[cont] == '-') {
                if (arr[pointer] == 0)
                    arr[pointer] = 255;
                else arr[pointer]--;
            }
        }
        cout << "Case " << i + 1 << ":";
        for (int x = 0; x < 100; x++) {
            printf (" %02X", arr[x]);
        }
        printf ("\n");



    }


}
