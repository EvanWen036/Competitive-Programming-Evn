#include <bits/stdc++.h>
using namespace std;


int main(){

	int T;
	cin >> T;
	while(T--){
		
		int n, m;
		cin >> n;
		cin >> m;
		vector<int> A(n);
		for(int &a : A){
			cin >> a;
		}
		vector<int> P(m);
		for(int i = 0 ;i < m; i++){
			int a;
			cin >> a;
			P[i] = a-1;
		}
		bool sorted = false;
		while(!sorted){
			sorted = true;
			for(int i = 0; i < m; i++){
				if(A[P[i]] > A[P[i]+1]){
					int temp = A[P[i]];
					A[P[i]] = A[P[i]+1];
					A[P[i]+1] = temp;
					sorted = false;
				}
			}
			
		}
		int ma = -1;
		for(int i = 0; i < n; i++){
			if(A[i] < ma)sorted = false;
			ma = max(ma, A[i]);
		}
		cout << (sorted ? "YES":"NO") << "\n";
	
		
	}


}