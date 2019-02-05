#include<iostream>
#include<queue>

using namespace std;


int main() {
    int N, M;
    cin >> N >> M;
    while (!(N==0 && M==0)) {
        priority_queue<int> jack;
        for (int i = 0; i < N; i++) {
            int aux;
            cin >> aux;
            jack.push(-aux);
        }
        int counter = 0;
        for (int i = 0; i < M; i++) {
            int aux;
            cin >> aux;
            if (-jack.top() ==  aux) {
                counter++;
                jack.pop();
            } else if (-jack.top() < aux) {
                while (!jack.empty() && -jack.top() <= aux) {
                    if (-jack.top() == aux) counter ++;
                    jack.pop();
                }
            }
        }

        cout << counter << endl;
        cin >> N >> M;
    }



}
