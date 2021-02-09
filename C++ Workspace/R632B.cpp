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
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		vector <int> b(n);
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		bool neg = false;
		bool pos = false;
		bool done = false;
		for(int i = 0; i < n; i++){
			if(a[i] > b[i]){
				if(!neg){
					cout << "NO\n";
					done = true;
					break;
				}
			}
			if(a[i] < b[i]){
				if(!pos){
					cout << "NO\n";
					done = true;
					break;
				}
			}
			if(a[i] == 1)pos =true;
			if(a[i] == -1)neg = true;
		}
		if(!done){
			cout << "YES" << endl;
		}
	}
	


}