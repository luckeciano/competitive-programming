#include <iostream>

using namespace std;

int main() {
	int cases;
	cin >> cases;
	cout << "Lumberjacks:" << endl;
	for (int i = 0; i < cases; i++) {
		int actual;
		int previous;
		bool ordered = true;
		bool orderedToMin, orderedToMax;
		cin >> previous;
		cin >> actual;
		if (actual < previous) {
			orderedToMax = false;
			orderedToMin = true;
		}
		else if (actual > previous) {
			orderedToMin = false;
			orderedToMax = true;
		}
		for (int j = 0; j < 8; j++) {
			previous = actual;
			cin >> actual;
			if ((actual < previous && orderedToMax) || (actual > previous && orderedToMin))
				ordered = false;
		}
		if (ordered) cout << "Ordered" << endl;
		else cout << "Unordered" << endl;

	}
	return 0;
}