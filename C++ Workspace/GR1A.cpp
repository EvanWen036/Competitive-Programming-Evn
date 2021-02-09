#include <bits/stdc++.h>
using namespace std;

int main(){
	int b, k;
	cin >> b >> k;
	bool b1 = (b % 2);
	bool b3 = false;
	for(int i = 0; i < k; i++){
		int a;
		cin >> a;
		if(i == k-1)b1 = true;
		bool b2 = (a % 2);
		if(b1 && b2){
			b3 = !b3;
			//cout << b3;
		}
	}
	cout << (!b3 ? "even":"odd");

}