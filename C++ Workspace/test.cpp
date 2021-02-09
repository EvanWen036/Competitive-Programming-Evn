#include <bits/stdc++.h>
using namespace std;

int main(){

	int T;
	cin >> T;
	while(T--){
		
		int N, M;
		cin >> N >> M;
		if(N%M == 0){
			cout<<"YES\n";
		} else{
			cout<<"NO\n";
		}
	}
	return 0;
}