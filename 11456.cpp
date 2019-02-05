#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;


void reconstruct_print(int end, long long a[], int p[]) {
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x]) s.push(a[x]);
  printf("[%d", a[x]);
  for (; !s.empty(); s.pop()) printf(", %d", s.top());
  printf("]\n");
}

int LIS(long long A[],int a, int b) {
    int N = 2005;
    int L[N], L_id[N], P[N];

      int lis = 0, lis_end = 0;
      for (int i = a; i <= b ; ++i) {
        int pos = lower_bound(L, L + lis, A[i]) - L;
        if (pos == 0 && A[i] != A[a]) continue;
        L[pos] = A[i];
        L_id[pos] = i;
        P[i] = pos ? L_id[pos - 1] : -1;
        if (pos + 1 > lis) {
          lis = pos + 1;
          lis_end = i;
        }
      }
   // reconstruct_print(lis_end, A, P);
    return lis;
}



int main() {
    int MAX_N = 2005;
    long long A[MAX_N];
    long long B[MAX_N];
    long long x;
    int TC; cin >> TC;
    while (TC --) {
        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> x;
            A[i] = x;
            B[i] = -x;
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
           // cout << LIS(B, i, N-1) << " " << LIS(A, i, N-1) << endl;
            ans = max (ans, LIS(B, i, N-1) + LIS(A, i, N - 1) - 1);
        }

        cout << ans << endl;
    }





}
