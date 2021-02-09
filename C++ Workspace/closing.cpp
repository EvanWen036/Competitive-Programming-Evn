#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dsu[200005];
int sz[200005];
int components;
int find(int u){
    if(dsu[u] == u)return u;
    return dsu[u] = find(dsu[u]);
}
void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)return;
    if(sz[v] > sz[u])swap(u,v);
    //u is the bigger one
    components--;
    dsu[v] = u;
    sz[u] += sz[v];
}
int main(){

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> adj[N];
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> order(N);
    for(int i =0; i < N; i++){
        dsu[i] = i;
        sz[i] = 1;
        cin >> order[i];
        order[i]--;
    }
    //cout << " HI " << endl;
    components = N;
    set<int> visited;
    vector<int> answers(N);
    for(int i = N-1; i >= 0; i--){
        int curr = order[i];
        visited.insert(curr);
        for(int i : adj[curr]){
            if(visited.count(i) > 0){
                //merge
                merge(curr, i);
            }
        }
        if(components == i+1){
            answers[i] = 1;
        }
        else{
            answers[i] = 0;
        }
    }
    for(int i = 0;i < N; i++){
        cout << (answers[i] == 1 ? "YES":"NO") << endl;
    }


}

