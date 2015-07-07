#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

//typedef long long int lld;
int arr[1000001];
int main() {

	arr[0] = 0;
	arr[1] = 1;
	for (int i = 1; i < 1000001; i++) {
		arr[i] = 1;
	}
	for (int i = 2; i < 1000001; i++) {
		arr[i]++;
		for (int j = i + i; j < 1000001; j += i) {
			arr[j]++;
		}
	}
	vector<int> prime;
	for (int i = 0; i < 100; i++) {
		if (arr[i] == 2)
			prime.push_back(i);
		if (prime.size() == 10)
			break;
	}
	vector<bool> m(1000, 0);
	for (int i = 0; i < prime.size(); i++) {
		for (int j = 0; j < prime.size(); j++) {
			if (i != j)
				m[prime[i] * prime[j]] = 1;
		}
	}
	int c = 0;
	for (int i = 1; i < 1000001; i++) {
		int x = arr[i];
		if (m[x]) {
			c++;
			if (c % 9 == 0)
				printf("%d\n", i);
		}
	}
}

