#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	int maxCap = 0;
	int curCap = 0;
	for(int i = 0; i < n; i++){
		
		int a, b;
		cin >> a >> b;
		curCap -= a;
		curCap += b;
		maxCap = max(curCap, maxCap);
	}
	cout << maxCap;

}