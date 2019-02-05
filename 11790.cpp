#include <iostream>

using namespace std;
#define MAX_N 50000
long long calcW (int P[], long long W[], int N) {
     long long maxW = 0;
    for (int t = 0; t < N; t++){
        int x = t;
        long long w = 0;
        while (true) {
            w += W[x];
            x = P[x];
            if (x == -1) break;
        }
        maxW = max(maxW, w);
    }
    return maxW;


}


long long LIS (long long A[], long long W[], int N) {
    long long temp;
    long long Li[N];
    long long maxW = 0;
    for (int i = 0; i < N; i++) {
        temp = Li[i] = W[i];
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i])
                Li[i] = max(Li[i], temp + Li[j]);
        }
        maxW = max(maxW, Li[i]);
    }
    return maxW;
}

int main() {
    int TC; cin >> TC;
    int cont = 0;
    long long hA [MAX_N];
    long long w [MAX_N];
    long long hB [MAX_N];
    while (TC -- ){
        cont++;
        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> hA[i];
            hB[i] = -hA[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> w[i];
        }
        long long A = LIS(hA, w, N);
        long long B = LIS(hB, w, N);
        if (A >= B)
            cout << "Case " << cont << ". Increasing (" << A << "). Decreasing (" << B << ")." << endl;
        else cout << "Case " << cont << ". Decreasing (" << B << "). Increasing (" << A << ")." << endl;
    }

}
