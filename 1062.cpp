#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main () {
    string x;
    cin >> x;
    int cont = 0;
    while (x != "end") {
        cont++;
        vector<stack <char> > stacks;
        for (int i = 0; i < x.size(); i++) {
            bool pushed = false;
            for (int j = 0; j < stacks.size() && !pushed; j++) {
                if (stacks[j].top() >= x[i]) {
                    stacks[j].push(x[i]);
                    pushed = true;
                }

            }
            if (!pushed) {
                stack<char> newOne;
                newOne.push(x[i]);
                stacks.push_back(newOne);
            }


        }

        cout << "Case " << cont << ": " << stacks.size() << endl;


        cin >> x;
    }


}
