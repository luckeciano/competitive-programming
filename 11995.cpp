#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        bool s = true;
        bool q = true;
        bool pq = true;
        stack<int> st;
        queue<int> qu;
        priority_queue<int> prq;
        for (int i = 0; i < N; i++) {
            int cmd, x;
            cin >> cmd >> x;
            if (cmd == 1) {
                st.push(x);
                qu.push(x);
                prq.push(x);
            }
            else if (cmd == 2) {
                if (st.empty() || st.top() != x)
                    s = false;
                if (!st.empty()) st.pop();
                if (qu.empty() || qu.front() != x)
                    q = false;
                if (!qu.empty()) qu.pop();
                if (prq.empty() || prq.top() != x)
                    pq = false;
                if (!prq.empty()) prq.pop();
            }
        }
        if (s && !q && !pq) cout << "stack" << endl;
        else if (!s && q && !pq) cout << "queue" << endl;
        else if (!s && !q && pq) cout << "priority queue" << endl;
        else if (!s && !q && !pq) cout << "impossible" << endl;
        else cout << "not sure" << endl;
    }




}
