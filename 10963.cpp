#include <cstdio>
#include<string>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
   string number;
   cin >> number;
   while (number != "0") {
        int sum = 0;
        bool fim = false;
        while (!fim) {
            sum = 0;
            for (int i = 0; i < number.size(); i++) {
                sum += int(number[i]) - 48;
            }
            if (sum < 10) {
                fim = true;
            }
            number = to_string(sum);
        }
        cout << sum << endl;
        cin >> number;

   }
}
