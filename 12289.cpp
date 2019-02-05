#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int cont;
    scanf ("%d", &cont);
    for (int i = 0; i < cont; i++) {
        int one = 0;
        int two = 0;
        string word;
        cin >> word;
        if (word.length() == 5)
            printf ("%d\n",3);
        else {
            if (word[0] == 'o')
                one++;
            if (word[0] == 't')
                two++;
            if (word[1] == 'n')
                one++;
            if (word[1] == 'w')
                two++;
            if (word[2] == 'e')
                one++;
            if (word[2] == 'o')
                two++;

            if (one >= 2) printf("%d\n",1);
            else if (two >= 2) printf ("%d\n",2);
        }
    }

}
