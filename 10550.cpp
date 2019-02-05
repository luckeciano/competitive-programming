#include <stdio.h>

int main()
{
    int a, b, c, d;

    while (true) {
        scanf ("%d %d %d %d", &a, &b,&c, &d);
        if (a == 0 && b ==0 && c ==0 && d==0)
            break;
        else {
            int answer = 1080;
            if (a - b > 0)
                answer += (a-b)*9;
            else answer += (a - b + 40)*9;
            if (c - b > 0)
                answer += (c-b)*9;
            else answer += (c - b + 40)*9;
            if (c - d > 0)
                answer += (c-d)*9;
            else    answer += (c - d + 40)*9;

            printf ("%d\n", answer);
        }


    }
}
