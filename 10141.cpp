#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int reqs, props;
	cin >> reqs >> props;
	int count = 0;
	while (!(reqs == 0 && props == 0)) {
		count ++;
		if (count > 1) {
			cout << endl;
		}
		string bestProposal;
		double bestPrice = 2000000000;
		int bestCompliance = -1;
		for (int i = 0; i <= reqs; i++) {
			string aux;
			//cin.ignore();
			getline(cin, aux);
		}
		for (int j = 0; j < props; j++) {
			string proposal;
			getline(cin, proposal);
			double price; int compliance;
			cin >> price >> compliance;
			if (compliance > bestCompliance) {
				bestCompliance = compliance;
				bestPrice = price;
				bestProposal = proposal;
			}
			else if (compliance == bestCompliance) {
				if (price < bestPrice) {
					bestCompliance = compliance;
					bestPrice = price;
					bestProposal = proposal;
				}
			}
			for (int k = 0; k <= compliance; k++) {
				string aux;
				getline(cin, aux);
			}				

		}
		cout << "RFP #" << count << endl;
		cout << bestProposal << endl;	
		cin >> reqs >> props;
	}
}