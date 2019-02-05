#include <iostream>

using namespace std;

int main () {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int calls;
		int totalMile = 0;
		int totalJuice  = 0;
		cin >> calls;
		for (int j = 0; j < calls; j++) {
			int call;
			cin >> call;
			totalMile += ((call/30) + 1)*10;
			totalJuice += ((call/60) + 1)*15;
		}
		cout << "Case " << i + 1 << ": ";
		if (totalJuice < totalMile)
			cout << "Juice " << totalJuice << endl;
		else if (totalJuice == totalMile)
			cout << "Mile Juice " << totalJuice << endl;
		else if (totalJuice > totalMile)
			cout << "Mile " << totalMile << endl;
	}
	return 0;
}