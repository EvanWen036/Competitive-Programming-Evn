#include <bits/stdc++.h>
#define ll long long;
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	vector<int> A(n);
	for(int &a : A){
		cin >> a;
	}
	int j = 0;
	int currTime = 0;
	int ma = 0;
	for(int i = 0; i < n;i ++){
		while(j < n && currTime + A[j] <= m){
			currTime += A[j];
			j++;
		}
		ma = max(ma, j-i);
		currTime -= A[i];
	}
	cout << ma;
	

}