#include <bits/stdc++.h>
using namespace std;


int main(){


	int q;
	cin >> q;
	while(q--){
	
		int a,b,c;
		cin >> a >> b >> c;
		cout << min((a+b+c)/3, min(a,b)) << "\n";
		
	
	}

}