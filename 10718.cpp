#include <iostream>
#include <cmath>


using namespace std;

int main () {

   unsigned long N, L, U;
   while (cin >> N >> L >> U) {
        unsigned long sum = 0;
        for (int i = 31;  i >= 0; --i) {
            unsigned long x = (N & (1L << i));
           // cout << x << endl;
            if (x) {
                unsigned long temp = x - 1;
                temp |= sum;
                if (temp < L)
                    sum |= x;
            }
            else {
                unsigned long temp = sum;
                temp |= (1L << i);
                if (temp <= U)
                    sum = temp;
            }
        }
        cout << sum << endl;
   }

}
