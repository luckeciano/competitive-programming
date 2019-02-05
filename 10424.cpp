#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {
	string first;
	while (getline(cin, first)) {
		string second;
		getline(cin, second);
		int value = 0, valueSec = 0;
		for (int i = 0; i < first.size(); i++) {
			char actual = first[i];
			if ('a' <= actual && actual <= 'z') {
				value += actual - 'a' + 1;
			} else if ('A' <= actual && actual <= 'Z') {
				value += actual - 'A' + 1;
			}
		}

		while (value >= 10) {
			int newValue = 0;
			while (value/10 > 0) {
				newValue += value%10;
				value /= 10;
			}
			newValue += value%10;
			value = newValue;
		}

		for (int i = 0; i < second.size(); i++) {
			char actual = second[i];
			if ('a' <= actual && actual <= 'z') {
				valueSec += actual - 'a' + 1;
			} else if ('A' <= actual && actual <= 'Z') {
				valueSec += actual - 'A' + 1;
			}
		}

		while (valueSec >= 10) {
			int newValueSec = 0;
			while (valueSec/10 > 0) {
				newValueSec += valueSec%10;
				valueSec /= 10;
			}
			newValueSec += valueSec%10;
			valueSec = newValueSec;
		}
		
		double ratio = (1.0*value)/(1.0*valueSec);
		if (ratio <= 1)
			printf("%.2f %%\n", ratio*100.0);
		else printf("%.2f %%\n", (1/ratio)*100.0);
	}
}