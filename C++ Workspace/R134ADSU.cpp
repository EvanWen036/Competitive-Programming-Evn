#include <bits/stdc++.h>
#define ll long long;
using namespace std;
int dsu[100];
int ranks[100];
int components;
int find(int u){
	if(dsu[u] == u){
		return u;
	}
	return find(u);
}
void merge(int u, int v){
	u = find(u);
	v = find(v);
	if(ranks[u] < ranks[v]){
		swap(u,v);
	}
	components--;
	dsu[v] = u;
	if(ranks[u] == ranks[v]){
		ranks[u]++;
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	components = n;
	vector<int> x(n);
	vector<int> y(n);
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y [i];
		dsu[i] = i;
		ranks[i] = 0;
	}
	for(int i = 0 ; i < n;i++){
		for(int j = i+1;j  < n; j++){
			if(i == j)continue;
			if((x[i] == x[j] || y[i] == y[j]) && find(i) != find(j))merge(i,j);
		}
	}
	cout << components-1;	

}