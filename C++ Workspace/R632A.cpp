#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		cout << "W";
		for(int i = 0; i < n; i++){
			int j = (i == 0 ? 1 : 0);
			while(j< m){
				cout << "B";
				j++;
			}
			cout << endl;
		}
	
	}
}
	

