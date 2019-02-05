#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;
string str;
double expression(int &pt) {
    pt += 1;
    string aux;
    while (str[pt] != ' ') {
        aux += str[pt];
        pt++;
    }
    stringstream ss (aux);
    double p; ss >> p;// p /= pow(10, aux.size());
    aux.clear();
    pt++; double a, b;
    if (str[pt] == '(') { a = expression(pt);
    }
    else {
        bool isNeg = false;
        if (str[pt] == '-') { isNeg = true;
            pt++;
        }
        while (str[pt] != ' ') {
            aux += str[pt];
            pt++;
        }
        stringstream ss2(aux);
        ss2 >> a;
        if (isNeg) a *= -1.00000000;
        pt++;
    }
    aux.clear();
    if (str[pt] == '(') b = expression(pt);
    else {
        bool isNeg = false;
        if (str[pt] == '-') { isNeg = true;
            pt++;
        }
        while (str[pt] != ')') {
            aux += str[pt];
            pt++;
        }
        stringstream ss3 (aux);
        ss3 >> b;
        if (isNeg) b *= -1.00000;
        pt++;
    }
    pt++;
    //cout << p << " " << a << " " << b << endl;
    return p*(a + b) + (1-p)*(a - b);

}


int main() {
    while (getline(cin, str), str != "()") {
        double res = 0;
        if (str[0] == '(') {
            int idx = 0;
            res = expression(idx);
        } else {
            stringstream ss(str);
            ss >> res;
        }
        cout << fixed << setprecision(2) << res << endl;
    }



}
