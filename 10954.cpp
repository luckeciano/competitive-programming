#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    while ( N != 0) {
        priority_queue<int> nums;
        for (int i = 0; i < N; i++) {
            int aux;
            cin >> aux;
            nums.push(-aux);
        }
        int cost = 0;
        while (nums.size() != 1) {
            int a = -nums.top();
            nums.pop();
            int b = -nums.top();
            nums.pop();
            cost += a + b;
            nums.push(-a-b);
        }
        cout << cost << endl;
        cin >> N;
    }


}
