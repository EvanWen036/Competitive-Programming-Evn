#include <bits/stdc++.h>
using namespace std;


int main(){

	int t;
	cin >> t;
	while(t--){
		
		
		int r,g,b;
		cin >> r >> g >> b;
		vector<int> v;
		v.push_back(r);
		v.push_back(g);
		v.push_back(b);
		int best = 0;
		sort(v.begin(), v.end());
		if(v[2] >= v[0]+v[1]){
			best = v[0]+v[1];
		}
		else{
			best = (v[0]+v[1]+v[2])/2;
		}
		cout << best << "\n";
		
		
	}


}