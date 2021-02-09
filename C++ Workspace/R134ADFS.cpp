#include <bits/stdc++.h>
#define ll long long;
using namespace std;

int x[100];
int y[100];
int r = 1;
int rV[100];
int n;
void dfs(int v){
	rV[v] = r;
	for(int i = 0; i < n;i ++){
		if((x[i] == x[v] || y[i] == y[v]) && rV[i] == 0){
			dfs(i);
		}
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i= 0; i <n ;i++){
		cin >> x[i] >> y[i];
	}
	for(int i = 0; i < n;i++){
		if(rV[i] == 0){
			dfs(i);
			r++;
		}
	}
	cout << r - 2;
	
}
