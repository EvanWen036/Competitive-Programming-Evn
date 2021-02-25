#include <bits/stdc++.h>
using namespace std;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	//initialize mi to a number bigger than everything 
	int mi = 100000000;
	int ma = 0;
	//find min in the first half
	for(int i = 0; i < N/2; i++){
		int x;
		cin >> x;
		mi = min(mi, x); 
	}
	//find max in the second half
	for(int i = 0;i  < N/2; i++){
		int x;
		cin >> x;
		ma = max(ma, x);
	}
	cout << mi + ma << '\n';


}
