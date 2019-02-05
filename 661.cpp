#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int m , n, c;
	cin >> n >> m >> c;
	int count = 0;
	while (!(m == 0 && n == 0 && c ==0)) {
		count++;
		int maxUse = 0;
		vector <pair <int, bool> > devices;
		for (int i = 0; i < n; i++) {
			int aux;
			cin >> aux;
			devices.push_back(std::make_pair(aux, false));
		}
		for (int j = 0; j < m; j++) {
			int dev;
			cin >> dev;
			devices[dev - 1].second = !devices[dev - 1].second;
			int use = 0;
			for (int t = 0; t < devices.size(); t++) {
				if (devices[t].second)
					use += devices[t].first;
			}
			if (use > maxUse)
				maxUse = use;
		}
		cout << "Sequence " << count << endl;
		if (maxUse > c)
			cout << "Fuse was blown." << endl;
		else { 
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << maxUse << " amperes." << endl;
		}
		cin >> n >> m >> c;
		cout << endl;

	}
}
