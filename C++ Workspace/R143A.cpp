#include <bits/stdc++.h>
using namespace std;

int main(){

	int N;
	cin >> N;
	int answer = 0;
	for(int i = 0; i < N; i++){
	
		int a,b,c;
		cin >> a >> b >> c;
		bool ans = (a&&b)||(a&&c)||(b&&c);
		answer += ans;
	
	}
	cout << answer;

}