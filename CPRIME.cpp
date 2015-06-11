#include <iostream>
#include <cmath>
#include <map>
#include <stdio.h>
#include <vector>
#include <iomanip>
using namespace std;

const int max_siz = 100000000;
bool arr[max_siz + 1];
int count[max_siz + 1];
int main() {
	int max = 0;
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i * i <= max_siz; i++) {
		if (!arr[i]) {
			for (int j = i * i; j <= max_siz; j += i) {
				arr[j] = 1;
			}
			max++;
		}
		count[i] = max;
	}
	int h = sqrt(max_siz);
	for (int i = h + 1; i <= max_siz; i++) {
		if (!arr[i]) {
			max++;
		}
		count[i] = max;
	}
	long int x;
	while (cin >> x) {
		if (x == 0)
			break;
		double test = x / log(x);
		double h = abs(test - count[x]);
		cout <<setprecision (1) << fixed <<(h / count[x]) * 100 << endl;
	}
}
