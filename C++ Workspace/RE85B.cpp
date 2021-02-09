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
		int n, x;
		cin >> n >> x;
		vector<int> A;
		for(int i = 0; i < n;i ++){
			int a;
			cin >> a;
			A.push_back(a);
		}
		sort(A.begin(), A.begin() + n);
		int ind = n;
		double sum = 0;
		
		while(ind > 0 && (A[ind-1] + sum)/(n-ind+1) >= x){
			sum += A[ind-1];
			ind--;
		}
		cout << n-ind << endl;
	}


}