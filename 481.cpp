#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;




void reconstruct_print(int end, long long a[], int p[]) {
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x]) s.push(a[x]);
  printf("%d\n", a[x]);
  for (; !s.empty(); s.pop()) printf("%d\n", s.top());
}


int main() {
    int MAX_N = 100000;
    long long A[MAX_N];
    long long x;
    int N = 0;
    while (cin >> x) {
        A[N] = x;
        N++;
    }
    int L[MAX_N], L_id[MAX_N], P[MAX_N];

      int lis = 0, lis_end = 0;
      for (int i = 0; i < N ; ++i) {
        int pos = lower_bound(L, L + lis, A[i]) - L;
        L[pos] = A[i];
        L_id[pos] = i;
        P[i] = pos ? L_id[pos - 1] : -1;
        if (pos + 1 >= lis) {
          lis = pos + 1;
          lis_end = i;
        }
      }
      cout << lis << endl;
      cout << "-" << endl;
      reconstruct_print(lis_end, A, P);





}
