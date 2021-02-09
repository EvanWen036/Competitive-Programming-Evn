#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int  t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int clears = 0;
		int plays = 0;
		bool works = true;
		for(int i = 0; i < n; i++){
			int pi, ci;
			cin >> pi >> ci;
			if(pi < plays || ci < clears || (pi-plays) < (ci-clears)){
				works = false;
			}
			plays = pi;
			clears = ci;
		}
		cout << (works ? "YES":"NO");
		cout << endl;
	}


}