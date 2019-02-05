#include <cstdio>
#include <cmath>
#include <cstdlib>

int main() {
    int lulu;
    scanf ("%d", &lulu);
    for (int i = 0; i < lulu; i++) {
        int n,res;
        scanf ("%d", &n);
        res =  (((((((n*567)/9)+7492)*235)/47)-498));
        res = int(res%100)/10;
        printf ("%d\n",abs(res));
    }

}
