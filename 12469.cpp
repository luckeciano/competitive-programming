#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	while (a != -1 && b != -1) {
		int number;
		number = abs(a-b);
		if (abs(a-b) > 50)
			number = 100 - abs(a-b);
		cout << number << endl;
		cin >> a >> b;
	}
	return 0;
}