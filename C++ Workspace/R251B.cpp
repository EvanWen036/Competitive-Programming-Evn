#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){

	int n,x;
	cin >> n >> x;
	vector<ll> C(n);
	for(ll &c : C){
		cin >> c;
	}
	sort(C.begin(), C.end());
	ll sum = 0;
	for(ll i : C){
		sum += i*x;
		if(x != 1)x--;
	}
	cout << sum;

}