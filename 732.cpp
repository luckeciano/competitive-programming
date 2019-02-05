#include <iostream>
#include <vector>
#include <stack>

using namespace std;


void backtrack (vector<string> &an, int i,int o,string src,string  tag,string  mens,stack<char> stk) {
   // cout << i << " " << o << " " << mens << " " << stk.size() << endl;
    if (i == src.size() && o == tag.size() && stk.empty()) {
        an.push_back(mens);
        //cout << "uhu> " << mens << endl;
    }
    else {

        if (i < src.size()) {
            stk.push(src[i]);
            mens.push_back('i');
            i++;
            backtrack(an, i, o, src, tag, mens, stk);
            i--;
            mens.erase(mens.end() - 1);
            stk.pop();
        }

        if (o < src.size()) {
            if (stk.empty());
            else if (stk.top() != tag[o]);
            else {
                stk.pop();
                mens.push_back('o');
                o++;
                backtrack(an, i, o, src, tag, mens, stk);
                o--;
                mens.erase(mens.end() - 1);
                stk.push(tag[o]);
            }
        }
    }


    return;

}

int main () {
    string src;
    while (getline(cin, src)) {
        string tag;
        getline (cin, tag);
        vector<string> an;
        int i = 0;
        int o = 0;
        string mens = "";
        stack<char> stk;
        backtrack (an, i, o, src, tag, mens, stk);
        cout << "[" << endl;
        for (int i = 0; i < an.size(); i++) {
            for (int j = 0; j < an[i].size(); j++) {
                cout << an[i][j];
                if (j != an[i].size() - 1) cout << " ";
            }
            cout << endl;
        }
        cout << "]" << endl;
    }



}
