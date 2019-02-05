#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        printf("%d\n", b^(b>>1));
    }
    return 0;


}
