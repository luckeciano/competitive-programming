#include <iostream>

using namespace std;

int main() {

	string number;
	int count = 0;
	while (cin >> number && number != "\n") {
		count ++;
		cout << "Case " << count << ":" << endl;
		int cases;
		cin >> cases;
		for (int i = 0; i < cases; i++) {
			int a, b;
			cin >> a >> b;
			if (a > b) {
				int aux;
				aux = b;
				b = a;
				a = aux;
			}
			char digit;
			digit = number[a];
			bool problem = false;
			for (int k = a; k <= b && !problem; k++) {
				if (digit != number[k])
					problem = true;
			}
			if (problem)
				cout << "No" << endl;
			else cout << "Yes" << endl; 
		}
	}
}