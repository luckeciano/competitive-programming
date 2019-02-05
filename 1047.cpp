#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {

    int n, m;
    int towers[25];
    map<int,int> unions;
    scanf ("%d %d", &n, &m);
    int caseN = 0;
    while (!(n == 0 && m ==0)){
        unions.clear();
        caseN++;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &towers[i]);
        }
        int k; scanf ("%d", &k);
        for (int i =0 ; i < k; i++) {
            int t;
            scanf ("%d", &t);
            int p = 0;
            for (int j =0; j < t; j++) {
                int aux; scanf ("%d", &aux);
                aux--;
                p |= (1 << aux);
            }
            int value;
            scanf ("%d", &value);
            unions[p] = value;
        }
        int maxArea = -100;
        int locations = - 1;
        for (int i = 0; i  < (1<<n); i++) {
            if (__builtin_popcount(i) == m) {
                int value = 0;
                for (int cont = 0; cont < n; cont++) {
                    if (i & (1 << cont))
                        value += towers[cont];
                }

               // printf ("%d\n", value);
                map<int,int>::iterator it;
                for (it = unions.begin(); it != unions.end(); it++) {
                    int un = __builtin_popcount(i & it->first);
                    if (un >= 2)
                        value -= (un - 1)*(it->second);
                }
                if (value > maxArea) {
                    maxArea = value;
                    locations = i;
                } else if (value == maxArea) {
                    for (int j = 0; j < n; j++) {
                        int a = (i & (1 << j));
                        int b = (locations & (1 << j));
                        if (a != b) {
                            if (a > 0) {
                                maxArea = value;
                                locations = i;
                            }
                            break;
                        }
                    }
                }
            }
        }

        printf ("Case Number  %d\n", caseN);
        printf ("Number of Customers: %d\n", maxArea);
        printf ("Locations recommended:");
        for (int i = 0; i < n; i++) {
            if (locations & (1 << i))
                printf (" %d", i+1);
        }
        printf ("\n");
        scanf ("%d %d", &n, &m);
        printf("\n");

    }



}
