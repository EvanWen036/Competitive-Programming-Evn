#include <bits/stdc++.h>
#define ll long long;
using namespace std;

const int MAXN = 200005;
vector<int> adj[200005];
vector<int> colorsX[200005];
int colors[200005];
queue<int> q;

void merge(int u, int v){
    u = colors[u];
    v = colors[v];
	if(colorsX[v].size() > colorsX[u].size()){
		swap(u,v);
	}
	for(int x : colorsX[v]){
		colors[x] = u;
		colorsX[u].push_back(x);
	}
    for(int x : adj[v]){
        adj[u].push_back(x);
    }
    adj[v].clear();
    if(adj[u].size() > 1)q.push(u);

}
int main(){

	//freopen("fcolor.in", "r", stdin);
	//freopen("fcolor.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int outdeg[n];
	bool added[n];

	for(int i = 0; i < n; i++){
		colors[i] = i;
		colorsX[i].push_back(i);
	}
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
	}
	for(int i = 0; i < n; i ++){
		if(adj[i].size() > 1)q.push(i);
	}
	while(!q.empty()){
		int v = q.front();
		if(adj[v].size() <=1){
			q.pop();
			continue;
		}
		int pref = adj[v].back();
		adj[v].pop_back();
		if(colors[pref] == colors[adj[v].back()])continue;
		merge(pref, adj[v].back());

	}
	int k = 1;
	map<int, int> f;
	for(int i = 0; i < n;i ++){
		if(f[colors[i]] == 0){
			f[colors[i]] = k;
			k++;
		}
		cout << f[colors[i]] << endl;
	}




}
