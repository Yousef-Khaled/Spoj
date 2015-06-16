    #include <iostream>
    #include <vector>
    #include <fstream>
    #include <map>
    #include <set>
    #include <stdio.h>
    using namespace std;
     
    double Euler(int a) {
    	double x = a;
    	vector<int> v;
    	bool flag;
    	for (int i = 2; i * i <= a; i++) {
    		flag = 0;
    		while (a % i == 0) {
    			a /= i;
    			flag = 1;
    		}
    		if (flag == 1) {
    			v.push_back(i);
    		}
    	}
    	if (a > 1) {
    		v.push_back(a);
    	}
    	if (v.size() == 0) {
    		return 1;
    	}
    	for (int i = 0; i < v.size(); i++) {
    		x *= (1 - 1.0 / v[i]);
    	}
    	return x;
    }
     
    int main() {
     
    	int t;
    	scanf("%d", &t);
    	int n, c;
    	while (t--) {
    		scanf("%d", &n);
    		cout << Euler(n) << endl;
     
    	}
    }
     
